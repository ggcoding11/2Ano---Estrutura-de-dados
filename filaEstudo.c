#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no{
	struct apelido_no *proximo;
	int dado;
} No;

typedef struct{
	int tam;
	No *frente;
}Fila;

void enqueue(int n, Fila *fila){
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	if (novo){
		if (fila->frente){
			No *aux = fila->frente;
	
			while (aux->proximo){
				aux = aux->proximo;
			}
			
			novo->proximo = aux->proximo;
			
			aux->proximo = novo;	
		} else {
			novo->proximo = NULL;
			fila->frente = novo;
		}
		
		fila->tam++;
	} else {
		printf("ALOCACAO FALHOU!\n\n");
	}
 
	system("pause");
}

void dequeue(Fila *fila){
	if (fila->frente){
		No *aux = fila->frente;
		
		fila->frente = fila->frente->proximo;
		
		fila->tam--;
		
		free(aux);		
	} else {
		printf("A fila ja esta vazia\n\n");
	}
 
	system("pause");
}

void imprimir(Fila fila){
	printf("Tamanho: %d\n", fila.tam);
	
	if (fila.frente){
		No *aux = fila.frente;
		
		while (aux){
			printf("%d\n", aux->dado);
			
			aux = aux->proximo;
		}
	} else {
		printf("A fila esta vazia\n\n");
	}
	
	system("pause");
}

int coletarDados(){
	int n;
	printf("Qual o valor: ");
	scanf("%d", &n);
	
	return n;
}

int main(){
	Fila fila;
	
	fila.frente = NULL;
	fila.tam = 0;
	
	int opcao;

	do{
		system("cls");
		
		printf("FILA\n\n");
		
		printf("1 - Enqueue\n");
		printf("2 - Dequeue\n");
		printf("3 - Imprimir\n");
		printf("0 - Sair\n\n");
		
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:{
				system("cls");
				
				int n = coletarDados();
				
				enqueue(n, &fila);	
			} break;
			
			case 2:
				system("cls");
				
				dequeue(&fila);
			break;
			
			case 3:
				system("cls");
			
				imprimir(fila);
			break;
		}
	} while (opcao);


	return 0;
}

