#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void distancia();
void matriz();

double distanciar2();
double distanciar3();

void somaM();
void multM();
void inversao();

void transposta();



int main()
{
    int op;
    printf("\n===================================================================\n");
    printf("                     CALCULADORA Algebra Linear\n");
    printf("===================================================================\n");

    printf("\n1.Calcular a Distancia Entre pontos\n2.Operacoes com Matrizes\n");
    printf("\nQual operacao voce gostaria de fazer? ");
    scanf("%d", &op);
    system("cls");

    switch (op){
        case 1: distancia();break;
        case 2: matriz();break;
        default: break;
    }
    return 0;
}

void distancia()
{
    int op;
    double resp;
    printf("\nEscolha entre:\n\n1.Distancia no R2\n2.Distancia no R3\n");
    printf("\nOpcao: ");
    scanf("%d", &op);
    system("cls");

    switch (op){
        case 1: resp = distanciar2(); break;
        case 2: resp = distanciar3(); break;
    }
    printf("%.2lf", resp);
    return;
}

void matriz()
{
    int op;
    printf("\nEscolha entre:\n\n1.Soma de Matrizes\n2.Multiplicacao de Matrizes\n3.Inversao de Matrizes\n4.Transposta de Matrizes\n");
    printf("\nOpcao: ");
    scanf("%d", &op);
    system("cls");

    switch (op){
        case 1: somaM(); break;
        case 2: multM(); break;
        case 3: inversao();break;
        case 4: transposta(); break;
    }
    return;
}

double distanciar2()
{
    double xa, xb, ya, yb;
    printf("\nDigite as duas coordeadas do ponto A: ");
    scanf("%lf%lf", &xa, &ya);
    printf("\nDigite as duas coordeadas do ponto B: ");
    scanf("%lf%lf", &xb, &yb);

    printf("\nA distancia de A ate B e: \n");
    return sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
}

double distanciar3()
{
    double xa, xb, ya, yb, za, zb ;
    printf("\nDigite as tres coordeadas do ponto A: ");
    scanf("%lf%lf%lf", &xa, &ya, &za);
    printf("\nDigite as tres coordeadas do ponto B: ");
    scanf("%lf%lf%lf", &xb, &yb, &zb);

    printf("\nA distancia de A ate B e: \n");
    return sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya)+ (zb-za)*(zb-za));
}

void somaM()
{
   int m1[2][2], m2[2][2], soma[2][2];

   printf("\nMatriz 2 x 2 !\n");
    printf("\nDigite em linha !");
   printf("\nDigite os elementos da Primeira Matriz: ");
   for(int i = 0; i < 2; i ++)
   {
       for(int j = 0; j < 2; j ++)
       {
           scanf("%d", &m1[i][j]);
       }
   }
   printf("\nDigite em linha !");
   printf("\nDigite os elementos da Segunda Matriz: ");
   for(int i = 0; i < 2; i ++)
   {
       for(int j = 0; j < 2; j ++)
       {
           scanf("%d", &m2[i][j]);
       }
   }
   printf("\nA matriz Soma e: \n\n");
   for(int i = 0; i < 2; i ++)
   {
       for(int j = 0; j < 2; j ++)
       {
           soma[i][j] = m1[i][j] + m2[i][j];
           printf("%d ", soma[i][j]);
       }
       printf("\n");
   }
}

void multM()
{
    int matrizA[2][2], matrizB[2][2], matrizC[2][2], aux = 0;

    printf("\nMatriz 2 x 2 !\n");
    printf("\nDigite em linha !");
    printf("\nDigite os elementos da Primeira Matriz: ");
   for(int i = 0; i < 2; i ++)
   {
       for(int j = 0; j < 2; j ++)
       {
           scanf("%d", &matrizA[i][j]);
       }
   }
   printf("\nDigite em linha !");
   printf("\nDigite os elementos da Segunda Matriz: ");
   for(int i = 0; i < 2; i ++)
   {
       for(int j = 0; j < 2; j ++)
       {
           scanf("%d", &matrizB[i][j]);
       }
   }

   for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {

			matrizC[i][j] = 0;
			for(int x = 0; x < 2; x++) {
				aux +=  matrizA[i][x] * matrizB[x][j];
			}

			matrizC[i][j] = aux;
			aux = 0;
		}
	}

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			printf("%d ", matrizC[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

}

void transposta(){
    int matrizA[3][3];

    printf("\nMatriz 3 x 3 !\n");
    printf("\nDigite em linha !");
    printf("\nDigite os elementos da Matriz A: ");
   for(int i = 0; i < 3; i ++)
   {
       for(int j = 0; j < 3; j ++)
       {
           scanf("%d", &matrizA[i][j]);
       }
   }

   printf("\nTransposta de A e:\n\n");
   for(int i = 0; i < 3; i ++)
   {
       for(int j = 0; j < 3; j ++)
       {
           printf("%d", &matrizA[j][i]);
       }
   }
}

void inversao(){
    double matrizA[2][2], matrizB[2][2], det = 0, aux = 0;

    printf("\nMatriz 2 x 2 !\n");
    printf("\nDigite em linha !");
    printf("\nDigite os elementos da Matriz A: ");
   for(int i = 0; i < 2; i ++)
   {
       for(int j = 0; j < 2; j ++)
       {
           scanf("%lf", &matrizA[i][j]);
       }
   }

   det = (matrizA[0][0] * matrizA[1][1]) - (matrizA[0][1] * matrizA[1][0]);
   printf("%lf\n",det);

   for(int i = 0; i < 2; i ++)
   {
       for(int j = 0; j < 2; j ++)
       {
           matrizB[i][j] = matrizA[i][j] / det;
       }
   }

   matrizB[0][1] *= -1;
   matrizB[1][0] *= -1;

   aux = matrizB[0][0];
   matrizB[0][0] = matrizB[1][1];
   matrizB[1][1] = aux;

   printf("\nA matriz inversa de A e: \n\n");

   for(int i = 0; i < 2; i ++)
   {
       for(int j = 0; j < 2; j ++)
       {
           printf("%.1lf ", matrizB[i][j]);
       }
       printf("\n");
   }
}

