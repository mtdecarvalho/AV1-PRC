//2- Faça um programa que leia uma frase e informe se ela é palindrome
//   palindrome é uma frase que pode ser lida de traz para frente e de frente para traz, que ela eh igual.
//   ex: arara

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char frase1[100], frase2[100], temp, original[100], cont;
    int i, tam, k = 0;
    do
    {
        printf("Insira a%s frase/palavra a ser analisada: \n", cont == 's' || cont == 'S' ? " proxima" : "");
        scanf(" %[^\n]s", frase1); while((getchar()) != '\n'); tam = strlen(frase1); strcpy(original, frase1); 
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
        printf("\"%s\"%s eh palindrome.\n", original, strcmp(frase2,frase1) == 0 ? "" : " nao"); //substitior por if/else?
        printf("Deseja continuar? [s / n]\n"); scanf(" %c", &cont); while ((getchar()) != '\n');
    } while (cont == 's' || cont == 'S');
    return 0;
}
