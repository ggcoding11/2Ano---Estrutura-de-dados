#include <stdio.h>
#include <stdlib.h>

// Definição da struct Endereco
typedef struct {
    char logradouro[50]; //
    short int numero; //
    char cidade[30]; //
    char estado[3]; //
    char cep[10]; //
} ENDERECO;
//-----------------------------------------------
// Definição da struct Pessoa, que inclui um Endereco
typedef struct {
    char nome[50]; //
    char cpf[15]; //
    char rg[15]; //
    short int fone; //
    char sexo; //
    short int idade; //
    ENDERECO endereco; 
} PESSOA;
//------------------------------------------------
PESSOA cliente[5];

void cadastrarPessoas();
void listarPessoas();

int main() {   
    printf("Cadastro de usuarios\n\n");
    
    FILE *listaPessoas = fopen("listaPessoas.txt", "r");
    
    if(!listaPessoas){
    	cadastrarPessoas();
	} else {
		printf("Pessoas ja cadastradas!\n");
		printf("1 - Cadastrar novamente\n");
		printf("2 - Listar pessoas\n");
		
		int opcao;
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				cadastrarPessoas();
				break;
			case 2:
				listarPessoas();
				break;
		}
	}
    
    system("pause"); 
    return 0;
}

void cadastrarPessoas(){
	int i;
	
	for (i = 0; i < 5; i++){
		printf("Cliente %d\n\n", i+1);
		
		fflush(stdin);
		
		printf("Nome: ");
		scanf("%49[^\n]", cliente[i].nome);
		
		fflush(stdin);
		
		printf("CPF: ");
		scanf("%14[^\n]", cliente[i].cpf);
		
		fflush(stdin);
		
		printf("RG: ");
		scanf("%14[^\n]", cliente[i].rg);
		
		fflush(stdin);
		
		printf("Sexo [m/f]: ");
		scanf("%c", &cliente[i].sexo);
		
		fflush(stdin);
		
		printf("Idade: ");
		scanf("%d", &cliente[i].idade);
		
		fflush(stdin);
		
		printf("Logradouro: ");
		scanf("%49[^\n]", cliente[i].endereco.logradouro);
		
		fflush(stdin);
		
		printf("Cidade: ");
		scanf("%29[^\n]", cliente[i].endereco.cidade);
		
		fflush(stdin);
		
		printf("Estado (ex: PR): ");
		scanf("%2s", cliente[i].endereco.estado);
		
		fflush(stdin);
		
		printf("CEP: ");
		scanf("%9[^\n]", cliente[i].endereco.cep);
		
		fflush(stdin);
	}
	
	PESSOA tmp;
		
	int x, y;
	
	for (x = 0; x < 4; x++){
		for (y = x+1; y < 5; y++){
			if (strcmp(cliente[y].nome, cliente[x].nome) == -1){
				tmp = cliente[y];
				
				printf("%s", tmp.nome);
				
				cliente[y] = cliente[x];
				cliente[x] = tmp;
			}
		}
	}
	
	FILE *listaClientes = fopen("listaClientes.txt", "w");
	
	int cont;
	
	for (cont = 0; cont < 5; cont++){
		fprintf(listaClientes, "%s|%s|%s|%c|%d|%s|%s|%s|%s\n", cliente[cont].nome, cliente[cont].cpf, cliente[i].rg, cliente[cont].sexo, cliente[cont].idade, cliente[cont].endereco.logradouro, cliente[cont].endereco.cidade, cliente[cont].endereco.estado, cliente[cont].endereco.cep); 
	}

	printf("\n");
}

void listarPessoas(){
	
}
