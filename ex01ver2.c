//1- faça um programa para ler um numero inteiro positivo e informe se ele é primo
//   assumimos que para este exercicio que o numero 1 não é primo.
//   todos os outros numeros primos são numeros que so tem dois divisores 1 e ele mesmo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    unsigned long int res, multiplo = 0, i, tam;
    char s[1000], k;
    char * pont;
    do
    {
        printf("Insira o numero positivo e inteiro a ser analisado: "); 
        fgets(s, sizeof(s), stdin); s[strlen(s)-1] = '\0'; tam = strlen(s);
        for (i = 0 ; i < tam ; i++) // checa integridade da string
        {
            if (strtoul (s, &pont, 10) == 0)
                while (strtoul (s, &pont, 10) == 0)
                {    printf("%s nao eh um valor valido. Insira um numero positivo e inteiro: 1 ", s); fgets(s, sizeof(s), stdin); s[strlen(s)-1] = '\0'; tam = strlen(s); i = 0;}
            if (s[i] == '.' || s[i] == ',')
                //while (s[i] == '.' || s[i] == ',')
                {    printf("%s nao eh um valor valido. Insira um numero positivo e inteiro: 2 ", s); fgets(s, sizeof(s), stdin); s[strlen(s)-1] = '\0'; tam = strlen(s); i = 0; }
            if (s[i] == '-')
                while(s[i] == '-')
                {    printf("%s nao eh um valor valido. Insira um numero positivo e inteiro: 3 ", s); fgets(s, sizeof(s), stdin); s[strlen(s)-1] = '\0'; tam = strlen(s); i = 0; }
            if (s[i] == '0')
                {    printf("%s nao eh um valor valido. Insira um numero positivo e inteiro: 4 ", s); fgets(s, sizeof(s), stdin); s[strlen(s)-1] = '\0'; tam = strlen(s); i = 0; }
        }
        // ABAIXO FICA A FORMA ANTIGA DE VERIFICAR INTEGRIDADE DA STRING. CASO NECESSARIO VOLTAR
        //while (strtoul (s, &pont, 10) == 0 || s[0] == '-') // enquanto a string for invalida ler novamente
       // {
         //   for (i = 0 ; i < tam ; i++) // checa se a string e float (tem ponto) ou int
        //        if(s[i] == '.')
        //        {    printf("%s eh um numero invalido. Insira um numero positivo e inteiro: ", s); fgets(s, sizeof(s), stdin); s[strlen(s)-1] = '\0'; i = 0;}
        //    if (s[0] == '-')
        //    {    printf("%s eh um numero invalido. Insira um numero positivo e inteiro: ", s); fgets(s, sizeof(s), stdin); s[strlen(s)-1] = '\0';}
         //   else
         //   {    printf("%s nao eh um valor valido. Insira um numero positivo e inteiro: ", s); fgets(s, sizeof(s), stdin); s[strlen(s)-1] = '\0';}
        //}
        res = strtoul (s, &pont, 10); // transforma string validada em long unsigned int
        for (i = 1; i<=res && multiplo<1; i++) // checa se existem multiplos alem de 1 e ele mesmo
            if (res % i == 0 && i > 1 && i < res)
                multiplo+=1;
        if (multiplo > 0 || res <= 1) // se tiver algum multiplo ou for o numero 1
        {
            printf("O numero %lu nao eh primo.\n", res);
        }
        else //caso não tenha
            printf("O numero %lu eh primo.\n", res);
        multiplo = 0; //reseta o contador de multiplos
        printf("Deseja continuar? [s / n] "); scanf("%c", &k); getchar(); //checa condicao de continuar e consome o \n no buffer
    } while (k == 's' || k == 'S');
    return 0;
}