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
	//linha
	int ligne;
	//coluna
	int colonne;
	double geomatriz[MAX][MAX];
}matriz;

//----------------------------------------------------

// ||| Funções de retorno void com Vetores (Prototipo) |||

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

	//inicio do for
    for(i=0; i<v->n; i++){

    	//pede pro usuário digitar o valor
        printf("\nDigite o valor de v[%d]: ", i+1);

        //lê o valor do elemento do vetor
        scanf("%lf", &v->geovetor[i]);
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
    printf("\n");
}

//Função para realizar o Produto de um Escalar por um Vetor
void GeoProdutoporEscalar(vetor vA, double esc){

   //variavel de controle do for
   int i;

   //cria um vetor pra produto
   double prod[vA.n];

   //inicio do for
   for(i=0;i<vA.n;i++)

   //calcula o produto e armazena no vetor
   prod[i] = vA.geovetor[i] * esc;

   //imprime uma mensagem antes do inicio do vetor
   printf("\nVetor resultante: ");

   //inicio do for para imprimir
	for(i = 0; i<vA.n; i++)

		//imprime o vetor produto
		printf("%.1lf ", prod[i]);
    printf("\n");
}

//Função para realizar o Produto Escalar entre dois Vetores
void GeoProdutoEscalar(vetor vA, vetor vB){

	//variavel de controle do for
	int i;

	//cria um vetor pra produto
	double prodVet[vA.n];

	//cria uma variavel para armazenar a soma dos produtos
	double soma=0;

	//inicio do for
	for(i = 0; i<vA.n; i++){

		//realiza as multiplicações em cada indice do vetor
		prodVet[i] = vA.geovetor[i] * vB.geovetor[i];

		//soma os produtos
		soma += prodVet[i];
	}

	//imprime o resultado
	printf("\nProduto entre os vetores: %.1lf\n", soma);
}



//-----------------------------------------------------------------

//  ||| Funções de retorno void com Matrizes (prototipo) |||

//Função para criar e ler Matrizes
void LerMatrizes(matriz *m);

//Função para imprimir Matrizes
void ImprimeMatriz(matriz m);

//Função para somar Matrizes
void GeoSomarMatrizes(matriz mA, matriz mB);

//Função para multiplicar Matrizes
void GeoMultiplicaMatriz(matriz mA, matriz mB);

//Função para calcular determinante

void determinante();

//Função para calcular transposta

void GeoTransposta(matriz m, matriz *t);

//Função para verificar se a matriz é simétrica
void GeoMatrizSimetrica(matriz m, matriz t);

//-------------------------------------------------------

// ||| Funções com Matrizes |||

//Função para criar e ler Matrizes
void LerMatrizes(matriz *m){

	//pede pro usuário informar o numero de linhas da matriz
	printf("Digite o numero de linhas da Matriz: ");

	//lê o numero de linhas da matriz
	scanf("%d", &m->ligne);

	//pede pro usuario informar o numero de colunas da matriz
	printf("\nDigite o numero de colunas da Matriz: ");

	//lê o número de colunas da matriz
	scanf("%d", &m->colonne);

	//variaveis de controles do for
	int i, j;

	//inicio do for i
	for(i = 0; i<m->ligne; i++){

		//inicio do for j
		for(j = 0; j<m->colonne; j++){

		//pede pro usuario digitar o elemento [i][j] da matriz
        	printf("\nDigite o valor do elemento [%d][%d]: ", i+1, j+1);

        	// lê o elemento [i][j] da matriz
        	scanf("%lf", &m->geomatriz[i][j]);
		}
	}

}

//Função para imprimir Matrizes
void ImprimeMatriz(matriz m){

    //variaveis de controles do for
    int i,j;

   //printa uma linha de hifens
   puts("\n_______________________________________________");

       //inicio do for i
      for(i=0;i<m.ligne;i++){

      //inicio do for j
      for(j=0;j<m.colonne;j++)

      //printa o elemento [i][j] da matriz
      printf("%.1lf  ", m.geomatriz[i][j]);

      //printa uma quebra de linha
      printf("\n");
    }

      //printa uma linha de hifens
      puts("__________________________________________________");
}

//Função para somar Matrizes
void GeoSomarMatrizes(matriz mA, matriz mB){

	//variaveis de controle do for
	int i,j;

	//cria uma matriz para a soma
	double soma[mA.ligne][mA.colonne];

	//inicio do for i
	for(i=0;i<mA.ligne;i++){

		//inicio do for j
		for(j=0;j<mA.colonne;j++)

			//armazena o valor da soma na matriz de soma
			soma[i][j]=mA.geomatriz[i][j]+mB.geomatriz[i][j];
	}
	//printa uma linha de hifens
	puts("\n______________________________________________________");
	//inicio do for i
	for(i=0;i<mA.ligne;i++){
		//inicio do for j
   	for(j=0;j<mA.colonne;j++)
      	//printa o elemento [i][j] da matriz soma
      	printf("%.1lf  ", soma[i][j]);
      //printa uma quebra de linha
      printf("\n");
    }
}

//Função para multiplicar Matrizes
void GeoMultiplicaMatriz(matriz mA, matriz mB){
    //variaveis de controle do for
    int i,j, k;

    //cria uma matriz para o produto
    double prod[mA.ligne][mA.colonne];

    //inicio do for i
    for(i=0; i<mA.ligne; i++){

    	//inicio do for j
    	for(j=0; j<mB.colonne; j++){

    		//inicializa o valor de [i][j] como 0
    		prod[i][j] = 0;

    		//inicio do for k
    		for(k = 0; k<mB.ligne; k++)

    			//o elemento [i][j] da matriz produto recebe ele mesmo mais o produto das linhas pelas colunas
    			prod[i][j] +=  mA.geomatriz[i][j] * mB.geomatriz[i][j];
		}
	}
	//printa uma linha de hifens
	puts("\n___________________________________________________");

	//inicio do for i
	for(i=0;i<mA.ligne;i++){

		//inicio do for j
   	for(j=0;j<mB.colonne;j++)

   		//imprime o elemento [i][j] da matriz produto
      	printf("%.1lf  ", prod[i][j]);

      //imprime uma quebra de linha
      printf("\n");
    }
}

//Função para calcular determinante

//Calcula a Determinante de uma Matriz Quadrada
void determinante()
	{
	int m = 0;
  double **a = 0;
  int i = 0, j = 0, k = 0;
  double factor = 0;
  double temp = 0;
  int count = 0;
    	printf("\nDimensão da Matriz quadrada: ");
    	scanf("%d", &m);

    	//Função que aloca uma matriz
    	a = malloc(m * sizeof(double *));
    	for(i = 0; i < m; i++)
    		{
        		a[i] =  malloc(m * sizeof(double));
    		}

    	//Entra com o conteúdo da matriz
    	printf("\nEntre com o Conteudo da Matriz\n\n");
    	for(i = 0; i < m; i++)
    		{
        		for(j = 0; j < m; j++)
        			{
            			printf("A [%d][%d]=> ", i+1, j+1);
            			scanf("%lf", &a[i][j]);
        			}
    		}

    	//Função que mostra a matriz
    	printf("\nSua Matriz:\n\n");
    	for(i = 0; i < m; i++)
    		{
        		for(j = 0; j < m; j++)
        			{
            			printf("%8.3f ", a[i][j]);
        			}
        		printf("\n");
    		}

    	//Tranforma em triângulo para facilitar o calculo do determinante
    	for(i = 0; i < m - 1; i++)
    		{
        		if(a[i][i] == 0)
        			{
            			for(k = i; k < m; k++)
            				{
                				if(a[k][i] != 0)
                					{
                    					for(j = 0; j < m; j++)
                    						{
                        						temp = a[i][j];
                        						a[i][j] = a[k][j];
                        						a[k][j] = temp;
                    						}
                    					k = m;
                					}
            				}
            			count++;
        			}
        		if(a[i][i] != 0)
        			{
            			for(k = i + 1; k < m; k++)
            				{
                				factor = -1.0 * a[k][i] / a[i][i];
                				for(j = i; j < m; j++)
                					{
                    					a[k][j] = a[k][j] + (factor * a[i][j]);
                					}
            				}
        			}
    		}
    	temp = 1.0;

    	//impressão do determinate
    	for(i = 0; i < m; i++)
        temp *= a[i][i];
    	printf("\nO valor do Determinante é:\n\n");
    	if(count % 2 == 0)
        printf("%8.3f \n", temp);
    	else
        printf("%8.3f \n", -1.0 * temp);
	}

//Função para calcular transposta

void GeoTransposta(matriz m, matriz *t){

	//variaveis de controle do for
	int i,j;

	//inicializa o numero de linhas e colunas da matriz transposta
	t->ligne=m.colonne;
	t->colonne=m.ligne;

	//inicio do for i
	for(i=0;i<m.colonne;i++){

		//inicio do for j
		for(j=0;j<m.ligne;j++)

			//inicializa o elemento [i][j] da transposta como sendo igual ao elemento [j][i] da matriz original
			t->geomatriz[i][j]=m.geomatriz[j][i];
		}

	//printa uma linha de hifens
	puts("\n________________________________________________________");

	//inicio do for i
	for(i=0;i<m.colonne;i++){

		//inicio do for j
   	for(j=0;j<m.ligne;j++)

      	//imprime o elemento [i][j] da transposta
      	printf("%.1lf  ", t->geomatriz[i][j]);

      //imprime uma quebra de linha
   	printf("\n");
    }
}

//Função para verificar se a matriz é simétrica
void GeoMatrizSimetrica(matriz m, matriz t){
	   //variaveis de controle do for e uma variavel auxiliar inicializa como 0
	   int i, j, aux=0;

	   //testa se a matriz é quadrada
	if(m.ligne != m.colonne){

   	 //caso não seja, a matriz não é simetrica
   	 printf("\nMatriz nao e simetrica\n");
   }else{

   	//caso seja quadrada:
   	//inicio do for i
		for(i = 0; i<m.ligne; i++){
			//inicio do for j

			for(j = 0; j<m.colonne; j++){
				//se o elemento [i][j] da matriz for igual ao elemento [i][j] da sua transposta

				if(m.geomatriz[i][j]==t.geomatriz[i][j])
      			//caso seja, soma 1 na variavel auxiliar
      			aux++;
			}
		}
		//testa se a variavel auxiliar é igual ao produto de linhas x colunas da matriz
		if(aux==(m.ligne*m.ligne)){

			//imprime que é simétrica
			puts("\nA Matriz e simetrica");
		}else{

			//imprime que não é simétrica
			puts("\nA Matriz nao e simetrica");
		}
	}
}
