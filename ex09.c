//9- Faça um programa para ler n numeros reais (no maximo 100), e mostrar a medias dos valores sem os valores extremos.
//   a leitura dos numeros será encerrada quando o usuário digitar 0 ou chegarmos a 100. 
//   (obs: mas ele pode digitar numeros negativos e positivos)
//   ex: 1 3 7 1 4 7 3 1 4 0
//    extremos: 1 e 7  (1 é menor valor e 7 é o maior valor)
//    media = (3 + 4 + 3 + 4)/4 = 14/4 = 3.5

#include <stdio.h>

#define max 100

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    int N, i, k;
    double n[max], media = 0, temp;
    char j;
    
    do
    {
        printf("Insira os valores (1 ate 100) a serem analisados:\n"
                "(Para encerrar a leitura, insira 0)\n");
        for ( i = 0 ; i < 100 ; i++ )
        {
            while ( (scanf(" %lf", &n[i]) != 1) || n[0] == 0)   {    printf("Valor invalido. Tente novamente: "); limpa();  } 
            if (n[i] == 0)  { i--; N = i; break; }
        }
        for (i = 0 ; i <= N ; i++)
        {
            for (k = 0; k <= N ; k++)
                if (n[i] < n[k])
                {
                    temp = n[k];    n[k] = n[i];    n[i] = temp;
                }
        }
        k = 0; printf("Extremos: |%lf| e |%lf|\n", n[0], n[N]);
        for (i = 0 ; i <= N ; i++)
        {
            if ( n[i] > n[0] && n[i] < n[N] )
            {   media+=n[i]; k++;   } //printf("%lf\n", media); }
        }
        media/=k;
        printf("A media dos valores sem seus extremos eh %.1lf.\n", media);
        printf("Deseja continuar? [s / n]\n"); scanf(" %c", &j);
    }
    while (j == 's' || j == 'S');
    
    return 0;
}