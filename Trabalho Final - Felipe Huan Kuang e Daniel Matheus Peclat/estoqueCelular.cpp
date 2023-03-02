#include "estoqueCelular.h"

using namespace std;

vector <Celular> EstoqueCelular::getEstoqueCelular () 
{
	return estoqueCelular;
}

const vector <Celular> EstoqueCelular::getEstoqueCelular () const 
{
	return estoqueCelular;
}

ostream &operator << (ostream &out, const EstoqueCelular &estoque)
{
	out << "Esses sao os modelos de celular presentes no estoque atual:\n" << endl;
	for (auto celular: estoque.getEstoqueCelular())
	{
		out << celular << endl;
	}
	return out;
}

Celular* EstoqueCelular::operator () (string &codigo)
{
	Celular *modeloEncontrado = new Celular;
	if (codigo.length () != 0)
	{
		for (auto celular: estoqueCelular)
		{
			if (celular.codigoCelular == codigo)
			{
				*modeloEncontrado = celular;
				return modeloEncontrado;
			}
		}
	}
	else
	{
		throw CodigoCelularVazio();
	}
	return NULL;
}

EstoqueCelular &EstoqueCelular::operator += (Celular &celular)
{
	if (estoqueCelular.size() == 0)
	{
		estoqueCelular.push_back (celular);
	}
	else
	{
		for (unsigned int indice = 0; indice < estoqueCelular.size(); indice ++)
		{
			if (estoqueCelular.at (indice).operator > (celular))
			{
				estoqueCelular.insert (estoqueCelular.begin() + indice, 1, celular);
				return *this;
			}
		}
		estoqueCelular.push_back(celular);
	}

	return *this;
}

EstoqueCelular &EstoqueCelular::operator -= (Celular &celular)
{
	if (this -> operator () (celular.codigoCelular) == NULL)
	{
		throw CelularLocalNaoEncontrado();
		return *this;
	}

	for (unsigned int indice = 0; indice < estoqueCelular.size(); indice ++)
	{
		if (estoqueCelular.at (indice).operator == (celular))
		{
			estoqueCelular.erase(estoqueCelular.begin() + indice);
		}
	}
	return *this;    
}
