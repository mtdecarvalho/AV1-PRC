//10- Faça o jogo da Forca. 
//    inicialmente o programa deve ler um frase secreta, limpar a tela e iniciar o jogo. 
//    Na tela devem aparacer: As letras chutas, a Frase secreta com _ nas letras nao chutadas, e a qtd de vida, que inicialmente é 5.
//    apos 5 erros o jogador perde.
//    obs: o usuario so vai chutar letras de A-Z, entao se na frase tivermos qualquer caracter diferente este ja aparece revelado.
//         e a Forca nao faz distinção de maiuscula e minuscula

#include <stdio.h>
#include <string.h>

int main ()
{
    char secreta[100], secreta2[100], input, chutes[100];
    int vida = 5, i = 0, perdeu = 1, k = 0;
    scanf("%[^\n]s", secreta);
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
    printf("\nInsira a letra: \n"); scanf(" %c", &input);
    if (input >= 97 && input <= 122)
        input-=32;
    chutes[k] = input;
    for (i = 0 ; i < strlen(secreta2) ; i++)
    {
        if ( input == secreta[i] )
        {    secreta2[i] = input; perdeu = 0;   }
    }
    if (perdeu == 1)
        vida-=1;
    perdeu = 1; k++;
    } while (vida > 0);
    if (vida == 0)
        puts("Voce perdeu.");
    puts("Fim de jogo.");
    return 0;
}