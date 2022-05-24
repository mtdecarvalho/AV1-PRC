# AV1 de Programação em C

## Exercícios:

01. Faça um programa para ler um número inteiro positivo e informe se ele é primo.
   Assumimos para este exercicio que o número 1 não é primo.
   Todos os outros números primos são números que só tem dois divisores: 1 e ele mesmo.

02. Faça um programa que leia uma frase e informe se ela é palíndroma.
   Ex: arara

03. Faça um programa que leia uma frase e coloque a primeira letra de cada palavra em maiúscula e as 
   demais letras em minúscula.

04. Faça um programa que leia duas matrizes de reais (de no maximo 100x100), e mostre o resultado da soma.
   Caso nao seja possivel somar, escreva "Matrizes incompativeis para a soma!" 

05. Faça um programa que leia duas matrizes de reais (de no maximo 100x100), e mostre o resultado da multiplicação. 
   Caso nao seja possivel multiplicar, escreva "Matrizes incompativeis para a multiplicacao!"   
     
06. Faça um program que mostre um cardápio, onde o usuário escolhe pelo número, depois entra com a quantidade
   e o programa mostra o total a pagar. O programa só encerra quando 0 é digitado.  
~~~
   Cardapio  
     1 - Misto Quente    R$ 4.50
     2 - Queijo Quente   R$ 4.00
     3 - Hamburguer      R$ 6.00
     4 - Eggburguer      R$ 7.00
     5 - Podrão          R$ 9.00
     0 - Sair
~~~
07. Faça um programa que leia n e depois os dados de n alunos (no maximo 100), 
   ao final o programa deve listar o nome de todos os alunos com média maior que a média da turma.  
   Dados dos alunos: Nome 30 caracteres, Nota1 e Nota2 reais.  
                     media = (Nota1 + 2 * Nota2) / 3  

08. Faça um programa para ler dois números inteiros positivos e informe se eles são amigos.
   Números amigos são números que a soma dos divisores de um é igual ao valor do outro.
   Obs: garanta que os números são positivos. Caso não sejam, repita a leitura.  
   Ex: 220 e 284  
      Os divisores de 220 são 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110, cuja soma é 284  
      Os divisores de 284 são 1, 2, 4, 71 e 142, cuja soma é 220  

09. Faça um programa para ler n números reais (no máximo 100), e mostrar a média dos valores sem os valores extremos.
   A leitura dos números será encerrada quando o usuário digitar 0 ou chegarmos a 100.   
   (Obs: mas ele pode digitar números negativos e positivos)  
   ex: 1 3 7 1 4 7 3 1 4 0  
    extremos: 1 e 7  (1 é menor valor e 7 é o maior valor)  
    media = (3 + 4 + 3 + 4)/4 = 14/4 = 3.5  

   
10. Faça o jogo da Forca. 
    Inicialmente o programa deve ler uma frase secreta, limpar a tela e iniciar o jogo. 
    Na tela devem aparecer: As letras chutadas, a frase secreta com _ nas letras não chutadas, e a quantidade de vida, que inicialmente é 5.
    Após 5 erros o jogador perde.  
    Obs: o usuário so vai chutar letras de A-Z, então se na frase tivermos qualquer caractere diferente este já aparece revelado.
         A forca nao faz distinção de maiúscula e minúscula.  
  
