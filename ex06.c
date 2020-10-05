//6- Faça um program que mostre um cardapio, onde o usuario escolhe pelo numero, depois entra com a quantidade
//   e o programa mostra o total a pagar. O programa so encerra quando digita-se 0.
//   Cardapio
//     1 - Misto Quente    R$ 4.50
//     2 - Queijo Quente   R$ 4.00
//     3 - Hamburguer      R$ 6.00
//     4 - Eggburguer      R$ 7.00
//     5 - Podrão          R$ 9.00
//     0 - Sair

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main ()
{
    int numpedido, qtdpedido;
    double val;
    char invalido, lixo;
    char cardapio[905] =
           (" __________________________________________\n"
           "|    BEM-VINDO AO CARVALHO'S FOODTRUCK!    |\n"
           "|------------------------------------------|\n"
           "| Nº|          LANCHE            |  PREÇO  |\n"
           "|------------------------------------------|\n"
           "| 1 |       Misto Quente         | R$ 4.50 |\n"
           "| 2 |       Queijo Quente        | R$ 4.00 |\n"
           "| 3 |       Hamburguer           | R$ 6.00 |\n"
           "| 4 |       Eggburguer           | R$ 7.00 |\n"
           "| 5 |       Podrão               | R$ 9.00 |\n"
           "|------------------------------------------|\n"
           "| 9 |       Mostrar cardapio               |\n"
           "| 0 |       Encerrar programa              |\n" 
           "|__________________________________________|");
    puts(cardapio);
    do
    {
        printf("\nInsira o numero de seu pedido: ");
        while ( scanf("%d", &numpedido) == 0 )
        {
            while ((lixo = getchar()) != '\n' && lixo != EOF);
            printf("\nValor invalido. Insira um numero valido: ");
        }
        //if (scanf("%d", &numpedido) == 0)
        //{
        //    do { printf("Insira um numero valido.\n");  invalido = getchar(); } while ( !isdigit(invalido) ); ungetc(invalido, stdin);
        //}
        switch(numpedido)
        { 
            case 1: val = 4.50; printf("\nInsira a quantidade de seu pedido: "); scanf("%d", &qtdpedido);
                                if ( qtdpedido == 0 ) break;
                                else { val*=qtdpedido; printf("\nTotal a pagar: R$%.2lf\n", val); break; }
            case 2: val = 4.00; printf("\nInsira a quantidade de seu pedido: "); scanf("%d", &qtdpedido); 
                                if ( qtdpedido == 0 ) break;
                                else { val*=qtdpedido; printf("\nTotal a pagar: R$%.2lf\n", val); break; }
            case 3: val = 6.00; printf("\nInsira a quantidade de seu pedido: "); scanf("%d", &qtdpedido); 
                                if ( qtdpedido == 0 ) break;
                                else { val*=qtdpedido; printf("\nTotal a pagar: R$%.2lf\n", val); break; }
            case 4: val = 7.00; printf("\nInsira a quantidade de seu pedido: "); scanf("%d", &qtdpedido); 
                                if ( qtdpedido == 0 ) break;
                                else { val*=qtdpedido; printf("\nTotal a pagar: R$%.2lf\n", val); break; }
            case 5: val = 9.00; printf("\nInsira a quantidade de seu pedido: "); scanf("%d", &qtdpedido); 
                                if ( qtdpedido == 0 ) break;
                                else { val*=qtdpedido; printf("\nTotal a pagar: R$%.2lf\n", val); break; }
            case 9: puts(cardapio); break;
            case 0: printf("\nEncerrando programa...\n"); break;
            default: printf("\nPor favor insira um numero de pedido valido!\n"); break;
        }
        if (qtdpedido == 0) { printf("\nEncerrando programa...\n"); break; }
    }
    while (numpedido != 0);
    return 0;
}