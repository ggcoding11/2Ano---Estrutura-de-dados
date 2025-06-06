#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;	
}No;

No *empilhar(No* topo); // Aqui não vai alterar o valor de topo
No *desempilhar(No **topo); //Aqui vai, pois é uma passagem de parâmetro por referência

void imprimir(No *topo);

int coletaDado();

int main(){
	No *topo = NULL;
		
	int opcao;
		
	do {
		system("cls");
		
		printf("PILHA COM PONTEIRO DE PONTEIRO - Por Mr.JeeJ\n\n");
		
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Imprimir\n");
		printf("0 - Sair\n\n");
		
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				system("cls");		
				
				topo = empilhar(topo);
				
				if (topo){
					printf("Elemento empilhado: %d\n", topo->dado);
				}
				
				system("pause");
			break;
			
			case 2:
				system("cls");
				
				No *remover = desempilhar(&topo);
				
				if (remover){
					printf("Elemento removido!\n\n");
				
					free(remover);	
				} 
				
				system("pause");
			break;
			
			case 3:
				system("cls");
				
				imprimir(topo);
				
				system("pause");
			break;
		}
	} while (opcao);

	return 0;
}

No *empilhar(No *topo){
	int n = coletaDado();
	
	No *novo = malloc(sizeof(No));
	
	if (novo){
		novo->dado = n;
		novo->proximo = topo;	
		return novo;
	} else {
		printf("Alocacao falhou!\n");
		return NULL;
	}
}

//PAREI AQUI - FALTA ENTENDER O PONTEIRO DE PONTEIRO

No *desempilhar (No **topo){
	if (*topo) { // Se eu escrever só topo, ele vai retornar o endereço próprio de topo. Entao se eu adicionar um asterisco, ele vai olhar dentro do ponteiro, ai vai dar bom
		No *temp = *topo; //Aqui
		*topo = temp->proximo;
		
		return temp;
	} else {
		printf("A pilha esta vazia!\n");
		
		return NULL;
	}
}

int coletaDado(){
	int n;
	
	printf("Digite um numero: ");
	scanf("%d", &n);
	
	return n;	
}

void imprimir(No *topo){	
	if (!topo){
		printf("Pilha vazia!\n\n");
	} else {
		while (topo){
			printf("%d\n", topo->dado);
			topo = topo->proximo;
		}	
	}
}
