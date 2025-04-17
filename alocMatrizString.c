#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nome[12][7] = {"JOSE", "CARLOS", "ANA", "VITOR", "VINI",
	"THOMAS", "HUGO", "JOAO", "CLARA", "MONICA", "RAUL", "GABY"};
	
	char ***mat;
	
	//Alocação 1
	mat = malloc(3 * sizeof(char **));
	
	int i,j, x = 0;
	
	for (i = 0; i < 3; i++){
		*(mat + i) = malloc(4 * sizeof(char *));
	}
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 4; j++){
			*(*(mat + i) + j) = malloc((strlen(nome[x])+1) * sizeof(char));
			
			strcpy(*(*(mat + i) + j), nome[x]);
			
			x++;
		}
	}
	
	printf("Matriz de strings\n\n");
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 4; j++){
			printf("%12s", *(*(mat + i) + j));
		}
		
		printf("\n");
	}
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 4; j++){
			free(*(*(mat + i) + j));
		}
		
		free(*(mat + i));
	}
	
	free(mat);

	return 0;
}

