# Algoritmo Caminho Guloso

## Apresentando o problema

Este problema mexe com o conceito de caminhamento em matrizes de forma gulosa, ou seja, optando por um dado caminho e não mais olhando para trás ou para decisões já tomadas. 

Dessa forma, o mesmo caminha por um conjunto de matrizes fornecidas como entrada, objetivando encontrar o maior valor final segundo um conjunto de regras preestabelecidas, 

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

## Como executar

## Contatos

git add . && git commit -m "Atualizando" && git push
