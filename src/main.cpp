#include "Matriz.hpp"
#include <sstream>

int main(){
    srand (time(NULL));

    int tam, **matriz, arr[4], **matrizResultante;
    char coordenadas[100], escolha;
    stringstream stream;
    string coordenadasTokenizadas;
    unordered_map <string, int**> map;

    cout << "Qual o tamanho da matriz quadrada desejada?" << endl;
    cin >> tam;
    matriz = geraMatriz(tam);
    arquivaMatriz(matriz, tam);

    do{
        stream.str("");
        cout << "Em quais coordenadas deseja criar uma submatriz? (Escrever no padrão: i,j/i,j)";
        cin >> coordenadas;

        char *token = strtok(coordenadas, "/,");

        for (int i = 0; i < 4; i++){
            stream << token;
            arr[i] = atoi(token);
            token = strtok(NULL, "/,");
        }

        coordenadasTokenizadas =  stream.str();

        cout << "COORDENADA TOKENIZAADA : " << coordenadasTokenizadas << endl;

        if (!(verificaMatriz(map, coordenadasTokenizadas))){
            
            if (tam < 15){
                cout << "Matriz principal gerada: " << endl;
                imprimeMatriz(matriz, tam, tam);
            }else{
                cout << "Matriz principal muito grande para imprimir no terminal. Por favor, consulte o arquivo 'matrix.txt'" << endl;
            }
            
            matrizResultante = recortaMatriz (arr);

            map.emplace(coordenadasTokenizadas, matrizResultante);
        }else{
            cout << endl << "Este recorte já foi feito, e o resultado é: " << endl;
            imprimeMatriz(map[coordenadasTokenizadas], (arr[2] - arr[0])+1, (arr[3] - arr[1])+1);
        }


        cout << "Deseja criar outra submatriz? Sim(S), Não(N)." << endl;
        cin >> escolha;
        escolha = toupper(escolha);
        
    }while(escolha != 'N');
    return 0;
}
