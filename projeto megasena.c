/*Leia um vetor A de 6 elementos contendo o gabarito da Mega-Sena. 

O sorteio consiste na extração de 6 números diferentes, no universo de 1 à 60. 

 A seguir, ler um vetor B para a aposta de tamanho 10. Esse vetor deverá ter no mínimo 6 valores e no máximo 10 valores. 

Atenção: Uma aposta só poderá ser finalizada quando tiver pelo menos 6 números digitados.

Uma aposta será finalizada automaticamente quando tiver 10 números digitados.

Escrever quantos pontos fez o apostador, e se ele fez a sena (6 acertos), a quina (5 acertos) ou a quadra (4 acertos).

Nesse exercício o usuário digita todos os valores, o gabarito e a aposta.

Não permitir que o usuário digite números repetidos para o gabarito ou aposta.

Não permitir que o usuário digite números fora do universo de 1 à 60.*/

#include <stdio.h>
#include <stdlib.h> //Biblioteca usada para limpar a tela do console

#define TAM_GAB 6


int main ()
{
	int i = 0, aux, tam_apo = 10, gab[TAM_GAB], apo[tam_apo], continuar, qtde_acertos = 0;
	
	
	while(i < TAM_GAB)
	{
		printf("Digite o valor %i do Gabarito: ",i);
		scanf("%i", &gab[i]);
		
		if(gab[i] >= 1 && gab[i] <= 60)
		{
			if(i > 0)
			{
				aux = i - 1;
				
				while(aux >= 0)
				{
					if(gab[i] == gab[aux]) 
					{
						printf("\nERRO... O numero digitado ja foi cadastrado\n");		
						i--;            	
					}
					aux--;
				}
			}
			i++;
		}
		else
		{
			printf("\nO valor tem que ser maior que 0 e menor que 61.\n\n");
		}
	}
	
	system("cls"); //Limpa a tela 
	
	i = 0;
	
	while(i < tam_apo)
	{
		if(i > 5)
		{
			printf("\nJa foram apostados %i numeros. Deseja realizar mais uma aposta?\n", i);
			printf("1 - SIM\n");
			printf("2 - NAO\n");
			scanf("%i", &continuar);	
			
			printf("\n");
			
			if(continuar == 2)
			{
				tam_apo = i;
				break;	
			}
		}
		printf("Digite o valor %i da Aposta: ",i);
		scanf("%i", &apo[i]);
		
		if(apo[i] >= 1 && apo[i] <= 60)
		{
			if(i > 0)
			{
				aux = i - 1;
				
				while(aux >= 0)
				{
					if(apo[i] == apo[aux]) 
					{
						printf("\nERRO... O numero digitado ja foi cadastrado\n");		
						i--;            	
					}
					aux--;
				}
			}
			i++;
		}
		else
		{
			printf("\nO valor tem que ser maior que 0 e menor que 61.\n\n");
		}
	}
	
	
	for(i = 0; i < tam_apo; i++)
	{
		aux = 0;
		while(apo[i] != gab[aux] && aux < TAM_GAB)
		{
			aux++;
		}
		
		if(apo[i] == gab[aux]){
			qtde_acertos++;
		}
	}
	
	system("cls");
	
	printf("\tGABARITO\n\n");
	
	for(i=0; i<TAM_GAB; i++)
	{
		printf("%i ",gab[i]);
	}
	
	printf("\n\n");
	printf("\tAPOSTA\n\n");
		
	for(i=0; i<tam_apo; i++)
	{
		printf("%i ",apo[i]);
	}
	
	printf("\n\nNumero de acertos = %i", qtde_acertos);
	printf("\n\n");
	
	if(qtde_acertos == 4)
	{
		printf("O apostador fez a quadra");
	}
	else
	{
		if(qtde_acertos == 5)
		{
			printf("O apostador fez a quina");			
		}
		else
		{
			if(qtde_acertos == 6)
			{
				printf("O apostador fez a sena");
			}
		}
	}
	
	return 0;
}




