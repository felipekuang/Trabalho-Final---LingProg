#ifndef MENU_H
#define MENU_H

#define PY_SSIZE_T_CLEAN
#include "python3.8/Python.h"
#include <pylifecycle.h>
#include <pythonrun.h>
#include <unicodeobject.h>
#include <import.h>
#include <object.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

#include <iostream>
#include <string>
#include <vector>
#include "celular.h"
#include "estoqueCelular.h"
#include "local.h"
#include "excecoes.h"

void menuOpcoes ();

void mainMenu (EstoqueCelular &);

void exibirCatalogo (EstoqueCelular &);

void incluirCelular (EstoqueCelular &);

void excluirCelular (EstoqueCelular &);

void verificarDefeito (EstoqueCelular &);

void grauEficiencia (EstoqueCelular &);

#endif
