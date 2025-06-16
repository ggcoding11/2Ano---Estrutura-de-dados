#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
} No;

void inserir_inicio(No **lista);
void inserir_fim(No **lista);
void inserir_meio(No **lista, int ant);
void inserir_ordenado(No **lista);
void remover_no(No **lista);
void buscar(No *lista);

void imprimir(No *lista);

int main(){
	setlocale(LC_ALL, "Portuguese");	
	
	No *lista = NULL;

	int opcao;
	
	do {
		system("cls");
		
		printf("Lista Simples - JeeJ\n\n");
		
		printf("1 - Inserir no inicio\n");
		printf("2 - Inserir no meio\n");
		printf("3 - Inserir no fim\n");
		printf("4 - Inserir ordenado\n");
		printf("5 - Imprimir\n");
		printf("6 - Remover\n");
		printf("7 - Procurar\n");
		printf("0 - Sair\n");
		
		printf("Opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				inserir_inicio(&lista);
			break;
			
			case 2:
				system("cls");				
				
				int n;
				
				printf("Digite um numero de referencia: ");
				scanf("%d", &n);
				
				inserir_meio(&lista, n);
			break;
			
			case 3:
				inserir_fim(&lista);
			break;
			
			case 4:
				inserir_ordenado(&lista);
			break;
			
			case 5:
				imprimir(lista);
			break;
			
			case 6:
				remover_no(&lista);
			break;
			
			case 7:
				buscar(lista);
			break;
		}
	} while (opcao);

	return 0;
}

void inserir_inicio(No **lista){
	system("cls");
	
	int n;
	
	printf("Qual o valor adicionado?: ");
	scanf("%d", &n);
	
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	novo->proximo = *lista;

	*lista = novo;
	
	system("pause");
}

void inserir_fim(No **lista){
	system("cls");
	
	int n;
	
	printf("Qual o valor adicionado?: ");
	scanf("%d", &n);
	
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	novo->proximo = NULL;
	
	if (*lista){
		No *aux = *lista;
	
		while (aux->proximo){
			aux = aux->proximo;
		}
		
		aux->proximo = novo;
	} else {
		*lista = novo;
	}
	
	system("pause");
}

void inserir_meio(No **lista, int ant){
	system("cls");
	
	int n;
	
	printf("Digite o valor: ");
	scanf("%d", &n);
	
	No *novo = malloc(sizeof(No));
	
	novo->dado =  n;
	
	if (*lista){
		No *aux = *lista;
		
		while (aux->proximo && aux->dado != ant){
			aux = aux->proximo;
		}
		
		novo->proximo = aux->proximo;
		aux->proximo = novo;
		
	} else {
		novo->proximo = *lista;
		
		*lista = novo;
	}
	
	system("pause");
}

void inserir_ordenado(No **lista){
	system("cls");
	
	//Lembrando que a ordem é crescente
	
	int n;
	
	printf("Qual o valor adicionado?: ");
	scanf("%d", &n);
	
	No *novo = malloc(sizeof(No));
	
	novo->dado = n;
	
	if (*lista == NULL){
		novo->proximo = NULL;
		*lista = novo;
	} else {
		if (novo->dado < (*lista)->dado){
			novo->proximo = *lista;
			*lista = novo;
		} else {
			No *aux = *lista;
			
			while (aux->proximo && novo->dado > aux->proximo->dado){
				aux = aux->proximo;
			}
			
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	}
	
	system("pause");
}

void remover_no(No **lista){
	system("cls");
	
	int n;
	
	printf("Qual o valor a ser removido?: ");
	scanf("%d", &n);
	
	if (*lista){
		No *atual = *lista;
		No *anterior = NULL;
		
		while (atual && atual->dado != n){
			anterior = atual;
			atual = atual->proximo;
		}
		
		//Se for o primeiro elemento
		if (anterior == NULL){
			*lista = atual->proximo;
			free(atual);
		} else {
			//Se nao encontrar ninguem
			if (atual == NULL){
				printf("Valor nao encontrado para remover!\n");
			} else {
				//Se não for nenhum desses, é só remover normal!
				
				anterior->proximo = atual->proximo;
				free(atual);		
			}	
		}
	} else {
		printf("A lista ja esta vazia\n");
	}
	
	system("pause");
}

void buscar(No *lista){
	system("cls");
	
	int n;
	
	printf("Insira o valor buscado: ");
	scanf("%d", &n);
	
	if (lista){
		while (lista && lista->dado != n){
			lista = lista->proximo;
		}
		
		if (lista == NULL){
			printf("Valor nao encontrado!\n");
		} else {
			printf("Valor encontrado: %d\n", lista->dado);	
		}
	} else {
		printf("A lista esta vazia\n");
	}
	
	system("pause");
}

void imprimir(No *lista){
	system("cls");
	
	if (lista){
		while (lista){
			printf("%d\n", lista->dado);
			
			lista = lista->proximo;
		}
	} else {
		printf("A lista esta vazia!\n");
	}
	
	system("pause");
}
