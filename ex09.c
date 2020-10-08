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
    int N, i;
    double n[max], media = 0, ex[3], k;
    char j;
    
    do
    {
        printf("Insira os valores a serem analisados (min. 1, max. 100):\n"
                "\t(Para encerrar a leitura, insira 0)\n\n");
        for ( i = 0 ; i < 100 ; i++ )
        {
            while ( (scanf(" %lf", &n[i]) != 1) || n[0] == 0 )
            {
                printf("Nenhum valor valido foi inserido. Tente novamente: \n");
                limpa();
            } 
            if (n[i] == 0)  { i--; N = i; i = 99; }
        }
        ex[0] = n[0]; ex[1] = n[0];
        for (i = 0 ; i <= N ; i++)
        {
            if ( n[i] > ex[1] )
                ex[1] = n[i];
            if ( n[i] < ex[0] )
                ex[0] = n[i];
        }

        printf("Extremos: |%.2lf| e |%.2lf|\n", ex[0], ex[1]);
        for (i = 0 ; i <= N ; i++)
        {
            if ( n[i] > ex[0] && n[i] < ex[1] )
            {   media+=n[i]; k++; printf("%lf\n", media); }
        }
        media/=k;
        printf("A media dos valores sem seus extremos eh %.2lf.\n", media);
        printf("Deseja continuar? [s / n]\n"); scanf(" %c", &j); media = 0;
    }
    while (j == 's' || j == 'S');
    
    return 0;
}