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

//Declaração das Structs

//struct de vetor

typedef struct{
	int n;
	double *geovetor;
}vetor;

//struct de matriz

typedef struct{
	int linha;
	int coluna;
	double **geomatriz;
}matriz;

//----------------------------------------------------

// ||| Funções de retorno void com Vetores |||

//Função para leitura de Vetor
void GeoLerVetor(vetor *v);

//Função para somar dois Vetores
void GeoSomarVetor(vetor vA, vetor vB);

//Função para realizar o Produto de um Escalar por um Vetor
void GeoProdutoporEscalar(vetor vA, double esc);

//Função para realizar o Produto Escalar entre dois Vetores
void GeoProdutoEscalar(vetor vA, vetor vB);

//------------------------------------------------------

//||| Funções com Vetores |||

//Função para leitura de Vetor
void GeoLerVetor(vetor *v){
	//variavel de controle do for
	int i;

	//imprime uma mensagem na tela
	printf("\nDigite o numero de elementos do Vetor: ");

	//lê a qtd de elementos do vetor
	scanf("%d", &v->n);

	// Aloca um vetor de ponteiros
	v->geovetor = (double*) malloc(v->n * sizeof(double));
	
	if(v->geovetor == NULL) {
		printf("Memoria insuficiente.\n\n");
	} else {
		//inicio do for
		for(i=0; i<v->n; i++){
			//pede pro usuário digitar o valor
			printf("\nDigite o valor de v[%d]: ", i+1);

			//lê o valor do elemento do vetor
			scanf("%lf", &v->geovetor[i]);
		}
	}
}

//Função para somar dois Vetores
void GeoSomarVetor(vetor vA, vetor vB){
	//variavel de controle do for
	int i;

	//cria um vetor soma
	double soma[vA.n];

	//inicio do for
	for(i = 0; i<vA.n; i++)
		//calcula a soma e armazena no vetor
		soma[i] = vA.geovetor[i] + vB.geovetor[i];

	//imprime uma mensagem antes do inicio do vetor
	printf("\nVetor resultante: ");

	//inicio do for para imprimir
	for(i = 0; i<vA.n; i++)
		//imprime o vetor soma
		printf("%.1lf ", soma[i]);
	printf("\n\n");
}

//Função para realizar o Produto de um Escalar por um Vetor
void GeoProdutoporEscalar(vetor vA, double esc) {
	//variavel de controle do for
	int i;

	//cria um vetor pra produto
	double prod[vA.n];

	//inicio do for
	for(i=0; i<vA.n; i++)
		//calcula o produto e armazena no vetor
		prod[i] = vA.geovetor[i] * esc;

	//imprime uma mensagem antes do inicio do vetor
	printf("\nVetor resultante: ");

	//inicio do for para imprimir
	for(i = 0; i<vA.n; i++)
		//imprime o vetor produto
		printf("%.1lf ", prod[i]);
	printf("\n\n");
}

//Função para realizar o Produto Escalar entre dois Vetores
void GeoProdutoEscalar(vetor vA, vetor vB) {

	//variavel de controle do for
	int i;

	//cria um vetor pra produto
	double prodVet[vA.n];

	//cria uma variavel para armazenar a soma dos produtos
	double soma=0;

	//inicio do for
	for(i = 0; i<vA.n; i++) {

		//realiza as multiplicações em cada indice do vetor
		prodVet[i] = vA.geovetor[i] * vB.geovetor[i];

		//soma os produtos
		soma += prodVet[i];
	}

	//imprime o resultado
	printf("\nProduto entre os vetores: %.1lf\n\n", soma);
}



//-----------------------------------------------------------------

//  ||| Funções de retorno void com Matrizes |||

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

//-------------------------------------------------------

// ||| Funções com Matrizes |||

//Função para criar e ler Matrizes
void LerMatrizes(matriz *m) {
	//pede pro usuário informar o numero de linhas da matriz
	printf("Digite o numero de linhas da Matriz: ");

	//lê o numero de linhas da matriz
	scanf("%d", &m->linha);

	//pede pro usuario informar o numero de colunas da matriz
	printf("\nDigite o numero de colunas da Matriz: ");

	//lê o número de colunas da matriz
	scanf("%d", &m->coluna);

	//variaveis de controles do for
	int i, j;

	// Aloca um vetor de ponteiros para as linhas
	m->geomatriz = (double**) malloc(m->linha * sizeof(double));

	if(m->geomatriz == NULL) {
		printf("Memoria insuficiente.\n\n");
	} else {
		//inicio do for i
		for(i = 0; i<m->linha; i++) {
			// Aloca um vetor de ponteiros para cada linha. (Colunas)
			m->geomatriz[i] = (double*) malloc(m->coluna * sizeof(double));

			if(m->geomatriz == NULL) {
				printf("Memoria insuficiente.\n\n");
			} else {
				//inicio do for j
				for(j = 0; j<m->coluna; j++) {
					//pede pro usuario digitar o elemento [i][j] da matriz
					printf("\nDigite o valor do elemento [%d][%d]: ", i+1, j+1);

					// lê o elemento [i][j] da matriz
					scanf("%lf", &m->geomatriz[i][j]);
				}
			}
		}
	}
}

//Função para imprimir Matrizes
void ImprimeMatriz(matriz m) {
	//variaveis de controles do for
	int i, j;

	//printa uma linha de hifens
	puts("\n_______________________________________________");

	//inicio do for i
	for(i=0; i<m.linha; i++) {
		//inicio do for j
		for(j=0; j<m.coluna; j++)
			//printa o elemento [i][j] da matriz
			printf("%.1lf  ", m.geomatriz[i][j]);

		//printa uma quebra de linha
		printf("\n");
	}

	//printa uma linha de hifens
	puts("__________________________________________________");
}

//Função para somar Matrizes
void GeoSomarMatrizes(matriz mA, matriz mB) {
	//variaveis de controle do for
	int i, j;

	//cria uma matriz para a soma
	double soma[mA.linha][mA.coluna];

	//inicio do for i
	for(i=0; i<mA.linha; i++) {
		//inicio do for j
		for(j=0; j<mA.coluna; j++)
			//armazena o valor da soma na matriz de soma
			soma[i][j] = mA.geomatriz[i][j] + mB.geomatriz[i][j];
	}
	//printa uma linha de hifens
	puts("\n______________________________________________________");
	//inicio do for i
	for(i=0; i<mA.linha; i++) {
		//inicio do for j
		for(j=0; j<mA.coluna; j++)
			//printa o elemento [i][j] da matriz soma
			printf("%.1lf  ", soma[i][j]);
		//printa uma quebra de linha
		printf("\n");
	}
}

//Função para multiplicar Matrizes
void GeoMultiplicaMatriz(matriz mA, matriz mB) {
	//variaveis de controle do for
	int i, j, k;

	//cria uma matriz para o produto
	double prod[mA.linha][mA.coluna];

	//inicio do for i
	for(i=0; i<mA.linha; i++) {
		//inicio do for j
		for(j=0; j<mB.coluna; j++) {
			//inicializa o valor de [i][j] como 0
			prod[i][j] = 0;

			//inicio do for k
			for(k = 0; k<mB.linha; k++)

			//o elemento [i][j] da matriz produto recebe ele mesmo mais o produto das linhas pelas colunas
			prod[i][j] +=  mA.geomatriz[i][j] * mB.geomatriz[i][j];
		}
	}
	//printa uma linha de hifens
	puts("\n___________________________________________________");

	//inicio do for i
	for(i=0; i<mA.linha; i++) {
		//inicio do for j
		for(j=0; j<mB.coluna; j++)
			//imprime o elemento [i][j] da matriz produto
			printf("%.1lf  ", prod[i][j]);

		//imprime uma quebra de linha
		printf("\n");
	}
}

//Função para calcular determinante
void determinante(matriz m) {
	//caso o numero de linhas e colunas seja 1, imprime o único elemento
	if(m.linha == 1)
		printf("\nDeterminante da matriz [%d][%d]: %.1f \n", m.linha,m.coluna, m.geomatriz[0][0]);

	//caso o numero de linhas e colunas seja 2, imprime o determinante
	else if(m.linha == 2)
		printf("\nDeterminante da matriz [%d][%d]: %.1f \n", m.linha,m.coluna, m.geomatriz[0][0] * m.geomatriz[1][1] - (m.geomatriz[0][1] * m.geomatriz[1][0]));

	//caso o numero de linhas e colunas seja 3, imprime o determinante
	else if(m.linha == 3) {
		double determinante;
		determinante = (m.geomatriz[2][0] * m.geomatriz[0][1] * m.geomatriz[1][2] +
						m.geomatriz[0][0] * m.geomatriz[1][1] * m.geomatriz[2][2] +
						m.geomatriz[1][0] * m.geomatriz[2][1] * m.geomatriz[0][2] -
						m.geomatriz[2][2] * m.geomatriz[0][1] * m.geomatriz[1][0] -
						m.geomatriz[0][2] * m.geomatriz[1][1] * m.geomatriz[2][0] -
						m.geomatriz[1][2] * m.geomatriz[2][1] * m.geomatriz[0][0]);
		printf("\nDeterminante da matriz [%d][%d]: %.1lf \n", m.linha, m.coluna, determinante);
	} else {
		puts("\nNao e possivel calcular o determinante da matriz\n");
	}
}

//Função para calcular transposta
void GeoTransposta(matriz m, matriz *t) {
	//variaveis de controle do for
	int i, j;

	//inicializa o numero de linhas e colunas da matriz transposta
	t->linha = m.coluna;
	t->coluna = m.linha;

	// Aloca um vetor de ponteiros para as linhas
	t->geomatriz = (double**) malloc(t->linha * sizeof(double));

	//inicio do for i
	for(i=0; i<t->linha; i++) {
		// Aloca um vetor de ponteiros para cada linha. (Colunas)
		t->geomatriz[i] = (double*) malloc(t->coluna * sizeof(double));

		//inicio do for j
		for(j=0; j<t->coluna; j++) {
			//inicializa o elemento [i][j] da transposta como sendo igual ao elemento [j][i] da matriz original
			t->geomatriz[i][j] = m.geomatriz[j][i];
		}
	}
	//printa uma linha de hifens
	puts("\n________________________________________________________");

	//inicio do for i
	for(i=0; i<m.coluna; i++) {
		//inicio do for j
		for(j=0; j<m.linha; j++)
			//imprime o elemento [i][j] da transposta
			printf("%.1lf  ", t->geomatriz[i][j]);

		//imprime uma quebra de linha
		printf("\n");
	}
}

//Função para verificar se a matriz é simétrica
void GeoMatrizSimetrica(matriz m, matriz t) {
	//variaveis de controle do for e uma variavel auxiliar inicializa como 0
	int i, j, aux=0;

	//testa se a matriz é quadrada
	if(m.linha != m.coluna) {
		//caso não seja, a matriz não é simetrica
		printf("\nMatriz nao e simetrica\n");
	} else {
		//caso seja quadrada:
		//inicio do for i
		for(i = 0; i<m.linha; i++) {

			//inicio do for j
			for(j = 0; j<m.coluna; j++) {

				//se o elemento [i][j] da matriz for igual ao elemento [i][j] da sua transposta
				if(m.geomatriz[i][j] == t.geomatriz[i][j])

					aux++; //caso seja, soma 1 na variavel auxiliar
			}
		}
		//testa se a variavel auxiliar é igual ao produto de linhas x colunas da matriz
		if(aux == (m.linha * m.linha)) {

			//imprime que é simétrica
			puts("\nA Matriz e simetrica");
		} else {

			//imprime que não é simétrica
			puts("\nA Matriz nao e simetrica");
		}
	}
}
