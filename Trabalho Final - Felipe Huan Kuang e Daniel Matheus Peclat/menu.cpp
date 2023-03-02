#include "menu.h"
#include <numeric>

using namespace std;


void mainMenu (EstoqueCelular &estoque) 
{
	int opcoes;

	menuOpcoes();
	cin >> opcoes;
	switch (opcoes)
	{
		case 1:
			exibirCatalogo (estoque);
			mainMenu (estoque);
			break;

		case 2:
			incluirCelular (estoque);
			mainMenu( estoque);
			break;
        
		case 3:
			excluirCelular (estoque);
			mainMenu (estoque);
			break;
        
		case 4:
			verificarDefeito (estoque);
			mainMenu (estoque);
			break;

		case 5:
			grauEficiencia (estoque);
			mainMenu (estoque);
			break;
        
		case 0:
			cout << "O programa está sendo encerrado..." << endl;
			terminarVerificacaoEstoqueCelular (estoque);
			Sleep(1500);
			cout << "Programa encerrado."<< endl;
			break;

		default:
			throw OpcaoInvalida();
			mainMenu (estoque);
	}
}




void menuOpcoes() 
{
	cout << "\n~ ~ ~ ~ ~ ~ ~ ~ ~ CONTROLE DE FABRICAÇÃO DE CELULARES ~ ~ ~ ~ ~ ~ ~ ~ ~\n" << endl;
	cout << "Digite o numero com a opcao desejada:\n" << endl;
	cout << "[1] Exibir um catálogo com todos os modelos de celulares já cadastrados" << endl;
	cout << "[2] Incluir um novo modelo na linha de produção." << endl;
	cout << "[3] Excluir um modelo da linha de produção" << endl;
	cout << "[4] Verificar se um objeto está defeituoso" << endl;
	cout << "[5] Exibir o grau de eficiência do detector de defeitos" << endl;
	cout << "[0] Sair do programa" << endl;
}



void exibirCatalogo (EstoqueCelular &estoque) 
{
	cout << estoque;
}



void incluirCelular (EstoqueCelular &estoque) 
{
	Celular novoCelular;

	cin >> novoCelular;
	estoque.operator += (novoCelular);
}



void excluirCelular (EstoqueCelular &estoque) 
{
	Celular *celularRemovido = new Celular;
	string removerCelular;

	cout << "\nDigite o codigo do Celular que deseja apagar. Os modelos disponiveis estao listados abaixo:\n";
	
	for (auto celular: estoque.getEstoqueCelular()) 
	{
		cout << celular.codigoCelular << endl;
	}
    
	cin.ignore();
	getline (cin, removerCelular);
	celularRemovido = estoque.operator() (removerCelular);

	if (celularRemovido == NULL)
	{
		throw CelularLocalNaoEncontrado();
	}
	else
	{
		estoque.operator -= (*celularRemovido);
	}
}



void verificarDefeito (EstoqueCelular &estoque) 
{
	Celular *pecaEncontrada;
	string buscaCodigoCelular, novaString;   

	cout << "\nDigite o codigo do celular desejado. Os modelos disponiveis estao listados abaixo:" << endl;
	cout << "(A verificacao sera feita por um algoritmo externo)\n" << endl;
	
	for (auto celular: estoque.getEstoqueCelular ()) 
	{
		cout << celular.codigoCelular << endl;
	}
    
	cin.ignore();
	getline(cin, buscaCodigoCelular);
	pecaEncontrada = estoque.operator()(buscaCodigoCelular);

	if (pecaEncontrada == NULL) 
	{
		throw CelularLocalNaoEncontrado();
	}
	else 
	{
		novaString = accumulate(begin(pecaEncontrada -> descricaoCelular), end(pecaEncontrada -> descricaoCelular), novaString);
		
		Py_Initialize();
		PyObject* pythonFilename = PyUnicode_FromString ((char*)"script1");
		PyObject* pythonImportModule = PyImport_Import (pythonFilename);
	
		if (pythonImportModule)
		{
			PyObject* pythonFunction = PyObject_GetAttrString (pythonImportModule, "celularClassificador");
			PyObject* pythonArgs = PyTuple_New (1);
			const char * cppToPythonArg = novaString.c_str ();
			PyObject* pythonPecaDescricao = PyUnicode_FromString (cppToPythonArg);
			PyTuple_SetItem (pythonArgs, 0, pythonPecaDescricao);
			PyObject* pythonFuncValue = PyObject_CallObject (pythonFunction, pythonArgs);
		}
		else
		{
			printf ("Module Error\n");
			Py_Finalize();
		}
	}
}


void grauEficiencia (EstoqueCelular &estoqueCelular) 
{
	Py_Initialize();
	FILE* pythonScriptFile = fopen ("script2.py", "r");
    
	if (pythonScriptFile)
	{
		PyRun_SimpleFile (pythonScriptFile, "script2.py");
		fclose (pythonScriptFile);
	}
	Py_Finalize();
}
