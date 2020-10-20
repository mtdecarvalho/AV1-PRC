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

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    char frase1[tammax], frase2[tammax], temp, original[tammax], cont;
    int i, tam, k = 0, val;
    do
    {
        limpartela();

        do
        {
            if (analise(frase1) == 2) limpartela();
            printf("Insira a%s frase/palavra a ser analisada: ", cont == 's' || cont == 'S' ? " proxima" : "");
            fgets(frase1, tammax, stdin);
            if (strlen(frase1) == tammax-1) 
                limpa();
        }
        while( analise(frase1) != 1 );
        
        //frase1[strlen(frase1)-1] = '\0';
        tam = strlen(frase1);

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
