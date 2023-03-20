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
  
  Todas essas regras só se aplicam se a casa (posição [i,j] da matriz) ainda não tenha sido descoberta ou já processada. 

5 - Para caminhar, deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra para adotar sempre uma mesma decisão de caminhamento. 

6 - Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado. 

## Sobre o caminho guloso

## Resolução do problema (com imagens)

### Entradas de dados necessárias

No programa existe uma pasta nomeada como `pasta`, que dentro contém um documento chamado `input.data`.

Este documento pode ser gerado através do seguinte repositório git, que foi utilizado como referência: [Generate Data To Matrix](https://github.com/mpiress/GenerateDataToMatrix) [^1]

Analogamente, também pode ser digitado manualmente pelo usuário, mas não é o intuito que utilize dessa forma.

Para exemplificar, utilizarei o seguinte arquivo `input.data`, gerado por mim através do repositório citado acima.

![Entrada de dados](https://user-images.githubusercontent.com/84406892/226461030-8900d360-f4db-464f-a305-ec2d873364cb.png)
  
### Saídas obtidas

## Compilação e Execução

Este algoritmo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
|  `make r`              | Realiza o `make clean`, `make` e `make run` juntos                                                |

## Referências

[^1]: [GitHub](<https://github.com/mpiress/GenerateDataToMatrix>)

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

git add . && git commit -m "Atualizando" && git push
