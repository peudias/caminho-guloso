#include "contador.h"

void menu(int **matriz, int N){
	//int matriz[N][N];

	//MatrizAleatoria(N, matriz);
    printf("\n=========================\n");
    printf("\nprimeira matriz\n");
	ImprimeAleatoria(N, matriz);
    Contador(N, matriz);
    printf("\nCaminho percorrido:\n");
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
                    //menu(matriz, tamMatriz);
                    if(contador == tamMatriz){
                       menu(matriz, tamMatriz);    
                    }
                    contador = 0;
                }
            }
		}
	}
    //printf("aux = %d\ntamMatriz=%d\n", auxInputLinhaFinal, tamMatriz);
    if(contador == tamMatriz){
        menu(matriz, tamMatriz);    
    }
	fclose(file);
    //ImprimeAleatoria(tamMatriz, matriz);
    *tamanho = tamMatriz;
    return matriz;
}

int primeiraLinha(char *str){
	const char sep[] = " ";
	char *tokens;

	tokens = strtok(str, sep);

	while (tokens != NULL) {
		//printf("%s\n", tokens);
		//tokens = strtok(NULL, sep);
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
		//printf("%s\n", tokens);
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
    //int soma = soma + matriz[0][0];

    //int soma = 0;
	int i = 0; // i = linha
	int j = 0; // j = coluna

	int auxValuesPerMatrix = 0;

	int valuesPerMatrix[N * N];
	valuesPerMatrix[auxValuesPerMatrix] = matriz[i][j];
    
    //int contador = -1;

    do{
        if(i == N - 1){
            matriz[i][j] = -1;
			j++;
        }else if(j == N - 1){
            //matriz[i][j]
            if(matriz[i + 1][j - 1] >= matriz[i + 1][j]){
                matriz[i][j] = -1;
                i++;
                j--;
            }else if(matriz[i + 1][j] >= matriz[i + 1][j - 1]){
                matriz[i][j] = -1;
                i++;
            }else{
                //matriz[i][j] = -1;
                //i++;
                //j--;
            }
        }else if(j == 0 && i < N - 1){
            if(matriz[i + 1][j] >= matriz[i][j + 1] 
            && matriz[i + 1][j] >= matriz[i + 1][j + 1]){
                matriz[i][j] = -1;
                i++;
            }else if(matriz[i][j + 1] >= matriz[i + 1][j] 
            && matriz[i][j + 1] >= matriz[i + 1][j + 1]){
                matriz[i][j] = -1;
                j++;
            }else{
                matriz[i][j] = -1;
                i++;
                j++;
            }
        }else{
            if(matriz[i][j - 1] >= matriz[i + 1][j - 1]
            && matriz[i][j - 1] >= matriz[i + 1][j]
            && matriz[i][j - 1] >= matriz[i + 1][j + 1]
            && matriz[i][j - 1] >= matriz[i][j + 1]){
                matriz[i][j] = -1;
                j--;
            }else if(matriz[i + 1][j] >= matriz[i + 1][j - 1]
                && matriz[i + 1][j] >= matriz[i][j + 1]
                && matriz[i + 1][j] >= matriz[i + 1][j + 1]
                && matriz[i + 1][j] >= matriz[i][j - 1]){
                matriz[i][j] = -1;
                i++;
            }else if(matriz[i][j + 1] >= matriz[i + 1][j - 1]
            && matriz[i][j + 1] >= matriz[i + 1][j]
            && matriz[i][j + 1] >= matriz[i + 1][j + 1]
            && matriz[i][j + 1] >= matriz[i][j - 1]){
                matriz[i][j] = -1;
                j++;
            }else if(matriz[i + 1][j + 1] >= matriz[i][j - 1]
            && matriz[i + 1][j + 1] >= matriz[i + 1][j]
            && matriz[i + 1][j + 1] >= matriz[i + 1][j - 1]
            && matriz[i + 1][j + 1] >= matriz[i][j + 1]){
                matriz[i][j] = -1;
                i++;
                j++;
            }else{
                matriz[i][j] = -1;
                i++;
                j--;
            }
        }
    }while(i < N && j < N);
}