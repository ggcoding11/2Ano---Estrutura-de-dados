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
	int opcao;
	
	system("cls");
	
	printf("Sistema com estrutura em PILHA - Por Mr.JeeJ\n");
	printf("1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n0 - Sair\n");
	
	printf("Escolha uma opcao: \n");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 0:
			system("pause");
		break;
		
		case 1:
			
		break;
		
		
		case 2:
			
		break;
		
		case 3:
			
		break;
	}
		
	return 0;
}

