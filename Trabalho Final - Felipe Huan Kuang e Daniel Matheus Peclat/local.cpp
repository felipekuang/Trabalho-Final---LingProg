#include "local.h"

string limparString (string palavras)
{
	vector <char> delim = { '\n' ,'\r','\t'};
	size_t ocorrencia;

	for (int i = 0; i < (int) delim.size (); i++)
	{
		ocorrencia = palavras.find (delim[i]);

		if (ocorrencia != string::npos)
		{
			palavras.erase (ocorrencia);
		}
	}
	return palavras;
}

Celular verificarCelular (const string &codigoCelular) 
{
	ifstream local;
	Celular celular;
	string buffer;
	int counter = 0;
    
	celular.codigoCelular = codigoCelular;
	local.open (codigoCelular);
	
	if (!local)
	{
		throw CelularLocalNaoEncontrado ();
	}

	if (local.is_open()) 
	{
		while (getline (local, buffer))
		{
			if (buffer != "")
			{
				if (counter == 0)
				{
					buffer = buffer.substr (separadores.at (0).length ());
					celular.modeloCelular = buffer;
					counter++;
				}
				else 
				{
					if (buffer != separadores.at (1)) 
					{
						buffer = limparString (buffer) + ' ';
						celular.descricaoCelular.push_back (buffer);
					}
				}
			}
		}
		celular.descricaoCelular.erase (celular.descricaoCelular.begin ());
	}
	else
	{
		throw CelularLocalErrado ();
	}

	local.close ();
    
	return celular;
}

void verificarCodigoCelular (vector<string> &codigo)
{
	ifstream local;
	string buffer;
    
	codigo.clear ();
	local.open ("codigoCelulares.txt");
	
	if (!local)
	{
		throw CodigoCelularNaoEncontrado ();
	}

	if (local.is_open()) 
	{
		while (getline (local, buffer))
		{
			codigo.push_back (buffer);
		}
	}
	else
	{
		throw CodigoCelularErrado ();
	}

	local.close ();
}

EstoqueCelular verificarEstoqueCelular ()
{
	EstoqueCelular estoque;
	Celular novoCelular;

	verificarCodigoCelular (codigoCelulares);

	for (auto codigoCelular : codigoCelulares)
	{
		novoCelular = verificarCelular (codigoCelular);
		estoque.operator += (novoCelular);
	}
	return estoque;
}

void terminarVerificacaoCelular (const Celular &celular)
{
	ofstream local;

	local.open (celular.codigoCelular);

	if (local.is_open ())
	{
		local << celular << endl;
	}	
	else 
	{
		throw CelularLocalErrado ();
	}
	
	local.close ();
}

void terminarVerificacaoEstoqueCelular (const EstoqueCelular &estoque)
{
	vector <Celular> estoqueCelular;
	ofstream local;
    
	codigoCelulares.clear ();
	estoqueCelular = estoque.getEstoqueCelular ();

	for (auto celular: estoqueCelular)
	{
		terminarVerificacaoCelular (celular);
		codigoCelulares.push_back (celular.codigoCelular);
	}

	local.open ("codigoCelulares.txt");

	for (auto codigoCelular: codigoCelulares)
	{
		local << codigoCelular << endl;
	}
	
	local.close ();
}
