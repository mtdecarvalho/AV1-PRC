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

void pausartela()
{
    #ifdef __unix__
        system("read -r -p \"Pressione qualquer tecla...\" key");
    #elif _WIN32
        system("pause");
    #elif _WIN64
        system("pause");
    #endif
}

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
            "\t      JOGO DA FORCA\n"
            "\t            _______\n"
            "\t            |     |\n"
            "\t            O     |\n"
            "\t           /|\\    |\n"
            "\t           / \\    |\n"
            "\t      ____________|_\n"
            "\t     /             /|\n "
            "\t    /_____________/ /\n"
            "\t    |_____________|/\n\n"
            "\t\t#MENU#\n"
            "\t# 1 # Iniciar o jogo\n"
            "\t# 2 # Mostrar regras\n"
            "\t# 0 # Encerrar programa\n");
}

void regras()
{
    limpartela();
    printf(
    "\t# Regras #\n\n"
    "# 1 # A forca nao faz distincao entre letras maiusculas e minusculas.\n"
    "# 2 # A frase secreta escondera apenas letras de A ate Z (acentos nao incluidos). Qualquer outro caractere sera revelado.\n"
    "# 3 # Apenas uma letra eh aceita por chute. No caso de mais de uma letra ser informada, apenas a primeira sera considerada.\n\n");
    pausartela();
}
 
void forca( int vida )
{
    switch (vida)
    {
    case 6:
    printf ("            _______\n"
            "            |     |\n"
            "                  |\n"
            "                  |\n"
            "                  |\n"
            "      ____________|_\n"
            "     /             /|\t______ O\n"
            "    /_____________/ /\t_____ </V\n"
            "    |_____________|/\t______V\\ \n\n");
            break;
    case 5:
    printf ("\t            _______\n"
            "\t            |     |\n"
            "\t                  |\n"
            "\t                  |\n"
            "\t                  |\n"
            "\t      ____________|_\n"
            "\t     /             /|\n "
            "\t    /_____________/ /\n"
            "\t    |_____________|/\n\n"
            ); break;
    case 4:
    printf ("\t            _______\n"
            "\t            |     |\n"
            "\t            O     |\n"
            "\t                  |\n"
            "\t                  |\n"
            "\t      ____________|_\n"
            "\t     /             /|\n "
            "\t    /_____________/ /\n"
            "\t    |_____________|/\n\n"); break;
    case 3:
    printf ("\t            _______\n"
            "\t            |     |\n"
            "\t            O     |\n"
            "\t            |     |\n"
            "\t                  |\n"
            "\t      ____________|_\n"
            "\t     /             /|\n "
            "\t    /_____________/ /\n"
            "\t    |_____________|/\n\n"); break;
    case 2:
    printf ("\t            _______\n"
            "\t            |     |\n"
            "\t            O     |\n"
            "\t           /|     |\n"
            "\t                  |\n"
            "\t      ____________|_\n"
            "\t     /             /|\n "
            "\t    /_____________/ /\n"
            "\t    |_____________|/\n\n"); break;
    case 1:
    printf ("\t            _______\n"
            "\t            |     |\n"
            "\t            O     |\n"
            "\t           /|\\    |\n"
            "\t                  |\n"
            "\t      ____________|_\n"
            "\t     /             /|\n "
            "\t    /_____________/ /\n"
            "\t    |_____________|/\n\n"); break;
    case 0:
    printf ("\t            _______\n"
            "\t            |     |\n"
            "\t            O     |\n"
            "\t           /|\\    |\n"
            "\t           / \\    |\n"
            "\t      ____________|_\n"
            "\t     /             /|\n "
            "\t    /_____________/ /\n"
            "\t    |_____________|/\n\n"); break;
    }
}

int main ()
{
    char secreta[tammax], secreta2[tammax], chutes[tammax], input, j, cont;
    int vida = 5, i = 0, perdeu = 1, k = 0;

    while (1) 
    {
        k = 0; vida = 5; memset(chutes, 0, strlen(chutes));

        do
        {
            menu();
            scanf(" %c", &j); limpa();
            switch (j)
            {
                case '2': regras(); break;
                case '1': break;
                case '0': limpartela(); return 0;
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

        limpartela();

        do
        {
            printf("\tVidas: %d\tChutes: %s\n\n", vida, chutes);
            forca(vida);
            printf("\t%s\n", secreta2);
            printf("\n\tInsira a letra: "); scanf(" %c", &input);
            limpa();
            limpartela();
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
        
        printf("\tVidas: %d\tChutes: %s\n\n", vida, chutes);
        forca(vida == 0 ? 0 : 6);
        printf("\t%s\n", secreta2);
        switch (vida)
        {
            case 0: printf("\n\t\tGame Over."); break;
            default:
            printf("\n\t\tVitoria!\n");
            break;
        }
        printf("\nFim de jogo.\n"); pausartela();
    }
}