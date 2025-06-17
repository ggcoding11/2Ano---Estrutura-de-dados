#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
	struct apelido_no *anterior;
} No;

void inserir_inicio(No **lista);
void inserir_fim(No **lista);
void inserir_meio(No **lista, int ant);
void inserir_ordenado(No **lista);
void remover_no(No **lista);

void imprimirIni(No *lista);
void imprimirFim(No *lista);

int main(){
	setlocale(LC_ALL, "Portuguese");	
	
	No *lista = NULL;

	int opcao;
	
	do {
		system("cls");
		
		printf("Lista duplamente encadeada - JeeJ\n\n");
		
		printf("1 - Inserir no inicio\n");
		printf("2 - Inserir no meio\n");
		printf("3 - Inserir no fim\n");
		printf("4 - Inserir ordenado\n");
		printf("5 - Imprimir do inicio ao fim\n");
		printf("6 - Imprimir do fim ao inicio\n");
		printf("7 - Remover\n");
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
				imprimirIni(lista);
			break;
			
			case 6:
				imprimirFim(lista);
			break;
			
			case 7:
				remover_no(&lista);
			break;
		}
	} while (opcao);

	return 0;
}

void inserir_inicio(No **lista){
	
}

void inserir_fim(No **lista){

}

void inserir_meio(No **lista, int ant){
	
}

void inserir_ordenado(No **lista){
	
}

void remover_no(No **lista){
	
}

void imprimirIni(No *lista){
	
}

void imprimirFim(No *lista){
	
}
