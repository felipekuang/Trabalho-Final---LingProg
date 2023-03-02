#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>

using namespace std;

class CelularLocalErrado: public runtime_error 
{
	public:
		CelularLocalErrado ():
		runtime_error("\nERRO #1: O codigo referente ao celular esta corrompido. Saindo do programa...\n") {};
};

class CelularLocalNaoEncontrado: public runtime_error 
{
	public:
		CelularLocalNaoEncontrado ():
		runtime_error("\nERRO #2: Codigo referente ao celular nao foi encontrado. Saindo do programa...\n") {};
};

class CodigoCelularNaoEncontrado: public runtime_error 
{
	public:
		CodigoCelularNaoEncontrado():
		runtime_error("\nERRO #3: Local que contem os codigos dos celulares nao foi encontrado. Saindo do programa...\n") {};
};

class CodigoCelularVazio: public runtime_error 
{
	public:
		CodigoCelularVazio():
		runtime_error("\nERRO #4: Codigo do celular esta vazio. Saindo do programa...\n") {};
};

class CodigoCelularErrado: public runtime_error 
{
	public:
		CodigoCelularErrado():
		runtime_error("\nERRO #5: Local que contem os codigos dos celulares esta corrompido. Saindo do programa...\n") {};
};

class CelularNaoExiste: public runtime_error 
{
	public:
		CelularNaoExiste():
		runtime_error("\nEste celular nao existe. Exibindo as opcoes do menu novamente.\n") {};
};

class OpcaoInvalida: public runtime_error 
{
	public:
		OpcaoInvalida():
		runtime_error("\nOpcao de menu invalida. Abortando operacao.\n") {};
};

#endif
