#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no{
	struct apelido_no *proximo;
	int dado;
} No;

typedef struct{
	int tam;
	No *topo;
}Pilha;

void push(int n, Pilha *pilha){
	No *novo = malloc(sizeof(No));
	
	if (novo){
		novo->dado = n;
		novo->proximo = pilha->topo;
		
		pilha->topo = novo;		
	} else {
		printf("ALOCACAO FALHOU!!\n\n");
	}
 
	system("pause");
}

void pop(Pilha *pilha){
	if (pilha->topo){
		No *aux = pilha->topo;
		
		pilha->topo = pilha->topo->proximo;
		
		free(aux);		
	} else {
		printf("A pilha ja esta vazia!!\n\n");
	}
 
	system("pause");
}

void imprimir(Pilha pilha){
	if (pilha.topo){
		while(pilha.topo){
			printf("%d\n", pilha.topo->dado);
			
			pilha.topo = pilha.topo->proximo;
		}	
	} else {
		printf("A pilha esta vazia!!\n\n");
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
	Pilha pilha;
	
	pilha.topo = NULL;
	pilha.tam = 0;
	
	int opcao;

	do{
		system("cls");
		
		printf("PILHA\n\n");
		
		printf("1 - Push\n");
		printf("2 - Pop\n");
		printf("3 - Imprimir\n");
		printf("0 - Sair\n\n");
		
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:{
				system("cls");
				
				int n = coletarDados();
				
				push(n, &pilha);	
			} break;
			
			case 2:
				system("cls");
				
				pop(&pilha);
			break;
			
			case 3:
				system("cls");
			
				imprimir(pilha);
			break;
		}
	} while (opcao);


	return 0;
}

