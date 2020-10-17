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

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    int i, tam, k;
    char frase[100], j;
    
    do
    {
        limpartela(); printf("\nInsira a frase a ser modificada:\n\n");
        
        do
        {
            k = 0; fgets(frase, 100 , stdin); frase[strlen(frase)-1] = '\0'; tam = strlen(frase);
            for (i = 0; i < tam ; i++)
                if (!isalpha(frase[i]))
                    k++;
            if (k == tam)
            {
                puts("Por favor insira uma frase valida.");
            }
        }
        while (k == strlen(frase));
        
        printf("\nFrase modificada:\n\n");
        for(i = 0; i < strlen(frase) ; i++)
        {
            if (i == 0)
            {
                if (frase[i] >= 97 && frase[i] <= 122)
                    frase[i]-=32;
            }
            else if ( !isalpha(frase[i-1]) )
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