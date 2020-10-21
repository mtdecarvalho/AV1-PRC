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
    int i = 0, k = 0, tam = strlen(a);
    for (i = 0 ; i < tam ; i++)
        if ( !isalpha(a[i]) )
            k++;
    if ( k == tam )
        return 0;
    else
        return 1;
}

void limpa()
{
    while ((getchar()) != '\n');
}

int menu()
{
    int a;
    limpartela();
    printf(
            "\t\tJOGO DA FORCA\n\n"
            "\t             XXXXXX\n"
            "\t             X    X\n"
            "\t             O    X\n"
            "\t            /|\\   X\n"
            "\t            / \\   X\n"
            "\t      ____________X_\n"
            "\t     / / / / / / / /|\n"
            "\t    /_/_/_/_/_/_/_/|/\n"
            "\t    |_|_|_|_|_|_|_|/\n\n"
            "\t-----------MENU----------\n"
            "\t| 1 | Iniciar o jogo    |\n"
            "\t| 2 | Mostrar regras    |\n"
            "\t| 0 | Encerrar programa |\n"
            "\t-------------------------\n");
            scanf(" %d", &a); limpa(); return a;
}

void regras()
{
    limpartela();
    printf(
    "\t# Regras #\n\n"
    "# 1 # A forca nao faz distincao entre letras maiusculas e minusculas.\n"
    "# 2 # O tamanho maximo da frase secreta eh de 100 caracteres.\n"
    "# 3 # A frase secreta escondera apenas letras de A ate Z (acentos nao incluidos). Qualquer outro caractere sera revelado.\n"
    "# 4 # Apenas uma letra eh aceita por chute. No caso de mais de uma letra ser informada, apenas a primeira sera considerada.\n\n");
    pausartela();
}
 
void forca( int vida ) //"spritezinho" da forca
{
    switch (vida)
    {
    case 6:
    printf ("\t             XXXXXX\n"
            "\t             X    X\n"
            "\t                  X\n"
            "\t                  X\n"
            "\t                  X\n"
            "\t      ____________X_\n"
            "\t     / / / / / / / /|\t______ O\n"
            "\t    /_/_/_/_/_/_/_/|/\t_____ </V\n"
            "\t    |_|_|_|_|_|_|_|/\t______V\\ \n\n");
            break;
    case 5:
    printf ("\t             XXXXXX\n"
            "\t             X    X\n"
            "\t                  X\n"
            "\t                  X\n"
            "\t                  X\n"
            "\t      ____________X_\n"
            "\t     / / / / / / / /|\n"
            "\t    /_/_/_/_/_/_/_/|/\n"
            "\t    |_|_|_|_|_|_|_|/\n\n"
            ); break;
    case 4:
    printf ("\t             XXXXXX\n"
            "\t             X    X\n"
            "\t             O    X\n"
            "\t                  X\n"
            "\t                  X\n"
            "\t      ____________X_\n"
            "\t     / / / / / / / /|\n"
            "\t    /_/_/_/_/_/_/_/|/\n"
            "\t    |_|_|_|_|_|_|_|/\n\n"); break;
    case 3:
    printf ("\t             XXXXXX\n"
            "\t             X    X\n"
            "\t             O    X\n"
            "\t             |    X\n"
            "\t                  X\n"
            "\t      ____________X_\n"
            "\t     / / / / / / / /|\n"
            "\t    /_/_/_/_/_/_/_/|/\n"
            "\t    |_|_|_|_|_|_|_|/\n\n"); break;
    case 2:
    printf ("\t             XXXXXX\n"
            "\t             X    X\n"
            "\t             O    X\n"
            "\t            /|    X\n"
            "\t                  X\n"
            "\t      ____________X_\n"
            "\t     / / / / / / / /|\n"
            "\t    /_/_/_/_/_/_/_/|/\n"
            "\t    |_|_|_|_|_|_|_|/\n\n"); break;
    case 1:
    printf ("\t             XXXXXX\n"
            "\t             X    X\n"
            "\t             O    X\n"
            "\t            /|\\   X\n"
            "\t                  X\n"
            "\t      ____________X_\n"
            "\t     / / / / / / / /|\n"
            "\t    /_/_/_/_/_/_/_/|/\n"
            "\t    |_|_|_|_|_|_|_|/\n\n"); break;
    case 0:
    printf ("\t             XXXXXX\n"
            "\t             X    X\n"
            "\t             O    X\n"
            "\t            /|\\   X\n"
            "\t            / \\   X\n"
            "\t      ____________X_\n"
            "\t     / / / / / / / /|\n"
            "\t    /_/_/_/_/_/_/_/|/\n"
            "\t    |_|_|_|_|_|_|_|/\n\n"); break;
    }
}

int main ()
{
    char secreta[tammax], secreta2[tammax], chutes[tammax], input;
    int vida = 5, i = 0, perdeu = 1, k = 0, acabou = 0, l = 0, tam[3];

    while (l == 0) 
    {
        k = 0; vida = 5; memset(chutes, 0, strlen(chutes)); acabou = 0; l = 0;

        while(acabou!=1)
        {
            switch ( menu() )
            {
                case 1: acabou = 1; break;
                case 2: regras(); break;
                case 0: limpartela(); l = 1; acabou = 1; break;
            }
        }

        limpartela();
        
        if (l == 0)
        {
            //leitura de frase
            printf("Insira a frase secreta: "); 
            fgets(secreta, tammax, stdin); if ( strlen(secreta) == tammax-1 ) { limpa(); }
            while ( ehvalido(secreta) != 1  )
            {
                memset(secreta, 0, tammax);
                printf("Frase invalida. Tente novamente: ");
                fgets(secreta, tammax, stdin); if ( strlen(secreta) == tammax-1 ) { limpa(); }
            }
            secreta[strlen(secreta)-1] = '\0';
            tam[0] = strlen(secreta);
            //manipulacao da frase
            for (i = 0 ; i < tam[0] ; i++)
            {
                if ( secreta[i] >= 97 && secreta[i] <= 122 )
                    secreta[i] -= 32;
            }   strcpy(secreta2, secreta);
            tam[1] = strlen(secreta2);
            for (i = 0 ; i < tam[1] ; i ++)
            {
                if ( ( secreta2[i] >= 65 && secreta2[i] <= 90 ) || ( secreta2[i] >= 97 && secreta2[i] <= 122 ) )
                    secreta2[i] = '_';
            }

            limpartela();

            //começo de jogo
            do
            {
                //informacoes da tela
                printf("\tVidas: %d\t\tChutes: %s\n\n", vida, chutes);
                forca(vida);
                printf("\t%s\n", secreta2);
                //leitura de chute
                printf("\n\tInsira a letra: "); scanf(" %c", &input);
                limpa();    limpartela();

                //manipulaçao de chute
                if (input >= 97 && input <= 122)
                    input-=32;
                chutes[k] = input; chutes[k+1] = '\0';

                //comparaçao de chute com elementos da frase
                for (i = 0 ; i < tam[1] ; i++)
                {
                    if ( input == secreta[i] && input != secreta2[i] )
                    {    secreta2[i] = input; perdeu = 0;   }
                }

                //condiçao de erro de chute
                if (perdeu == 1)
                    vida-=1;
                
                perdeu = 1; k++;
            }
            while (vida > 0 && strcmp(secreta2, secreta) != 0);
            
            //tela de fim de jogo
            printf("\tVidas: %d\t\tChutes: %s\n\n", vida, chutes);
            forca(vida == 0 ? 0 : 6); //se vida = 0, mostra um desenho, se nao, mostra outro
            printf("\t%s\n", secreta2);
            //mensagem
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
    return 0;
}