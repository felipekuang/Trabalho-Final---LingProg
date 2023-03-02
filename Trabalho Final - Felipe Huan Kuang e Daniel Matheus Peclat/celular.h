#ifndef CELULAR_H
#define CELULAR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string EOBT = "FIM";

struct Celular
{
	friend class EstoqueCelular;

	friend ostream &operator << (ostream &, const Celular &);

	friend istream &operator >> (istream &, Celular &);

	bool operator > (const Celular &);

	bool operator < (const Celular &);

	bool operator == (const Celular &);

	string codigoCelular;

	string modeloCelular;

	vector <string> descricaoCelular;
};

#endif
