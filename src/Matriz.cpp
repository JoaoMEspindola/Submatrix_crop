#include "Matriz.hpp"

int** geraMatriz(int tam){

    int** matriz = new int*[tam];

    for (int i = 0; i < tam; ++i)
        matriz[i] = new int[tam];
    
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            matriz[i][j] = rand() % 100;
        }
    }
    return matriz;
}

void arquivaMatriz(int **matriz, int tam){
    fstream file;

    file.open ("matrix.txt", ios::out);
    if (file.is_open()){
        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++){
                file << matriz[i][j] << "\t";
            }
            file << endl;
        }

    }else{
        cout << "Erro ao abrir o arquivo.";
    }
    file.close();
}

void imprimeMatriz(int **matriz, int linha, int coluna){
    
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

int** recortaMatriz(int arr[4]){

    int linhaInicial, linhaFinal, colunaInicial, colunaFinal;//coordenadas separadas
    int linhaMatrizAux, colunaMatrizAux;//tamanho da matriz auxilar
    int auxLeitura; // variável que lerá os valores das colunas não pertencentes a submatriz

    linhaInicial = arr[0];
    linhaFinal = arr[2];
    colunaInicial = arr[1];
    colunaFinal = arr[3];

    linhaMatrizAux = (linhaFinal - linhaInicial) + 1;
    colunaMatrizAux = (colunaFinal - colunaInicial) + 1;

    int** matrizAux = new int*[linhaMatrizAux];

    for (int i = 0; i < linhaMatrizAux; ++i)
        matrizAux[i] = new int[colunaMatrizAux];

    fstream file;

    file.open("matrix.txt", ios::in);
    if (file.is_open()){
        for (int i = 0; i < linhaInicial; i++) {
            file.ignore(1000000, '\n');
        }
        for (int i = 0; i < linhaMatrizAux; i++) {
            for (int j = 0; j < colunaInicial; j++) {
                file >> auxLeitura;
            }

            for (int j = 0; j < colunaMatrizAux; j++) {
                file >> matrizAux[i][j];
            }
            file.ignore(1000000, '\n');
        }
    }
    file.close();
    cout << endl << "Matriz recortada: " << endl << endl;
    imprimeMatriz(matrizAux, linhaMatrizAux, colunaMatrizAux);
    cout << endl;
    return multiplicaMatrizes(matrizAux, transpoeMatriz(matrizAux, linhaMatrizAux, colunaMatrizAux), linhaMatrizAux, colunaMatrizAux);

}

int** transpoeMatriz(int **matriz, int linha, int coluna){
    
    int** matrizTransposta = new int*[coluna];

    for (int i = 0; i < coluna; ++i)
        matrizTransposta[i] = new int[linha];
    
    for (int i = 0; i < coluna; i++){
        for (int j = 0; j < linha; j++){
            matrizTransposta[i][j] = matriz[j][i];
        }
    }

    cout << endl << "Matriz resultante da transposição: " << endl;

    imprimeMatriz(matrizTransposta, coluna, linha);

    return matrizTransposta;
}

int** multiplicaMatrizes(int **matriz, int **matriz2, int linha, int coluna){

    int** matrizResultante = new int*[linha];

    for (int i = 0; i < linha; ++i)
        matrizResultante[i] = new int[linha];

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < linha; j++) {
            matrizResultante[i][j] = 0;
 
            for (int k = 0; k < coluna; k++) {
                matrizResultante[i][j] += matriz[i][k] * matriz2[k][j];
            }
         }
     }

    cout << endl << "Matriz resultante da multiplicação: " << endl;
    imprimeMatriz(matrizResultante, linha, coluna);

    return matrizResultante;
}

bool verificaMatriz(unordered_map<string, int**> map, string key) {
    auto verifica = map.find(key);

    if (verifica != map.end()) {
        return true;
    }
    
    return false;
}
