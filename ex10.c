//10- Faça o jogo da Forca. 
//    inicialmente o programa deve ler um frase secreta, limpar a tela e iniciar o jogo. 
//    Na tela devem aparacer: As letras chutas, a Frase secreta com _ nas letras nao chutadas, e a qtd de vida, que inicialmente é 5.
//    apos 5 erros o jogador perde.
//    obs: o usuario so vai chutar letras de A-Z, entao se na frase tivermos qualquer caracter diferente este ja aparece revelado.
//         e a Forca nao faz distinção de maiuscula e minuscula

#include <stdio.h>
#include <string.h>

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

int main ()
{
    char secreta[100], secreta2[100], input, chutes[100], lixo, cont;
    int vida = 5, i = 0, perdeu = 1, k = 0;
    do 
    {
        printf("Insira a frase secreta: "); scanf("%[^\n]s", secreta); lixo = getchar();
        while ( ehvalido(secreta) != 1)
            {   printf("Frase invalida.\n"); scanf("%[^\n]s", secreta); lixo = getchar();   }
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
        while (i < 1000) //limpar tela. melhorar talvez?
        {   printf("\n"); i++;  }
        do
        {
            printf("\nVidas: %d"
                    "\tChutes: %s\n\n", vida, chutes);
            printf("\t%s\n", secreta2);
            if (strcmp(secreta2, secreta) == 0)
            {
                printf("\nVoce ganhou!\n"); break;
            }
            printf("\nInsira a letra: "); scanf("%c", &input); lixo = getchar();
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
        } while (vida > 0);
        if (vida == 0)
            puts("Voce perdeu.");
        printf("\nFim de jogo. Jogar novamente? [s / n]\n"); scanf("%c", &cont); lixo = getchar();
    } while (cont == 's' || cont == 'S');
    return 0;
}