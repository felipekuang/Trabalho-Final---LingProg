/* Universidade Federal do Rio de Janeiro
 * Departamento de Engenharia Eletronica e de Computacao
 * EEL670 - Linguagens de Programacao
 * Trabalho Final de Programacao
 * Professor: Miguel Campista
 * Autores: Felipe Huan Kuang
 *          Daniel Matheus Peclat
 */

#define PY_SSIZE_T_CLEAN
#include "python3.8/Python.h"

#include <pylifecycle.h>
#include <pythonrun.h>
#include <unicodeobject.h>
#include <import.h>
#include <object.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "menu.h"
#include "celular.h"
#include "estoqueCelular.h"
#include "local.h"
#include "excecoes.h"

#define OK  0

using namespace std;

int main()
{   
	EstoqueCelular estoqueCelular;

	try
	{
		estoqueCelular = verificarEstoqueCelular ();
		system("clear");
		mainMenu (estoqueCelular);
	}
    
	catch (CelularLocalNaoEncontrado &error1)
	{
		cout << error1.what () << endl;
	}

	catch (CelularLocalErrado &error2)
	{
		cout << error2.what () << endl;
	}

	catch (CodigoCelularNaoEncontrado &error3)
	{
		cout << error3.what () << endl;
	}

	catch (CodigoCelularErrado &error4)
	{
		cout << error4.what () << endl;
	}

	catch (CodigoCelularVazio &error5)
	{
		cout << error5.what () << endl;
	}
    
	return OK;
}
