//2- Faça um programa que leia uma frase e informe se ela é palindrome
//   palindrome é uma frase que pode ser lida de traz para frente e de frente para traz, que ela eh igual.
//   ex: arara

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

int ehvalido (char a[])
{
    int i, tam, k = 0;
    tam = strlen(a);
    for (i = 0 ; i < tam; i++)
    {
        if ( isalpha(a[i]) != 0 )
            k++;
        else
            if ( isspace(a[i]) != 0 )
                k++;
    }
    if (k == tam-1 || tam <= 1)
        return 0;
    else
        return 1;
}

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    char frase1[tammax], frase2[tammax], temp, original[tammax], cont;
    int i, tam, k = 0;
    do
    {
        limpartela();
        printf("Insira a%s frase/palavra a ser analisada: ", cont == 's' || cont == 'S' ? " proxima" : "");
        fgets(frase1, tammax, stdin); tam = strlen(frase1); frase1[tam-1] = '\0';
        while ( ehvalido(frase1) != 1 )
        {
            printf("\n\tInsira uma frase/palavra valida.\n"); fgets(frase1, tammax, stdin); tam = strlen(frase1); frase1[tam-1] = '\0';
        }
        if (tam == tammax-1)
            limpa();
        
        strcpy(original, frase1); 
        for (i = 0; i < strlen(frase1) ; i++)
        {
            if (frase1[i] >= 65 && frase1[i] <= 90)
                { frase1[i] += 32; i--; }
        }
        strcpy(frase2, frase1);
        tam = strlen(frase2); 
        for (i = 0, k = tam-1 ; i < tam/2 ; i++, k--)
        {
            temp = frase2[i]; frase2[i] = frase2[k]; frase2[k] = temp;
        }
        printf("\n\t\"%s\"%s eh palindrome.\n", original, strcmp(frase2,frase1) == 0 ? "" : " nao"); //substitior por if/else?
        printf("\nDeseja continuar? [s / n]\t"); scanf(" %c", &cont); limpa();
    }
    while (cont == 's' || cont == 'S');
    
    return 0;
}
