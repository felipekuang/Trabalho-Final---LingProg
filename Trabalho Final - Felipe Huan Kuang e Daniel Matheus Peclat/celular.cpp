#include "celular.h"

using namespace std;

ostream &operator << (ostream &out , const Celular &celular)
{
	out << "Modelo: " << celular.modeloCelular << endl;
	out << "Descrição:" << endl;
	for (auto textline : celular.descricaoCelular)
	{
		out << textline << endl;
	}
	out << endl;

	return out; 
}

istream &operator >> (istream &in, Celular &celular)
{
    
	string buffer;

	cout << "Modelo: ";
	in.ignore();
	getline(in, celular.modeloCelular);

	cout << "Descrição do celular (estado/qualidade do produto): <Digite em uma linha \"FIM\" para terminar o processo de escrita>" << endl;
	buffer.clear();
	
	while (buffer != EOBT)
	{
		getline(in, buffer);
		if (buffer != EOBT)
		{
			celular.descricaoCelular.push_back(buffer);
		}
	}
	
	cout << "Código do celular: ";
	getline(in, celular.codigoCelular);

	return in;
}

bool Celular::operator > (const Celular &celular)
{
	return (this -> codigoCelular > celular.codigoCelular);
}

bool Celular::operator < (const Celular &celular)
{
	return (this -> codigoCelular < celular.codigoCelular);
}

bool Celular::operator == (const Celular &celular)
{
	return (this -> codigoCelular == celular.codigoCelular);
}
