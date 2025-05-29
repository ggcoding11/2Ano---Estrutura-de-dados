#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_do_no{
	int dado;
	struct apelido_do_no *proximo;
}No;

No *topo = NULL;

void push(int n);
void pop();
void printarFila();
int coletaDados();

int main(){
	
	int opcao;
	
	do {
		system("cls");
		
		printf("PILHA - Por Mr.JeeJ\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Printar a fila\n");
		printf("0 - Sair\n\n");
		
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				system("cls");
				
				int n = coletaDados();				
				push(n);
			break;
			
			case 2:
				pop();
			break;
			
			case 3:
				printarFila();
			break;
		}	
	} while(opcao != 0);
	
	return 0;
}

int coletaDados(){
	printf("Insira um numero: ");
	
	int n;
	
	scanf("%d", &n);
	
	return n;
}

void push(int n){
	
	No *novo = malloc(sizeof(No));
	
	(*novo).dado = n;
	(*novo).proximo = topo;
	
	topo = novo;
	
	printf("Valor empilhado!\n");
	
	system("pause");
}

void pop(){
	system("cls");
	
	if (topo == NULL){
		printf("A pilha ja esta vazia!\n");
	} else {
		No *temp = topo;
		topo = (*topo).proximo;
		free(temp);
		
		printf("O dado foi retirado!\n");
	}
	
	system("pause");
}

void printarFila(){
	system("cls");
	
	No *temp = topo;
	
	while (temp != NULL){
		printf("%d\n", (*temp).dado);
		
		temp = (*temp).proximo;
	}
	
	system("pause");
}
