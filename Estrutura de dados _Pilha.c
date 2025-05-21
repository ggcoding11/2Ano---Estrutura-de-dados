#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *proximo;
} No;

No *top = NULL;

void push(int item);
void pop();
void imprimir();
int entrada_dados();

int main(){
	int dado, opcao;
	
	do {
		system("cls");
	
		printf("Sistema com estrutura em PILHA - Por Mr.JeeJ\n");
		printf("1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n0 - Sair\n");
		
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){	
			case 1:
				dado = entrada_dados();
				push(dado);
			break;
			
			case 2:
				pop();	
			break;
			
			case 3:
				imprimir();
			break;
		}	
		
		system("pause");
	} while (opcao != 0);
	
	return 0;
}

int entrada_dados(){
	system("cls");
	
	int n;
	
	printf("Qual o numero que sera guardado?: ");
	scanf("%d", &n);
	
	return n;	
}

void push(int item){
	No *novo = malloc(sizeof(No));
	(*novo).dado = item;
	(*novo).proximo = top;
	
	top = novo;
	
	printf("Valor empilhado!\n");
}

void pop(){
	system("cls");
	
	if (top != NULL){
		No *temp = top;
		top = (*top).proximo;
		
		free(temp);
		
		printf("Valor desempilhado\n");	
	} else {
		printf("A pilha ja esta vazia!\n");
	}
}

void imprimir(){
	system("cls");	

	printf("Pilha completa\n\n");
	
	if (top != NULL){
		No *temp = top;	
		
		while (temp != NULL){
			printf("%d\n", (*temp).dado);
			
			temp = (*temp).proximo;
		}
		
	} else {
		printf("A pilha esta vazia!\n");
	}
}
