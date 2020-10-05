//2- Faça um programa que leia uma frase e informe se ela é palindrome
//   palindrome é uma frase que pode ser lida de traz para frente e de frente para traz, que ela eh igual.
//   ex: arara
//Socorram-me, subi no onibus em Marrocos!
//Socorram-me, subi no ônibus em Marrocos!
//Ai, Lima falou: “Ola, familia”. não funciona pelas aspas
//Ai, Lima falou: Ola, familia. funciona.
//consertar suporte a aspas?

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char frase1[100], frase2[100], temp, original[100];
    int i, tam, k = 0;
    printf("Insira a frase/palavra a ser analisada: \n");
    while (fgets(frase1, 100, stdin) != NULL) //enquanto fgets detectar uma frase valida
    {
    frase1[strlen(frase1)-1] = '\0'; tam = strlen(frase1); strcpy(original, frase1); //retirando o \0 e copiando a frase para outra variavel.
    for (i = 0; i < strlen(frase1) ; i++) //loop para limpar a frase (retirar pontuacoes e transformar maiusculas em minusculas equivalentes)
    {
        if (frase1[i] >= 65 && frase1[i] <= 90)
            { frase1[i] += 32; i--; }
        //else if ( isspace(frase1[i]) )
        //{
        //    k = i;
        //    while (k != tam)
        //    {
        //        frase1[k] = frase1[k+1];
        //        k++;
        //    }
        //    i--;
        //}
        else if ( ispunct(frase1[i]) )
        {
            k = i;
            while (k != tam)
            {
                frase1[k] = frase1[k+1];
                k++;
            }
            i--;
        }
        //else if (frase1[i] == '"')
        //{
        //    k = i;
        //    while (k != tam)
        //    {
        //        frase1[k] = frase1[k+1];
        //        k++;
        //    }
        //    i--;
        //}
    }
    puts(frase1);
    strcpy(frase2, frase1); // copiando a frase para comparacao
    tam = strlen(frase2); 
    for (i = 0, k = tam-1 ; i < tam/2 ; i++, k--)
    {
        temp = frase2[i]; frase2[i] = frase2[k]; frase2[k] = temp; //invertendo a segunda frase para comparacao
    }
    if (strcmp(frase1, frase2) == 0)
        printf("\"%s\" eh palindrome.\n", original);
    else
        printf("\"%s\" nao eh palindrome.\n", original);
    printf("Insira a frase/palavra a ser analisada: \n");
    }
    return 0;
}
