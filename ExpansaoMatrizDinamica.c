#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	
	printf("Matriz de numeros aleatorios (3 x 4)\n\n");
	
	int **mat;
	
	int i, j;
	
	mat = malloc(3 * sizeof(int *));
	
	for (i = 0; i < 3; i++){
		*(mat + i) = malloc(4 * sizeof(int));
	}
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 4; j++){
			*(*(mat + i) + j) = rand() % 100;
		}
	}
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 4; j++){
			printf("%10d", *(*(mat + i) + j));	
		}
		
		printf("\n");
	}
	
	printf("\nMatriz realocada (5 x 10)\n\n");
	
	mat = realloc(mat, 5 * sizeof(int *));
	
	for (i = 0; i < 3; i++){
		*(mat + i) = realloc(*(mat + i), 10 * sizeof(int));
	}
	
	for (i = 3; i < 5; i++){
		*(mat + i) = malloc(10 * sizeof(int));
	}
	
	for (i = 0; i < 3; i++){
		for (j = 4; j < 10; j++){
			*(*(mat + i) + j) = rand() % 100;
		}
	}
	
	for (i = 3; i < 5; i++){
		for (j = 0; j < 10; j++){
			*(*(mat + i) + j) = rand() % 100;
		}
	}
	
	for (i = 0; i < 5; i++){
		for (j = 0; j < 10; j++){
			printf("%10d", *(*(mat + i) + j));
		}
		
		printf("\n");
	}
	
	for (i = 0; i < 5; i++){
		free(*(mat + i));
	}
	
	free(mat);
	
	return 0;
}

