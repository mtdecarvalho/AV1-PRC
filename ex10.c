//10- Faça o jogo da Forca. 
//    inicialmente o programa deve ler um frase secreta, limpar a tela e iniciar o jogo. 
//    Na tela devem aparacer: As letras chutas, a Frase secreta com _ nas letras nao chutadas, e a qtd de vida, que inicialmente é 5.
//    apos 5 erros o jogador perde.
//    obs: o usuario so vai chutar letras de A-Z, entao se na frase tivermos qualquer caracter diferente este ja aparece revelado.
//         e a Forca nao faz distinção de maiuscula e minuscula

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define tammax 100

int ehvalido ( char a[] )
{
    int i = 0, k = 0;
    for (i = 0 ; i < strlen(a) ; i++)
        if ( !isalpha(a[i]) )
            k++;
    if ( k == strlen(a) )
        return 0;
    else
        return 1;
}

void limpa()
{
    while ((getchar()) != '\n');
}

void menu()
{
    limpartela();
    printf(
            "\t###############################\n"
            "\t# Bem vindo ao jogo da forca! #\n"
            "\t###############################\n"
            "\t# 1 # Iniciar o jogo          #\n"
            "\t# 2 # Mostrar regras          #\n"
            "\t# 0 # Encerrar programa       #\n"
            "\t###############################\n");
}

void regras()
{
    limpartela();
    printf(
    "\t                                                   # Regras #\n"
    "\t#############################################################################################################################\n"
    "\t# 1 # A forca nao faz distincao entre letras maiusculas e minusculas.                                                       #\n"
    "\t# 2 # A frase secreta escondera apenas letras de A ate Z. Qualquer outro caractere sera revelado.                           #\n"
    "\t# 3 # Apenas uma letra eh aceita por chute. No caso de mais de uma letra ser informada, apenas a primeira sera considerada. #\n"
    "\t#############################################################################################################################\n");
    pausartela();
}

void limpartela()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
}

void pausartela()
{
    #ifdef __linux__
        system("read -n1 -r -p \"Pressione qualquer tecla...\" key");
    #elif _WIN32
        system("pause");
    #endif
}

int main ()
{
    char secreta[tammax], secreta2[tammax], chutes[tammax], input, j, cont;
    int vida = 5, i = 0, perdeu = 1, k = 0;

    while (1) 
    {
        k = 0; vida = 5;

        do
        {
            menu();
            scanf(" %c", &j); limpa();
            switch (j)
            {
                case '2': regras(); break;
                case '1': break;
                case '0': limpartela(); return 0; // Retirar?
            }
        }
        while (j != '1');
        limpartela();

        printf("Insira a frase secreta: "); scanf(" %[^\n]s", secreta); limpa();
        while ( ehvalido(secreta) != 1)
            {   printf("Frase invalida. Tente novamente: "); scanf(" %[^\n]s", secreta); limpa(); }
        for (i = 0 ; i < strlen(secreta) ; i++)
        {
            if ( secreta[i] >= 97 && secreta[i] <= 122 )
                secreta[i] -= 32;
        }   strcpy(secreta2, secreta);
        for (i = 0 ; i < strlen(secreta2) ; i ++)
        {
            if (secreta2[i] >= 65 && secreta2[i] <= 90 || secreta2[i] >= 97 && secreta2[i] <= 122)
                secreta2[i] = '_';
        }

        limpartela(); //limpar tela. melhorar talvez?

        do
        {
            printf("\nVidas: %d\tChutes: %s\n\n", vida, chutes);
            printf("\t%s\n", secreta2);
            printf("\nInsira a letra:\n"); scanf(" %c", &input);
            limpa();
            limpartela(); //limpar tela. melhorar talvez?
            if (input >= 97 && input <= 122)
                input-=32;
            chutes[k] = input;
            for (i = 0 ; i < strlen(secreta2) ; i++)
            {
                if ( input == secreta[i] && input != secreta2[i] )
                {    secreta2[i] = input; perdeu = 0;   }
            }
            if (perdeu == 1)
                vida-=1;
            perdeu = 1; k++;
        }
        while (vida > 0 && strcmp(secreta2, secreta) != 0);
        
        printf("\nVidas: %d\tChutes: %s\n\n", vida, chutes);
        printf("\t%s\n", secreta2);
        memset(chutes, 0, sizeof chutes);
        switch (vida)
        {
            case 0: puts("\nVoce perdeu."); break;
            default: puts("\nVoce ganhou!"); break;
        }
        printf("\nFim de jogo.\n"); pausartela();
    }
    //return 0;
}