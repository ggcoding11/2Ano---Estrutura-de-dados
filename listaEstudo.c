#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no{
	struct apelido_no *proximo;
	int dado;
} No;

typedef struct{
	int tam;
	No *inicio;
}Lista;

void inserirIni(int n, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	novo->proximo = lista->inicio;
	lista->inicio = novo;
	
	system("pause");
}

void inserirMeio(int n, int ant, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	if (lista->inicio){
		No *aux = lista->inicio;
		
		while (aux->proximo && aux->dado != ant){
			aux = aux->proximo;
		}
		
		novo->proximo = aux->proximo;
		aux->proximo = novo;
	} else {
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}
	
	system("pause");
}

void inserirFim(int n, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;

	if (lista->inicio){
		No *aux = lista->inicio;
		
		while (aux->proximo){
			aux = aux->proximo;
		}
		
		novo->proximo = aux->proximo;
		aux->proximo = novo;
	} else {
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}

	system("pause");
}

void inserirOrdenado(int n, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	if (lista->inicio){
		No *aux = lista->inicio;
		
		if (aux->dado > n){
			novo->proximo = lista->inicio;
			lista->inicio = novo;	
		} else {
			while (aux->proximo && aux->proximo->dado < n){
				aux = aux->proximo;
			}
			
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	} else {
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}

	system("pause");
}

void remover(int n, Lista *lista){
	if (lista->inicio){
		No *aux = lista->inicio;
		
		if (aux->dado == n){
			lista->inicio = lista->inicio->proximo;
			
			free(aux);
		} else {
			while (aux->proximo && aux->proximo->dado != n){
				aux = aux->proximo;
			}
			
			if (aux->proximo == NULL){
				printf("Elemento nao encontrado!\n");
			} else {
				No *removido = aux->proximo;
				
				aux->proximo = aux->proximo->proximo;
				
				free(removido);
			}
		}
	} else {
		printf("A lista ja esta vazia!\n");
	}

	system("pause");
}

void imprimir(Lista lista){
	system("cls");
	
	if (lista.inicio){
		while (lista.inicio){
			printf("%d\n", lista.inicio->dado);
			lista.inicio = lista.inicio->proximo;
		}	
	} else {
		printf("A lista esta vazia\n");
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
	Lista lista;
	
	lista.inicio = NULL;
	lista.tam = 0;
	
	int opcao;

	do{
		system("cls");
		
		printf("LISTA SIMPLES\n\n");
		
		printf("1 - Inserir no inicio\n");
		printf("2 - Inserir no meio\n");
		printf("3 - Inserir no fim\n");
		printf("4 - Inserir ordenado\n");
		printf("5 - Remover\n");
		printf("6 - Imprimir\n");
		printf("0 - Sair\n\n");
		
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:{
				system("cls");
				
				int n = coletarDados();
				
				inserirIni(n, &lista);
			} break;
			
			case 2:{
				system("cls");
				
				int n = coletarDados();
				
				int ant;
				
				printf("Qual a referencia: ");
				scanf("%d", &ant);
				
				inserirMeio(n, ant, &lista);
			} break;
			
			case 3:{
				system("cls");
				
				int n = coletarDados();
				
				inserirFim(n, &lista);
			} break;
			
			case 4:{
				system("cls");
				
				int n = coletarDados();
				
				inserirOrdenado(n, &lista);
			} break;
			
			case 5:{
				system("cls");
				
				int n = coletarDados();
				
				remover(n, &lista);
			} break;
			
			case 6:
				imprimir(lista);
			break;
		}
	} while (opcao);

	return 0;
}

