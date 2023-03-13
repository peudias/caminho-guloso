#include "caminhoguloso.h"

int main(){
	int **matriz;
	int t;
	matriz = lerArquivo(&t);

	printf("\nMatriz Inicial\n");
	ImprimeAleatoria(t, matriz);
	printf("\n");
	
	Caminho(matriz, t);

	printf("\nMatriz Percorrida\n");
	ImprimeAleatoria(t, matriz);

	return 0;
}
