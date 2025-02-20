#include <stdio.h>

int main(){
	
	int pessoas = 0;
	float total = 0;
	
	do {
		float doacao;
		printf("Doacao %d: ", pessoas+1);
		scanf("%f", &doacao);
		
		total += doacao;
		
		pessoas++;
	} while (pessoas < 100 && total < 7500);
	
	float media = total/pessoas;
	
	printf("Media: %.2f", media);
	
	return 0;
}
