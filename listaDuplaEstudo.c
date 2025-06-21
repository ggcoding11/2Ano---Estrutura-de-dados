#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no{
	struct apelido_no *proximo;
	struct apelido_no *anterior;
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
	novo->anterior = NULL;
	
	if (lista->inicio){
		lista->inicio->anterior = novo;
	}
	
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
		novo->anterior = aux;
		
		if (aux->proximo){
			aux->proximo->anterior = novo;
		}
		
		aux->proximo = novo;
	} else {
		novo->proximo = lista->inicio;
		novo->anterior = NULL;
		
		if (lista->inicio){
			lista->inicio->anterior = novo;
		}
		
		lista->inicio = novo;
	}
	
	system("pause");
}

void inserirFim(int n, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado =  n;
	
	if (lista->inicio){
		No *aux = lista->inicio;
		
		while (aux->proximo){
			aux = aux->proximo;
		}
		
		novo->proximo = aux->proximo;
		novo->anterior = aux;
		
		aux->proximo = novo;
	} else {
		novo->proximo = lista->inicio;
		novo->anterior = NULL;
		
		if (lista->inicio){
			lista->inicio->anterior = novo;
		}
		
		lista->inicio = novo;
	}
	
	system("pause");
}

void inserirOrdenado(int n, Lista *lista){
	No *novo = malloc(sizeof(No));
	
	novo->dado =  n;
	
	if (lista->inicio){
		No *aux = lista->inicio;
		
		if (aux->dado > n){
			novo->proximo = lista->inicio;
			novo->anterior = NULL;
			
			lista->inicio->anterior = novo;
			
			lista->inicio = novo;
			
		} else {
			while (aux->proximo && aux->proximo->dado < n){
				aux = aux->proximo;
			} 
			
			novo->proximo = aux->proximo;
			novo->anterior = aux;
			
			if (aux->proximo){
				aux->proximo->anterior = novo;
			}
			
			aux->proximo = novo;
		}
	} else {
		novo->proximo = lista->inicio;
		novo->anterior = NULL;
		
		if (lista->inicio){
			lista->inicio->anterior = novo;
		}
		
		lista->inicio = novo;
	}
	
	system("pause");
}

void remover(int n, Lista *lista){
	
	if (lista->inicio){
		No *aux = lista->inicio;
		
		while (aux && aux->dado != n){
			aux = aux->proximo;
		}	
		
		if (aux == NULL){
			printf("Elemento nao encontrado!\n");		
		} else {
			if (aux->anterior == NULL){
				lista->inicio = aux->proximo;
				
				if (lista->inicio){
					lista->inicio->anterior = NULL;	
				}
				
				free(aux);
			} else {
				aux->anterior->proximo = aux->proximo;
				
				if (aux->proximo){
					aux->proximo->anterior = aux->anterior;
				}
			}
		}
	} else {
		printf("A lista ja esta vazia!\n");
	}
	
	system("pause");
}

void imprimirIF(Lista lista){
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

void imprimirFI(Lista lista){
	system("cls");
	
	if (lista.inicio){
		No *aux = lista.inicio;
		
		while (aux->proximo){
			aux = aux->proximo;
		}	
		
		while (aux){
			printf("%d\n", aux->dado);
			
			aux = aux->anterior;
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
		
		printf("LISTA DUPLA\n\n");
		
		printf("1 - Inserir no inicio\n");
		printf("2 - Inserir no meio\n");
		printf("3 - Inserir no fim\n");
		printf("4 - Inserir ordenado\n");
		printf("5 - Remover\n");
		printf("6 - Imprimir do inicio ao fim\n");
		printf("7 - Imprimir do fim ao inicio\n");
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
			
			case 7:
				imprimirFI(lista);
			break;
		}
	} while (opcao);

	return 0;
}

