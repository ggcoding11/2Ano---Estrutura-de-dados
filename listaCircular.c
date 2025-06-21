#include <stdio.h>	
#include <stdlib.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
	struct apelido_no *anterior;	
}No;

typedef struct{
	int tam;
	No *inicio;
	No *fim;
} Lista;

void inserirIni(int n, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	if (lista->inicio){
		novo->proximo = lista->inicio;
		novo->anterior = lista->fim;
		
		lista->inicio->anterior = novo;
		lista->fim->proximo = novo;
		
		lista->inicio = novo;
	} else {
		novo->proximo = novo;
		novo->anterior = novo;
		
		lista->inicio = novo;
		lista->fim = novo;
	}
	
	system("pause");
}

void inserirMeio(int n, int ant, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	if (lista->inicio){
		No *aux = lista->inicio;
		
		while (aux != lista->fim && aux->dado != ant){
			aux = aux->proximo;
		}
		
		if (aux == lista->fim){
			novo->proximo = lista->inicio;
			novo->anterior = aux;
			aux->proximo = novo;
			lista->inicio->anterior = novo;
			
			lista->fim = novo;
		} else {
			novo->proximo = aux->proximo;
			novo->anterior = aux;
			aux->proximo = novo;
			novo->proximo->anterior = novo;
		}
	} else {
		novo->proximo = novo;
		novo->anterior = novo;
		
		lista->inicio = novo;
		lista->fim = novo;
	}
	
	system("pause");
}

void inserirFim(int n, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	if (lista->inicio){
		No *aux = lista->inicio;
		
		while (aux != lista->fim){
			aux = aux->proximo;
		}
		
		novo->proximo = lista->inicio;
		novo->anterior = lista->fim;
		lista->fim->proximo = novo;
		lista->inicio->anterior = novo;
		
		lista->fim = novo;
	} else {
		novo->proximo = novo;
		novo->anterior = novo;
		
		lista->inicio = novo;
		lista->fim = novo;
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
			novo->anterior = lista->fim;
			lista->fim->proximo = novo;
			lista->inicio->anterior = novo;
			
			lista->inicio = novo;
		} else {
			while (aux->proximo->dado < n && aux != lista->fim){
				aux = aux->proximo;
			}
			
			if (aux == lista->fim){
				novo->proximo = lista->inicio;
				novo->anterior = lista->fim;
				lista->fim->proximo = novo;
				lista->inicio->anterior = novo;
				
				lista->fim = novo;
			} else {
				novo->proximo = aux->proximo;
				novo->anterior = aux;
				aux->proximo = novo;
				novo->proximo->anterior = novo;
			}
		}
	} else {
		novo->proximo = novo;
		novo->anterior = novo;
		
		lista->inicio = novo;
		lista->fim = novo;
	}
	
	system("pause");
}

void remover(int n, Lista *lista){
	if (lista->inicio){
		No *aux = lista->inicio;
		
		while (aux != lista->fim && aux->dado != n){
			aux = aux->proximo;
		}
		
		if (aux->dado != n){
			printf("Elemento nao encontrado!\n");
		} else {
			if (lista->inicio == lista->fim){
				lista->inicio = NULL;
				lista->fim = NULL;
				
				free(aux);
			} else {
				if (aux == lista->inicio){
					lista->inicio = lista->inicio->proximo;
					lista->inicio->anterior = lista->fim;
					lista->fim->proximo = lista->inicio;
					
					free(aux);
				} else {
					if (aux == lista->fim){
						lista->fim = lista->fim->anterior;
						lista->fim->proximo = lista->inicio;
						lista->inicio->anterior = lista->fim;
						
						free(aux);
					} else {
						aux->anterior->proximo = aux->proximo;
						aux->proximo->anterior = aux->anterior;
						
						free(aux);
					}
				}
			}
		}
		
	} else {
		printf("A lista esta vazia\n");
	}
	
	system("pause");
}

void imprimirIF(Lista lista){
	system("cls");
	
	if (lista.inicio){
		No *aux = lista.inicio;
		
		do {
			printf("%d\n", aux->dado);
			aux = aux->proximo;
		} while (aux != lista.inicio);
		
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
	lista.fim = NULL;
	lista.tam = 0;
	
	int opcao;
			
	do {
		system("cls");
		
		printf("LISTA CIRCULAR\n\n");
		
		printf("1 - Inserir no inicio\n");
		printf("2 - Inserir no meio\n");
		printf("3 - Inserir no fim\n");
		printf("4 - Inserir no ordenado\n");
		printf("5 - Remover\n");
		printf("6 - Imprimir do inicio ao fim\n");
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
				imprimirIF(lista);
			break;
		}
	} while (opcao);

	return 0;
}
