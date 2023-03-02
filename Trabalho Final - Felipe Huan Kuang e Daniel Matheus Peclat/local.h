#ifndef LOCAL_H
#define LOCAL_H

#include <fstream>
#include <string>
#include <iomanip>
#include "excecoes.h"
#include "estoqueCelular.h"
#include "celular.h"

const vector <string> separadores {"Modelo: ", "Descricao do celular:"};

static vector <string> codigoCelulares;

string limparString (string);

void verificarCodigoCelular (vector <string> &);

Celular verificarCelular (const string &);

EstoqueCelular verificarEstoqueCelular();

void terminarVerificacaoCelular (const Celular &);

void terminarVerificacaoEstoqueCelular (const EstoqueCelular &);

#endif
