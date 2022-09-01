#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_map>
using namespace std;

int** geraMatriz(int tam);
void imprimeMatriz(int **matriz, int linha, int coluna);
void arquivaMatriz(int **matriz, int tam);
int** transpoeMatriz(int **matriz, int linha, int coluna);
int** recortaMatriz(int arr[4]);
int** multiplicaMatrizes(int **matriz, int **matriz2, int linha, int coluna);
bool verificaMatriz(unordered_map<string, int**> map, string key);


#endif
