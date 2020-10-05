////////////////////////////////////////////////
// 3- Faça um programa que leia uma frase e coloque a primeira letra de cada palavra em maiuscula e as 
//   demais letras em minuscula
//  asass123asdasd quero-quero.MARIA
//  Asass123Asdasd Quero-Quero.Maria
///////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    int i, tam, k;
    char frase[100];
    char * palavra;
    puts("Insira a frase a ser modificada:");
    do
    {
        k = 0; fgets(frase, 100 , stdin); frase[strlen(frase)-1] = '\0'; tam = strlen(frase);
        for (i = 0; i < tam ; i++)
            if (frase[i] >= 48 && frase[i] <= 57)
                k++;
        if (k == tam)
            puts("Por favor insira uma frase valida.");
    } while (k == strlen(frase));
    palavra = strtok(frase, " -");
    printf("Resultado: ");
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
    puts("");
    return 0;
}