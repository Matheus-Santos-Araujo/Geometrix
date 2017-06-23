/* ____________________________________________________
Equipe: MATHEUS SANTOS ARAÚJO, EDSON RODRIGO E FRANCISCO JOSÉ.
Universidade Estadual do Ceará.
Curso de Ciência da Computação do CCT.
Disciplina de Introdução a Ciência da computação com prof. Dr. Leonardo.
_____________________________________________________ */

#include "gtx.h"
#include <stdio.h>
#include <stdlib.h>

void exibir_menu_principal();
void exibir_menu_vetores();
void exibir_menu_matrizes();
void menu_calculos_de_vetores();
void menu_calculos_de_matrizes();

int main() {
	char Esc[5];
	int Escolha = 0;

	puts("\n\n                B E M - V I N D O  A O  G E O M E T R I X\n");
	puts("     Aqui você pode realizar diversas operações com vetores e matrizes.\n");
	
	do {
		exibir_menu_principal();
		scanf("%s", Esc);
		printf("          _______________________________________________________\n\n");
		Escolha = atoi(Esc);

		switch(Escolha) {
		case 1:
			menu_calculos_de_vetores();
			break;

		case 2:
			menu_calculos_de_matrizes();
			break;

		case 3:
			puts("\nGEOMETRIX, um oferecimento UECE, obrigado por utilizar nosso sistema volte sempre!");
			break;
			default:
			puts("\nOpcao Invalida");
			break;
		}
	} while(Escolha != 3);
}

void exibir_menu_principal() {
	puts("   [[__________________________MENU PRINCIPAL__________________________]]\n");
	puts("Escolha uma das alternativas abaixo:\n");
	puts("1 --> CALCULOS DE VETORES\n");
	puts("2 --> CALCULOS DE MATRIZES\n");
	puts("3 --> SAIR DO GEOMETRIX\n");
	printf("Entre com sua opcao de escolha: ");
}


void exibir_menu_vetores() {
	puts("[[__________________________MENU DE VETORES__________________________]]\n");
	puts("Escolha uma das alternativas abaixo:\n" );
	puts("1 --> Ler dois vetores\n");
	puts("2 --> Somar dois vetores\n");
	puts("3 --> Multiplicar um dos vetores por um escalar\n");
	puts("4 --> Produto escalar entre dois vetores\n");
	puts("5 --> Voltar para o menu anterior\n");
	printf("Entre com sua opcao de escolha: ");
}


void exibir_menu_matrizes() {
	puts("[[__________________________MENU DE MATRIZES__________________________]]\n");
	puts("Escolha uma das alternativas abaixo:\n");
	puts("1 --> Ler matrizes\n");
	puts("2 --> Somar duas matrizes\n");
	puts("3 --> Multiplicar duas matrizes\n");
	puts("4 --> Calcular a transposta de uma matriz\n");
	puts("5 --> Calcular o determinante de uma matriz\n");
	puts("6 --> Verificar se uma matriz e simetrica\n");
	puts("7 --> Voltar ao menu principal\n");
	printf("Entre com sua opcao de escolha: ");
}

void menu_calculos_de_vetores() {
	vetor vA;
	vetor vB;
	int num, EscolhaB = 0;
	char EscB[5];
	double esc;
	
	do {
		exibir_menu_vetores();
		scanf("%s", EscB);
		puts("______________________________________________________\n");

		EscolhaB = atoi(EscB);

		switch(EscolhaB) {
		case 1: // Ler dois vetores
			GeoLerVetor(&vA);
			GeoLerVetor(&vB);


			break;
		case 2: // Somar dois vetores
			if(vA.n != vB.n)
				puts("\nComando invalido! Os vetores nao possuem a mesma dimensao.");
			else
				GeoSomarVetor(vA, vB);
			break;


		case 3: // Multiplicar um dos vetores por um escalar
			printf("\nQual vetor voce deseja multiplicar: ");
			scanf("%d", &num);
			if( num != 1 && num != 2){
				puts("Digite uma opcao valida");
				break;
			}
			printf("\nDigite o escalar: ");
			scanf("%lf", &esc);
			if(num == 1)
				GeoProdutoporEscalar(vA, esc);
			else if(num == 2)
				GeoProdutoporEscalar(vB, esc);
			break;


		case 4: // Produto escalar entre dois vetores
			if(vA.n != vB.n)
				puts("Comando invalido! Os vetores nao possuem a mesma dimensao!");
			else
				GeoProdutoEscalar(vA, vB);
			break;


		case 5: // Voltar para o menu anterior
			free(vA.geovetor);
			free(vB.geovetor);
			puts("\nRetornando ao menu principal do Geometrix\n");
			break;
		default:
			puts("\nComando invalido!");
			break;
		}
	} while(EscolhaB != 5);
}


void menu_calculos_de_matrizes() {
	matriz mA;
	matriz mB;
	matriz tA;
	matriz tB;
	int num, EscolhaC = 0;
	char EscC[5];

	do {
		exibir_menu_matrizes();
		scanf("%s", EscC);
		puts("_______________________________________________________\n");

		EscolhaC = atoi(EscC);

		switch(EscolhaC) {
		case 1: // Ler matrizes
			printf("\nDigite a Matriz 1:\n");
			LerMatrizes(&mA);
			printf("\nDigite a Matriz 2:\n \n");
			LerMatrizes(&mB);
			printf("\nMatriz 1:\n ");
			ImprimeMatriz(mA);
			printf("\nMatriz 2:\n ");
			ImprimeMatriz(mB);
			break;


		case 2: // Somar duas matrizes
			if(mA.linha != mB.linha || mA.coluna != mB.coluna)
				puts("\nComando inválido! As matrizes nao possuem a mesma dimensao");
			else
				GeoSomarMatrizes(mA, mB);
			break;


		case 3: // Multiplicar duas matrizes
			if(mB.linha != mA.coluna)
				puts("\nComando inválido! Nao e possivel realizar a multiplicacao");
			else
				GeoMultiplicaMatriz(mA, mB);
			break;


		case 4: // Calcular a transposta de uma matriz
			printf("\nDigite a matriz que deseja utilizar: ");
			scanf("%d", &num);
			if(num!=1 && num!=2) {
				puts("\nOpcao Invalida");
				break;
			} else if(num==1)
				GeoTransposta(mA, &tA);
			else
				GeoTransposta(mB, &tB);
			break;


		case 5: // Calcular o determinante de uma matriz
			printf("\nDigite a matriz que deseja utilizar: ");
			scanf("%d", &num);
			if(num!=1 && num!=2){
				printf("\nComando inválido\n");
				break;
			} else if(num==1) {
				if(mA.linha == mA.coluna)
					determinante(mA);
				else {
					puts("\nComando inválido! Nao e possivel calcular o determinante");
					break;
				}
			} else {
				if(mB.linha == mB.coluna)
					determinante(mB);
				else {
					puts("\nComando inválido! Nao e possivel calcular o determinante");
					break;
				}
			}
			break;


		case 6: // Verificar se uma matriz e simetrica
			printf("\nQual matriz voce deseja saber se e simetrica: ");
			scanf("%d", &num);
			if(num != 1 && num != 2) {
				puts("\nDigite uma opcao valida");
				break;
			} else if(num == 1) {
				GeoTransposta(mA,&tA);
				GeoMatrizSimetrica(mA,tA);
			} else {
				GeoTransposta(mB,&tB);
				GeoMatrizSimetrica(mB,tB);
			}
			break;


		case 7: // Voltar ao menu principal
			free(mA.geomatriz);
			free(mB.geomatriz);
			break;
		}
	} while(EscolhaC !=7);
}
