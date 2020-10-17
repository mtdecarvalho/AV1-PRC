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
        system("read -r -p \"Pressione Enter para continuar...\" key");
    #elif _WIN32
        system("pause");
    #elif _WIN64
        system("pause");
    #endif
}

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    int numpedido, qtdpedido, k;
    double val;
    char invalido, lixo;
    char cardapio[] =
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
    "| 0 |       Encerrar programa              |\n" 
    "|__________________________________________|");
    
    do
    {
        limpartela();   puts(cardapio);
        printf("\nInsira o numero de seu pedido: ");
        while ( scanf(" %d", &numpedido) == 0 )
        {
            limpa(); printf("\nPor favor insira um numero valido: ");
        }
        limpa();
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
            case 0: printf("\nPrograma encerrado.\n\n"); return 0;
            default: printf("\nPor favor insira um numero de pedido valido!\n"); break;
        }
        if (qtdpedido == 0) { printf("\nPrograma encerrado.\n\n"); return 0; }
        limpa();    puts("");    pausartela();   limpartela(); 
    }
    while (numpedido != 0);
}