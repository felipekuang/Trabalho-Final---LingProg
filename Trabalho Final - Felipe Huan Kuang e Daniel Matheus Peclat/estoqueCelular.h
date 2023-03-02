#ifndef ESTOQUECELULAR_H
#define ESTOQUECELULAR_H

#include <iostream>
#include <vector>
#include <string>
#include "celular.h"
#include "excecoes.h"

using namespace std;

class EstoqueCelular 
{
	friend ostream &operator << (ostream &, const EstoqueCelular &);

	public:
        
		EstoqueCelular &operator += (Celular &);

		EstoqueCelular &operator -= (Celular &);

		Celular* operator () (string &);

		vector <Celular> getEstoqueCelular ();

		const vector <Celular> getEstoqueCelular () const;

	private:

		vector <Celular> estoqueCelular;
};

#endif
