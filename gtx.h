/* ____________________________________________________
Equipe: MATHEUS SANTOS ARAÚJO, EDSON RODRIGO E FRANCISCO JOSÉ.
Universidade Estadual do Ceará.
Curso de Ciência da Computação do CCT.
Disciplina de Introdução a Ciência da computação com prof. Dr. Leonardo.
____________________________________________________ */

#ifndef GTX_H_INCLUDED
#define GTX_H_INCLUDED
#endif

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Declaração das Structs

//struct de vetor

typedef struct{
	int n;
	double geovetor[MAX];
}vetor;

//struct de matriz

typedef struct{
	int ligne;
	int colonne;
	double geomatriz[MAX][MAX];
}matriz;

//----------------------------------------------------

//Nenhuma das funções seguintes retorna algum valor.
//Todas as funções são void.

// ||| Funções com Vetores |||

//Função para leitura de Vetor
void GeoLerVetor(vetor *v);

//Função para somar dois Vetores
void GeoSomarVetor(vetor vA, vetor vB);

//Função para realizar o Produto de um Escalar por um Vetor
void GeoProdutoporEscalar(vetor vA, double esc);

//Função para realizar o Produto Escalar entre dois Vetores
void GeoProdutoEscalar(vetor vA, vetor vB);

//-----------------------------------------------------------------

//  ||| Funções com Matrizes |||

//Função para criar e ler Matrizes
void LerMatrizes(matriz *m);

//Função para imprimir Matrizes
void ImprimeMatriz(matriz m);

//Função para somar Matrizes
void GeoSomarMatrizes(matriz mA, matriz mB);

//Função para multiplicar Matrizes
void GeoMultiplicaMatriz(matriz mA, matriz mB);

//Função para calcular determinante

void determinante(matriz m);

//Função para calcular transposta

void GeoTransposta(matriz m, matriz *t);

//Função para verificar se a matriz é simétrica
void GeoMatrizSimetrica(matriz m, matriz t);
