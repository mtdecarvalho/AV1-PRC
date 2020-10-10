//1- faça um programa para ler um numero inteiro positivo e informe se ele é primo
//   assumimos que para este exercicio que o numero 1 não é primo.
//   todos os outros numeros primos são numeros que so tem dois divisores 1 e ele mesmo.

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    int res, multiplo = 0, i, tam;
    char s[1000], k, j;
    
    do
    {
        printf("Insira o numero positivo e inteiro a ser analisado: "); 
        while (scanf(" %d", &res) != 1 || scanf(".%c", &j) == 1 || res < 0)
        {
            printf("\tO valor inserido eh invalido!\n"
                    "Insira o numero positivo e inteiro a ser analisado: "); limpa();
        }
        limpa();
        for (i = 1; i<=res && multiplo<1; i++)
            if (res % i == 0 && i > 1 && i < res)
                multiplo+=1;

        if (multiplo > 0 || res <= 1)
            printf("\n\tO numero %d nao eh primo.\n", res);
        else
            printf("\n\tO numero %d eh primo.\n", res);
    
        printf("\nDeseja continuar? [s / n]\t"); scanf(" %c", &k); limpa();
    }
    while (k == 's' || k == 'S');
    
    return 0;
}

//int ehnum ( char a[] )
//{
//    int i;
//    for (i = 0 ; i < strlen(a) ; i++)
//        if ( !isdigit(a[i]) )
//            return 0;
//        else if (a[0] == '0' || a[0] == '\n')
//            return 0;
//    return 1;
//}
        
        //scanf("%s", s);
        //while ( ehnum(s) != 1 )
        //{
        //    printf("O valor inserido nao eh valido. Insira um numero valido: "); scanf("%s", s);
        //}
        //res = atoi(s);