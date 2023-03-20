#include "caminhoguloso.h"

void menu(int **matriz, int N){
    printf("\n=========================\n");
	ImprimeAleatoria(N, matriz);
    Contador(N, matriz);
    ImprimeAleatoria(N, matriz);
}

int** lerArquivo(int *tamanho){
	FILE *file = fopen("pasta/input.data", "r");

	char *result, linha[100];
    int contador = 0;
    int controle = 1;
    int tamMatriz = 0;
    int **matriz;

	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	} else {
		while (!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if (result) {
                if(controle == 1){
                    controle = 0;
                    tamMatriz = primeiraLinha(linha);
                    matriz = (int**)malloc(sizeof(int*)*tamMatriz);
                    for(int i = 0; i < tamMatriz; i++){
                        matriz[i] = (int*)malloc(sizeof(int)*tamMatriz);
                    }
                }else if(strlen(linha) != 1){
                    tokenizar(linha, matriz, contador);
                    contador++;
                }else{
                    if(contador == tamMatriz){
                       menu(matriz, tamMatriz);    
                    }
                    contador = 0;
                }
            }
		}
	}
    if(contador == tamMatriz){
        menu(matriz, tamMatriz);    
    }
	fclose(file);
    *tamanho = tamMatriz;
    return matriz;
}

int primeiraLinha(char *str){
	const char sep[] = " ";
	char *tokens;

	tokens = strtok(str, sep);

	while (tokens != NULL) {
        return atoi(tokens);
    }
}

void tokenizar(char *str, int **matriz, int contadorLinha){
    int contadorColuna = 0;
	const char sep[] = " ";
	char *tokens;

	tokens = strtok(str, sep);

	while (tokens != NULL) {
        matriz[contadorLinha][contadorColuna] = atoi(tokens);
        contadorColuna++;
		tokens = strtok(NULL, sep);
	}
}

void ImprimeAleatoria(int N, int **matriz){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("[%-3d]", matriz[i][j]);
        }
        printf("\n");
    }   
}

void Contador(int N, int **matriz){  
	int i = 0; // i = linha
	int j = 0; // j = coluna

	int auxValuesPerMatrix = 0;

	int valuesPerMatrix[N * N];
	valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
    
    int soma = 0;

    do{
        if(i == N - 1){
            auxValuesPerMatrix++;
            soma += matriz[i][j];
            matriz[i][j] = -1;
			j++;
            valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
        }else if(j == N - 1){
            if(matriz[i + 1][j - 1] >= matriz[i + 1][j]){
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                i++;
                j--;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }else if(matriz[i + 1][j] >= matriz[i + 1][j - 1]){
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                i++;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }else{
                //matriz[i][j] = -1;
                //i++;
                //j--;
            }
        }else if(j == 0 && i < N - 1){
            if(matriz[i + 1][j] >= matriz[i][j + 1] 
            && matriz[i + 1][j] >= matriz[i + 1][j + 1]){
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                i++;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }else if(matriz[i][j + 1] >= matriz[i + 1][j] 
            && matriz[i][j + 1] >= matriz[i + 1][j + 1]){
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                j++;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }else{
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                i++;
                j++;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }
        }else{
            if(matriz[i][j - 1] >= matriz[i + 1][j - 1]
            && matriz[i][j - 1] >= matriz[i + 1][j]
            && matriz[i][j - 1] >= matriz[i + 1][j + 1]
            && matriz[i][j - 1] >= matriz[i][j + 1]){
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                j--;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }else if(matriz[i + 1][j] >= matriz[i + 1][j - 1]
                && matriz[i + 1][j] >= matriz[i][j + 1]
                && matriz[i + 1][j] >= matriz[i + 1][j + 1]
                && matriz[i + 1][j] >= matriz[i][j - 1]){
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                i++;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }else if(matriz[i][j + 1] >= matriz[i + 1][j - 1]
            && matriz[i][j + 1] >= matriz[i + 1][j]
            && matriz[i][j + 1] >= matriz[i + 1][j + 1]
            && matriz[i][j + 1] >= matriz[i][j - 1]){
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                j++;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }else if(matriz[i + 1][j + 1] >= matriz[i][j - 1]
            && matriz[i + 1][j + 1] >= matriz[i + 1][j]
            && matriz[i + 1][j + 1] >= matriz[i + 1][j - 1]
            && matriz[i + 1][j + 1] >= matriz[i][j + 1]){
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                i++;
                j++;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }else{
                auxValuesPerMatrix++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
                i++;
                j--;
                valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
            }
        }
    }while(i < N && j < N);
    printf("\nSoma do caminho percorrido = %d\n", soma);

    printf("Caminho percorrido");    
    for (int i = 0; i <= auxValuesPerMatrix - 1; i++){
        printf(" -> %d", valuesPerMatrix[i]);
    }
    printf("\n\n");

}   