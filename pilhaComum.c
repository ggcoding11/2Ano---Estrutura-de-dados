#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
} No;

void empilhar();
void desempilhar();
void imprimir();

No *topo = NULL;

int main(){
	setlocale(LC_ALL, "Portuguese");	

	int opcao;
	
	do {
		system("cls");
		
		printf("Pilha comum - JeeJ\n\n");
		
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Imprimir a pilha\n");
		printf("0 - Sair\n");
		
		printf("Opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				empilhar();
			break;
			
			case 2:
				desempilhar();
			break;
			
			case 3:
				imprimir();
			break;
		}
	} while (opcao);

	return 0;
}

void empilhar(){
	system("cls");
	
	int n;
	
	printf("Digite um número: ");
	scanf("%d", &n);
	
	No *novo = malloc(sizeof(No));
	
	if (novo){	
		novo->dado = n;
		novo->proximo = topo;
			
		topo = novo;
		
		printf("Valor empilhado: %d\n", topo->dado);	
	} else {
		printf("Alocacao falhou!\n");
	}
	
	system("pause");
}

void desempilhar(){
	system("cls");
	
	if (topo){
		No *aux = topo;
	
		topo = topo->proximo;
		
		free(aux);	
		
		printf("Valor desempilhado\n");
	} else {
		printf("A pilha já está vazia!\n");
	}
	
	system("pause");
}

void imprimir(){
	system("cls");
	
	if (topo){
		No *aux = topo;
		
		while (aux) {
			printf("%d\n", aux->dado);
			
			aux = aux->proximo;
		}
	} else {
		printf("A pilha está vazia!\n");
	}

	system("pause");
}

