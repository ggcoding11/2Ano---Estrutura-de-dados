#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
} No;

void enfileirar();
void remover();
void imprimir();

No *fila = NULL;

int main(){
	setlocale(LC_ALL, "Portuguese");	

	int opcao;
	
	do {
		system("cls");
		
		printf("Pilha comum - JeeJ\n\n");
		
		printf("1 - Enfileirar\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir a fila\n");
		printf("0 - Sair\n");
		
		printf("Opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				enfileirar();
			break;
			
			case 2:
				remover();
			break;
			
			case 3:
				imprimir();
			break;
		}
	} while (opcao);

	return 0;
}

void enfileirar(){
	system("cls");
	
	int n;
	
	printf("Digite um número: ");
	scanf("%d", &n);
	
	No *novo = malloc(sizeof(No));
	
	if (novo){
		novo->dado = n;
		novo->proximo = NULL;
		
		if (fila){
			No *aux = fila;
			
			while (aux->proximo){
				aux = aux->proximo;
			}
			
			aux->proximo = novo;
		} else {
			fila = novo;
		}	
		
		printf("Valor enfileirado: %d\n", novo->dado);
	} else {
		printf("Alocacao falhou!\n");
	}
	
	system("pause");
}

void remover(){
	system("cls");
	
	if (fila){
		No *aux = fila;
		
		fila = fila->proximo;
		
		free(aux);
		
		printf("Valor removido\n");
	} else {
		printf("Fila está vazia\n");
	}
	
	system("pause");
}

void imprimir(){
	system("cls");
	
	if (fila){
		No *aux = fila;
		
		while (aux){
			printf("%d\n", aux->dado);
			
			aux = aux->proximo;
		}
	} else {
		printf("Fila está vazia\n");
	} 
	
	system("pause");
}

