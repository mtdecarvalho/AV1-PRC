//2- Faça um programa que leia uma frase e informe se ela é palindrome
//   palindrome é uma frase que pode ser lida de traz para frente e de frente para traz, que ela eh igual.
//   ex: arara

#include <stdio.h>
#include <string.h>

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    char frase1[100], frase2[100], temp, original[100], cont;
    int i, tam, k = 0;
    do
    {
        printf("Insira a%s frase/palavra a ser analisada: ", cont == 's' || cont == 'S' ? " proxima" : "");
        scanf(" %[^\n]s", frase1);
        while ( strlen(frase1) <= 1 )
        {
            limpa(); printf("\n\tInsira uma frase/palavra valida.\n"); scanf(" %[^\n]s", frase1);
        }
        limpa(); tam = strlen(frase1); strcpy(original, frase1); 
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
