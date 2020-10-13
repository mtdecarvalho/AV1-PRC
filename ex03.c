////////////////////////////////////////////////
// 3- Faça um programa que leia uma frase e coloque a primeira letra de cada palavra em maiuscula e as 
//   demais letras em minuscula
//  asass123asdasd quero-quero.MARIA
//  Asass123Asdasd Quero-Quero.Maria
///////////////////////////////////////////////

#include <stdio.h>
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
    char * palavra;
    
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
        
        palavra = strtok(frase, " -");
        printf("\nFrase modificada:\n\n");
        while (palavra != NULL)
        {
            for(i = 0; i < strlen(palavra) ; i++)
            {
                if (i == 0)
                {
                    if (palavra[i] >= 97 && palavra[i] <= 122)
                        palavra[i]-=32;
                }
                else if ( !isalpha(palavra[i-1]) )
                {
                    if (palavra[i] >= 97 && palavra[i] <= 122)
                        palavra[i]-=32;
                }
                else
                {
                    if (palavra[i] >= 65 && palavra[i] <= 90)
                        palavra[i]+=32;
                }
            }
            printf("%s ", palavra); palavra = strtok(NULL, " -");
        }
        printf("\n\nDeseja continuar? [s / n]\t"); scanf(" %c", &j); limpa();
    }
    while (j == 's' || j == 'S');
    
    return 0;
}