#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
}No;

void inserir(No **fila);
void remover(No **fila);
void imprimir(No *fila);

int main(){
	No *fila = NULL;
	
	int opcao;
	
	do {
		system("cls");
				
		printf("FILA USANDO PONTEIRO DE PONTEIRO - Por Mr.JeeJ\n\n");
		
		printf("1 - Adicionar\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir\n");
		printf("0 - Sair\n\n");
		
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				system("cls");
				
				inserir(&fila);
			break;
			
			case 2:
				system("cls");
				
				remover(&fila);
			break;
			
			case 3:
				system("cls");
				
				imprimir(fila);
			break;		
		}
		
		system("pause");
	} while (opcao);
	
	return 0;
}

void inserir(No **fila){
	system("cls");
	
	int n;
	
	printf("Qual o valor a ser adicionado?: ");
	scanf("%d", &n);
	
	No *novo = malloc(sizeof(No));
	
	if (novo){
		novo->dado = n;
		novo->proximo = NULL;
		
		if (*fila == NULL){
			*fila = novo;
		} else {
			No *aux = *fila;
			
			while (aux->proximo){
				aux = aux->proximo;
			}
			
			aux->proximo = novo;
		}
	} else {
		printf("Erro na alocacao!\n");
	}
}

void remover(No **fila){
	if (*fila){
		No *removido = *fila;
		*fila = (*fila)->proximo;
		
		free(removido);
		
		printf("Elemento removido!\n");
	} else {
		printf("A fila esta vazia!\n");
	}
}

void imprimir(No *fila){
	if (fila){
		while (fila){
			printf("%d\n", fila->dado);
			fila = fila->proximo;
		}
	} else {
		printf("A fila esta vazia!\n");
	}
}
