# Exercício de aquecimento de AEDS II

[![Linguagem C++](https://img.shields.io/badge/Linguagem-C%2B%2B-green.svg)](https://github.com/PedroLouback/Exercicio3-ListaAEDs)
[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)


<h2> <u>Processamento de matrizes por segmentação de arquivo</u>

---

## Problema

<p align="justify">Neste trabalho, cada aluno deve implementar um sistema de multiplicação de matrizes baseando-se em uma estratégia de segmentação em arquivo. Um arquivo M grande é fornecido no formato NxN com valores de ponto flutuante ou inteiros como entrada. Este é processado a partir de várias coordenadas introduzidas por um segundo arquivo, o coordenadas.txt. Em coordenadas.txt deve ser descrito por linha uma dupla de i e j correspondendo a posição inicial e final a ser lida. Por exemplo, as posições 2,4,6,10 indica que a leitura em M deve iniciar na linha 2 coluna 4 e seguir até a linha 6 coluna 10.</p>

<p align="justify">Feito a leitura da composição de M para um tipo matriz em C, a segunda etapa é produzir a transposta de M -= MT. Feito isso, produza a multiplicação e armazene em uma hash o resultado da multiplicação como valor para a dupla de i's e j's, os quais deverão ser utilizados como chaves da hash. Assim, para cada novo calculo, antes o sistema deve consular a hash para identificar se a multiplicação já foi realizada. Em caso afirmativo, retorne apenas a resposta já calculada. Caso contrário, elabore a multiplicação e armazene o conteúdo em cache. </p>

---

## Lógica

### Introdução
<p align="justify">Dentre as linguagens oferecidas para a resolução do problema (C e C++), para este utilizou-se a linguagem C++, pois facilita a manipulação de arquivos e strings.
No enunciado do exercício pede-se um arquivo de nome <i>coordenadas.txt</i>, porém, para facilitar a inserção de mais dados no programa, é pedido ao usuário o tamanho da matriz a ser armazenada no arquivo, a inserção das coordenadas da submatriz que deseja "cortar" e, ao final do programa, oferece ao usuário a opção de escolher novas coordenadas, melhorando a praticidade do teste do programa.</p>

### Função geraMatriz()
<p align="justify">Função simples para gerar uma matriz quadrada dada um tamanho <b>N</b>, inserido pelo usuário, com números inteiros aleatórios de 0 a 99 utilizando a função <code>rand()</code> da biblioteca <stdlib.h>.</p>

### Função arquivaMatriz()
<p align="justify">Após gerar a matriz na função citada anteriormente, agora é necessário inseri-la em um arquivo <I>.txt</i>, esta função faz exatamente isso, dada uma <b>matriz</b> de tamanho <b>N</b>, será inserido ao arquivo <code>matrix.txt</code> a matriz gerada.</p>

### Função transpoeMatriz()
<p align="justify">Para a realização da multiplicação entre matrizes, é necessário transpor a submatriz anteriormente recortada, logo, esta função irá trocar as linhas e colunas da submatriz, criando assim a submatriz transposta, pedida no enunciado.</p>

### Função multiplicaMatrizes()
<p align="justify">Utilizando a submatriz recortada e a submatriz transposta, esta função ira realizar a multiplicação de seus termos criando assim uma terceira matriz, a <code>matrizResultante</code>, que será armazenada na tabela <i><b>Hash</i></b> proposta no exercício.</p>

### Função verificaMatriz()
<p align="justify">Uma outra funcionalidade que fez com que C++ fosse escolhido foi a biblioteca <code>unordered_map</code>, que, basicamente, implementa uma tabela <i><b>Hash</i></b> dada uma chave escolhida pelo programador. A chave escolhida para este problema foram as coordenadas iniciais e finais fornecidas pelo usuário, tornando aquela <code>matrizResultante</code> única e resolvendo a última parte do exercício. Caso o usuário insira as mesmas coordenadas na entrada, o programa mostrará o resultado ja armazenado naquela chave.</p>

Caso queira consultar mais informações sobre esta biblioteca, clique <a href="https://cplusplus.com/reference/unordered_map/unordered_map/">aqui</a>.

### Função recortaMatriz()
<p align="justify">Dadas as coordenadas iniciais e finais da submatriz, utilizou-se a <i>Tokenização</i> para separar cada ponto criando assim quatro novas variáveis, <b>linhaInicial</b>, <b>linhaFinal</b>, <b>colunaInicial</b> e <b>colunaFinal</b>.</p>

<p align="justify">Para a realização da <i>Tokenização</i>, utilizou-se a função <a href="https://cplusplus.com/reference/cstring/strtok/"><code>strtok()</code></a> que retirará caracteres não numéricos da string e armazenará o resto de duas formas: em um vetor de inteiros, tendo assim que transformar os <i>tokens</i> com a função <code>atoi</code> e também formará a string <b>coordenadasTokenizadas</b> que servirá como <i>key</i> da tabela <i><b>Hash</i></b>.</p>

<p align="justify">Dado o vetor de coordenadas, sendo cada posição uma coordenada, associa-se então, cada posição com uma variável supracitada, segue a imagem como exemplo de explicação:</p>

<img src="imgs/Exemplo vetor.png" width="400px"/>

<p align="justify">Com isso, pode-se obter o tamanho da submatriz a ser recortada fazendo a diferença da coordenada final pela inicial.

<p align="justify">Agora, tem-se as informações necessárias para pesquisar a submatriz dentro do arquivo. O primeiro passo será chegar na linha inicial, para isso utilizou-se a função <code>ignore()</code>, que não armazenará o que ler na linha do arquivo até chegar a um <b>/n</b>, dentro de um loop com a condição de parada a <b>linhaInicial</b>. O segundo passo será chegar na <b>colunaInicial</b>, para tal, o programa armazenará os números anteriores a coluna em uma variável <i>auxLeitura</i>. Após isso, o terceiro passo será ler toda a linha até chegar na <b>colunaFinal</b> em um loop com a condição de parada a <b>linhaFinal</b>.</p>

<p align="justify">Segue um exemplo de explicação, nesta imagem, os vértices vermelhos representam os números <i>ignorados</i>, os verdes os armazenados pela <i>auxLeitura</i> e os azulados a submatriz recortada:</p>

<img src="imgs/Exemplo recortaMatriz.png" width="400px"/>

## Exemplo

### Entrada:

```
7 (tamanho da matriz)
2,2/5,5 (coordenadas)
```

### Matriz gerada

<img src="imgs/matriz limpa.png" width="400px"/>

### Matriz recortada

<img src="imgs/matriz recortada.png" width="400px"/>

### Saída

<img src="imgs/exemplo saida.png" width="500px"/>

---

# Compilação e Execução

<p align="justify">O exercício disponibilizado possui um arquivo Makefile cedido pelo professor que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:</p>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

<p align="justify">É recomendado fazer um <code>make clean</code> antes de um <code>make</code>.</p>
