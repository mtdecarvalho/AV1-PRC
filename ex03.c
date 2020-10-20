////////////////////////////////////////////////
// 3- Faça um programa que leia uma frase e coloque a primeira letra de cada palavra em maiuscula e as 
//   demais letras em minuscula
//  asass123asdasd quero-quero.MARIA
//  Asass123Asdasd Quero-Quero.Maria
///////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define tammax 100

void limpartela()
{
    #ifdef __unix__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #endif
}

void limpa()
{
    while ((getchar()) != '\n');
}

int analise(char a[])
{
    int i, k = 0;
    if (a[strlen(a)-1] == '\n')
        a[strlen(a)-1] = '\0';
    for (i=0;a[i] != '\0';i++)
        if (isspace(a[i]))
            k++;
    if ( k == strlen(a) )
        return 2;
    for (i=0;i<strlen(a);i++)
    {
        if ( !isalpha(a[i]) && !isspace(a[i]) && !ispunct(a[i]) && !isdigit(a[i]) )
        {    limpartela(); printf("Frase invalida! \"%s\" possui um ou mais caracteres invalidos.\n\n", a); return 0;   }
    }
    return 1;
}

int main ()
{
    int i, tam, k;
    char frase[tammax], j;
    
    do
    {
        limpartela();
        
        do
        {
            if (analise(frase) == 2) limpartela();
            printf("Insira a frase a ser modificada:\n\n");
            fgets(frase, tammax , stdin); 
            if (strlen(frase) == tammax-1) 
                limpa();
        }
        while ( analise(frase) != 1 );
        tam = strlen(frase);
        printf("\nFrase modificada:\n\n");
        for(i = 0; frase[i] != '\0' ; i++)
        {
            //if (i == 0)
            //{
            //    if (frase[i] >= 97 && frase[i] <= 122)
            //        frase[i]-=32;
            //}
            //else
            if ( !isalpha(frase[i-1]) || i == 0 )
            {
                if (frase[i] >= 97 && frase[i] <= 122)
                    frase[i]-=32;
            }
            else
            {
                if (frase[i] >= 65 && frase[i] <= 90)
                    frase[i]+=32;
            }
        }
        printf("%s\n", frase);
        
        printf("\nDeseja continuar? [s / n]\t"); scanf(" %c", &j); limpa();
    }
    while (j == 's' || j == 'S');
    
    return 0;
}