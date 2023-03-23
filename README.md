# Algoritmo Caminho Guloso

<p>
<div style="display: inline-block;">

![C](https://img.shields.io/badge/-C-05122A?style=flat&logo=Cplusplus)&nbsp;
![Visual Studio Code](https://img.shields.io/badge/-Visual%20Studio%20Code-05122A?style=flat&logo=visual-studio-code&logoColor=007ACC)&nbsp;

</p>

## Apresentando o problema

Este problema mexe com o conceito de caminhamento em matrizes de forma gulosa, ou seja, optando por um dado caminho e não mais olhando para trás ou para decisões já tomadas. 

Dessa forma, o mesmo caminha por um conjunto de matrizes fornecidas como entrada, objetivando encontrar o maior valor final segundo um conjunto de regras preestabelecidas.

## Regras

1 - Criar um sistema que leia K matrizes quadradas no tamanho NxN.

2 - O programa deve enumerá-las, de forma a deixá-las organizadas para processamento. 

3 - Partindo da primeira matriz, deve iniciar de um ponto preestabelecido, sendo este contido em arquivos extras de configuração. Não é permitido definir diretamente no código. 

4 - A partir da primeira matriz, tem como regras: 
  
  (a) avançar para a próxima coluna; 
  
  (b) retroceder para coluna anterior; 
  
  (c) saltar para a linha de baixo; 
  
  (d) ir em diagonal para baixo. 
  
  ![exemplomatriz](https://user-images.githubusercontent.com/84406892/227231857-df0d0d47-e2e8-4a13-ac89-9f6e3dbd4262.jpeg)
  
  Obs:. Setas verdes indicam que a matriz <strong>PODE</strong> seguir aquele caminho. Setas vermelhas indicam que a matriz <strong>NÃO</strong> pode seguir aquele caminho.
  
  

  Todas essas regras só se aplicam se a casa (posição [i,j] da matriz) ainda não tenha sido descoberta ou já processada. 

5 - Para caminhar, deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra para adotar sempre uma mesma decisão de caminhamento. 

6 - Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado. 

## Sobre o caminho guloso

## Resolução do problema (com imagens)

### Entradas de dados necessárias

No programa existe um diretório nomeado como `pasta`, que dentro contém um documento chamado `input.data`.

Este documento pode ser gerado através do seguinte repositório git, que foi utilizado como referência: [Generate Data To Matrix](https://github.com/mpiress/GenerateDataToMatrix) [^1]

Analogamente, também pode ser digitado manualmente pelo usuário, mas não é o intuito que utilize dessa forma.

Para exemplificar, utilizarei o seguinte arquivo `input.data`, gerado por mim através do repositório citado acima.

### input.data

No exemplo a seguir, estão as informações sobre o tamanho da matriz e quantas matrizes serão analisadas neste programa.

Observe que a primeira linha do arquivo é onde se encontram as entradas NxN da matriz.

Nos blocos subsequentes, a cada cinco linhas, separados por uma linha em branco, encontram-se as matrizes.

Nessa imagem é possível perceber que existem cinco matrizes distintas entre si no total.

![Entrada de dados](https://user-images.githubusercontent.com/84406892/226461030-8900d360-f4db-464f-a305-ec2d873364cb.png)
  
### Saídas obtidas

Ao executar o programa, a seguinte saída é gerada.

Observe que existe um padrão nas impressões. 
Primeiro é impresso a matriz original, corretamente ordenada e dentro de colchetes.

Em seguida é mostrado a soma do caminho que a matriz percorreu durante a execução do programa, e logo abaixo o caminho detalhado por onde passou.

Por fim, uma impressão visual do caminho percorrido dessa matriz.

#### Primeira Matriz percorrida

![matriz1](https://user-images.githubusercontent.com/84406892/227222471-5bc2d926-a49d-48f6-a54a-2d737c105f83.png)

#### Segunda Matriz percorrida

![matriz2](https://user-images.githubusercontent.com/84406892/227222477-9b5676fc-d7d7-491f-a5b1-bdd1f3874534.png)

#### Terceira Matriz percorrida

![matriz3](https://user-images.githubusercontent.com/84406892/227222480-64b2e842-054e-4b0a-acfc-892cdd0583d6.png)

#### Quarta Matriz percorrida

![matriz4](https://user-images.githubusercontent.com/84406892/227222484-4b666d06-5406-49c7-98d7-1a4c449b706d.png)

#### Quinta Matriz percorrida

![matriz5](https://user-images.githubusercontent.com/84406892/227222486-d8e0d622-035a-4be3-bce2-37d8ba149054.png)

### Explicando um pouco sobre o código

O programa em si possui basicamente 6 funções. Todas que irei citar, estão presentes no `caminhoguloso.c`.

- menu( );
> Função localizada na [linha 3](https://github.com/phpdias/caminho-guloso/blob/main/src/caminhoguloso.c#L3). 



> Tem como funcionalidade chamar a função que faz imprimir, e assim, imprimir a matriz original. Em seguida executar a função que faz caminhar pela matriz, e por fim, imprimir a matriz final, que sairá de forma visual para o usuário mostrando o caminho percorrido. 

- lerArquivo( );
> Função localizada na [linha 10](https://github.com/phpdias/caminho-guloso/blob/main/src/caminhoguloso.c#L10). 

> Tem como funcionalidade abrir o arquivo `input.data`, e não sendo possível realizar essa ação, imprimirá uma mensagem indicando tal erro. Do contrário, tendo êxito em abrir o arquivo, essa função irá ler as informações dentro do arquivo. Também é responsável por lidar com a possibilidade do arquivo `input.data` ter espaços em branco no final da última matriz, fazendo com que isso não interfira no resultado desejado.

- primeiraLinha( );
> Função localizada na [linha 53](https://github.com/phpdias/caminho-guloso/blob/main/src/caminhoguloso.c#L53). 

> Tem como funcionalidade tokenizar a primeira linha do arquivo `input.data`. É a função responsável por fazer o programa reconhecer que a primeira linha será a correspondente aos valores de N da matriz NxN.

- tokenizar( );
> Função localizada na [linha 64](https://github.com/phpdias/caminho-guloso/blob/main/src/caminhoguloso.c#L3). 

> Tem como funcionalidade tokenizar. É a função responsável por reconhecer as matrizes e acessar a posição apropriada da matriz.

- ImprimeAleatoria( );
> Função localizada na [linha 78](https://github.com/phpdias/caminho-guloso/blob/main/src/caminhoguloso.c#L78). 

> Tem como funcionalidade imprimir a matriz e também é responsável pela formatação da mesma para a visualização do usuário.

- Contador( );
> Função localizada na [linha 87](https://github.com/phpdias/caminho-guloso/blob/main/src/caminhoguloso.c#L87). 

> Tem como funcionalidade percorrer a matriz. Essa é a função com mais finalidades para o problema. É onde está a lógica do programa para que a matriz seja percorrida corretamente. Também é lá que é feito a soma dos números transitados pelas matrizes, além de ainda ser responsável por imprimir os valores ordenados em que a matriz movimentou.

## Compilação e Execução

Este algoritmo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
|  `make r`              | Realiza o `make clean`, `make` e `make run` juntos                                                |

## Contatos

<div style="display: inline-block;">

<a href="https://t.me/phpdias" target="_blank">
  <img align="center" src="https://img.shields.io/badge/-phpdias-05122A?style=flat&logo=telegram" alt="telegram"/>
</a>
  
<a href="https://linkedin.com/in/phpd" target="_blank">
  <img align="center" src="https://img.shields.io/badge/-phpd-05122A?style=flat&logo=linkedin" alt="linkedin"/>
</a>

<a style="color:black" href="mailto:phpdias@outlook.com?subject=[GitHub]%20O%20Caminho%20Guloso">
 <img align="center" src="https://img.shields.io/badge/-phpdias@outlook.com-05122A?style=flat&logo=email" alt="email"/>
</a>

</div>

## Referências

[^1]: [GitHub](<https://github.com/mpiress/GenerateDataToMatrix>)


