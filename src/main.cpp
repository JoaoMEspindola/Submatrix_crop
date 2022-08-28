#include "Matriz.hpp"
#include <sstream>

int main(){
    srand (time(NULL));

    int tam, **matriz, arr[4], **matrizResultante;
    char coordenadas[100], escolha;
    stringstream stream;
    string coordenadasTokenizadas;

    cout << "Qual o tamanho da matriz quadrada desejada?" << endl;
    cin >> tam;
    matriz = geraMatriz(tam);
    arquivaMatriz(matriz, tam);

    do{

        cout << "Em quais coordenadas deseja criar uma submatriz? (Escrever no padrão: i,j/i,j)";
        cin >> coordenadas;

        char *token = strtok(coordenadas, "/,");

        for (int i = 0; i < 4; i++){
            stream << token;
            arr[i] = atoi(token);
            token = strtok(NULL, "/,");
        }

        stream >> coordenadasTokenizadas;

        matrizResultante = recortaMatriz (arr);

        hashMatriz(coordenadasTokenizadas, matrizResultante);

        cout << "Deseja criar outra submatriz? Sim(S), Não(N)." << endl;
        cin >> escolha;
        escolha = toupper(escolha);
        
    }while(escolha != 'N');
    return 0;
}