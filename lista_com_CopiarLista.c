#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int valor;
  struct no *proximo;
}No;

typedef struct{
  No *inicio;
  int tam;
}Lista;

void criar_lista(Lista *lista){
  lista->inicio = NULL;
  lista->tam = 0;
}
//-----------------------------------------------------------------
void inserir_inicio(Lista *lista, int num){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
  }else
    printf("Erro ao alocar memoria.\n");
}
//-----------------------------------------------------------------
void inserir_fim(Lista *lista, int num){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = NULL;

    if(lista->inicio == NULL)
      lista->inicio = novo;
    else{
      aux = lista->inicio;
      while(aux->proximo)
        aux = aux->proximo;
      aux->proximo = novo;
    }
    lista->tam++;
  }else
    printf("Erro ao alocar memoria.\n");
}
//-----------------------------------------------------------------
void inserir_meio(Lista *lista, int num, int ant){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;

    if(lista->inicio == NULL){
      novo->proximo = NULL;
      lista->inicio = novo;
    }else{
      aux = lista->inicio;
      while(aux->valor != ant && aux->proximo)
        aux = aux->proximo;
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
    lista->tam++;
  }else
    printf("Erro ao locar memoria.\n");
}
//-----------------------------------------------------------------
void inserir_ordenado(Lista *lista, int num){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;

    if(lista->inicio == NULL){
      novo->proximo = NULL;
      lista->inicio = novo;
    }else if(novo->valor < lista->inicio->valor){
      novo->proximo = lista->inicio;
      lista->inicio = novo;
    }else{
      aux = lista->inicio;
      while(aux->proximo && novo->valor > aux->proximo->valor)
        aux = aux->proximo;
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
    lista->tam++;
  }else
    printf("Erro ao alocar memoria.\n");
}
//-----------------------------------------------------------------
No* remover(Lista *lista, int num){
  No *aux, *no = NULL;

  if(lista->inicio){
    if(lista->inicio->valor == num){
      no = lista->inicio;
      lista->inicio = no->proximo;
      lista->tam--;
    }else{
      aux = lista->inicio;
      while(aux->proximo && aux->proximo->valor != num)
        aux = aux->proximo;
      if(aux->proximo){
        no = aux->proximo;
        aux->proximo = no->proximo;
        lista->tam--;
      }
    }
  }
  return no;
}
//-----------------------------------------------------------------
No* buscar(Lista *lista, int num){
  No *aux, *no = NULL;

  aux = lista->inicio;
  while(aux && aux->valor != num)
    aux = aux->proximo;
  if(aux)
    no = aux;
  return no;
}

void imprimir(Lista lista){
  No *no = lista.inicio;
  printf("\nTamanho da Lista: %d \n\n", lista.tam);
  while(no){
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n\n");
}

void copiarLista(Lista lista){
	Lista lista2;
	
	criar_lista(&lista2);
	
	while ((lista.inicio)){
		inserir_fim(&lista2, (lista.inicio)->valor);
		
		lista.inicio = (lista.inicio)->proximo;
	}
	
	imprimir(lista2);
}

//-----------------------------------------------------------------
int main(void) {
  int opcao, valor, anterior;
  No *no;
  Lista lista;
  criar_lista(&lista);
  do{
  	system("cls");
  	
    printf("\n0 - Sair\n1 - Inserir no inicio\n2 - Inserir no fim\n3 - Inserir no meio\n4 - Inserir ordenado\n5 - Remover\n6 - Imprimir\n7 - Buscar\n8 - Copiar lista\n\nOpcao: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_inicio(&lista, valor);
        break;
      case 2:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_fim(&lista, valor);
        break;
      case 3:
        printf("Valor a ser inserido e valor de referencia: ");
        scanf("%d%d", &valor, &anterior);
        inserir_meio(&lista, valor, anterior);
        break;
      case 4:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_ordenado(&lista, valor);
        break;
      case 5:
        printf("Remover valor: ");
        scanf("%d", &valor);
        no = remover(&lista, valor);
        if(no){
          printf("Elemento: %d", no->valor);
          free(no);
        }else
          printf("Elemento nao encontrado.\n");
        break;
      case 6:
        imprimir(lista);
        break;
      case 7:
        printf("Buscar valor: ");
        scanf("%d", &valor);
        no = buscar(&lista, valor);
        if(no){
          printf("Elemento: %d", no->valor);          
        }else
          printf("Elemento nao encontrado.\n");
        break;
        
      case 8:
      	copiarLista(lista);
    	break;
      default:
        if(opcao != 0)
          printf("Opcao invalida.\n");
    }
    
    system("pause");
  }while(opcao != 0);
  return 0;
}

