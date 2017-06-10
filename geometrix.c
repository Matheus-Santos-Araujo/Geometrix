/* ____________________________________________________
Equipe: MATHEUS SANTOS ARAÚJO, EDSON RODRIGO E FRANCISCO JOSÉ.
Universidade Estadual do Ceará.
Curso de Ciência da Computação do CCT.
Disciplina de Introdução a Ciência da computação com prof. Dr. Leonardo.
_____________________________________________________ */

#include "gtx.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
	matriz mA;
	matriz mB;
	matriz tA;
	matriz tB;
	vetor vA;
	vetor vB;

	char Esc[5], EscB[5], EscC[5];

	int Escolha = 0, EscolhaB = 0, EscolhaC = 0, num;

	double  esc;

	  puts("                B E M - V I N D O  A O  G E O M E T R I X\n");
	  puts("     Aqui você pode realizar diversas operações com vetores e matrizes.\n");
	do{
		puts("   [[__________________________MENU PRINCIPAL__________________________]]\n");
		puts("Escolha uma das alternativas abaixo:\n");
		puts("1 --> CALCULOS DE VETORES\n");
    puts("2 --> CALCULOS DE MATRIZES\n");
    puts("3 --> SAIR DO GEOMETRIX\n");
    printf("Entre com sua opcao de escolha: ");
		scanf("%s", Esc);
        printf("          _______________________________________________________\n\n");
        Escolha = atoi(Esc);


        switch(Escolha){
        	case 1:
        		do{
   puts("[[__________________________MENU DE VETORES__________________________]]\n");
   puts("Escolha uma das alternativas abaixo:\n" );
	 puts("1 --> Ler dois vetores\n");
	 puts("2 --> Somar dois vetores\n");
	 puts("3 --> Multiplicar um dos vetores por um escalar\n");
	 puts("4 --> Produto escalar entre dois vetores\n");
	 puts("5 --> Voltar para o menu anterior\n");
	 printf("Entre com sua opcao de escolha: ");
	 scanf("%s", EscB);
   puts("______________________________________________________\n");

        	    EscolhaB = atoi(EscB);


        			switch(EscolhaB){

        				case 1:
        					GeoLerVetor(&vA);
        					GeoLerVetor(&vB);
        					break;

        				case 2:
        					if(vA.n != vB.n)
        						puts("\nComando invalido! Os vetores nao possuem a mesma dimensao");
        					else
        						GeoSomarVetor(vA, vB);
        					break;


        				case 3:
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


        				case 4:
        					if(vA.n != vB.n)
        						puts("Comando invalido! Os vetores nao possuem a mesma dimensao!");
        					else
        						GeoProdutoEscalar(vA, vB);
        					break;


        				case 5:
        					puts("\nRetornando ao menu principal do Geometrix");
        					break;


        				default:
        					puts("\nComando invalido!");
        					break;
					}
				}while(EscolhaB != 5);
        		break;


        	case 2:
        		do{
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
              scanf("%s",EscC);
        			puts("_______________________________________________________\n");

        			EscolhaC=atoi(EscC);

    				  switch(EscolhaC){

    					case 1:
    						printf("\nDigite a Matriz 1:\n");
    						LerMatrizes(&mA);
    						printf("\nDigite a Matriz 2:\n \n");
							  LerMatrizes(&mB);
							  printf("\nMatriz 1:\n ");
    						ImprimeMatriz(mA);
    						printf("\nMatriz 2:\n ");
    						ImprimeMatriz(mB);
    						break;

    					case 2:
    						if(mA.ligne != mB.ligne || mA.colonne != mB.colonne)
        						puts("\nComando inválido! As matrizes nao possuem a mesma dimensao");
        					else
        						GeoSomarMatrizes(mA, mB);
    						break;


    					case 3:
    						if(mB.ligne != mA.colonne)
    							puts("\nComando inválido! Nao e possivel realizar a multiplicacao");
        					else
        						GeoMultiplicaMatriz(mA, mB);
						    break;


    					case 4:
    						printf("\nDigite a matriz que deseja utilizar: ");
    						scanf("%d", &num);
    						if(num!=1 && num!=2){
    							puts("\nOpcao Invalida");
    							break;
							}else if(num==1)
								GeoTransposta(mA, &tA);
							else
    							GeoTransposta(mB, &tB);
    						break;


    					case 5:
    						printf("\nDigite a matriz que deseja utilizar: ");
    						scanf("%d", &num);
    						if(num!=1 && num!=2){
    							printf("\nOpcao Invalida\n");
    							break;
							}else if(num==1){
								if(mA.ligne == mA.colonne)
									determinante(mA);
								else{
									puts("\nComando inválido! Nao e possivel calcular o determinante");
									break;
								}
							}else{
								if(mB.ligne == mB.colonne)
									determinante(mB);
								else{
									puts("\nComando inválido! Nao e possivel calcular o determinante");
									break;
								}
							}
    						break;


    					case 6:
    						printf("\nQual matriz voce deseja saber se e simetrica: ");
                                scanf("%d", &num);
                                if( num != 1 && num != 2){
                                	puts("\nDigite uma opcao valida");
                                	break;
								}else if(num == 1){
                                  GeoTransposta(mA,&tA);
                                    GeoMatrizSimetrica(mA,tA);
                                }else{
                                    GeoTransposta(mB,&tB);
                                    GeoMatrizSimetrica(mB,tB);

                                }
    			}
    		}while(EscolhaC !=7);
        		break;


        	case 3:
        		puts("\nGEOMETRIX, um oferecimento UECE, obrigado por utilizar nosso sistema volte sempre!");
        		break;
        	default:
        		puts("\nOpcao Invalida");
        		break;
		}

	}while(Escolha != 3);
}

//Funções com Matrizes
//Functions with Matrices

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
//Function to sum Matrices
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

void determinante(matriz m){

	//caso o numero de linhas e colunas seja 1, imprime o único elemento
	if(m.ligne==1)
		printf("\nDeterminante da matriz [%d][%d]: %.1f", m.ligne,m.colonne, m.geomatriz[0][0]);

	//caso o numero de linhas e colunas seja 2, imprime o determinante
	else if(m.ligne==2)
		printf("\nDeterminante da matriz [%d][%d]: %.1f", m.ligne,m.colonne, m.geomatriz[0][0]*m.geomatriz[1][1]-(m.geomatriz[0][1]*m.geomatriz[1][0]));

	//caso o numero de linhas e colunas seja 3, imprime o determinante
	else if(m.ligne==3){
		double determinante;
		determinante=(m.geomatriz[2][0]*m.geomatriz[0][1]*m.geomatriz[1][2]+m.geomatriz[0][0]*m.geomatriz[1][1]*m.geomatriz[2][2]+m.geomatriz[1][0]*m.geomatriz[2][1]*m.geomatriz[0][2]-m.geomatriz[2][2]*m.geomatriz[0][1]*m.geomatriz[1][0]-m.geomatriz[0][2]*m.geomatriz[1][1]*m.geomatriz[2][0]-m.geomatriz[1][2]*m.geomatriz[2][1]*m.geomatriz[0][0]);
		printf("\nDeterminante da matriz [%d][%d]: %.1lf", m.ligne, m.colonne,determinante);
	}else{
		puts("\nNao e possivel calcular o determinante da matriz");
	}
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

//Funções com Vetores

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
