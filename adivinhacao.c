//tudo que começa com # em C se chama diretiva
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

//#define NUMERO_DE_TENTATIVAS 5 //#define para declarar váriáveis que são constante.

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    
    printf("    [][][]  /""\\  [][][]                            \n");
    printf("     |::|  /__\\  |::|       Bem vindo             \n");
    printf("     |[]|_|::::|_|[]|          ao                  \n");
    printf("     |::::::__::::::|   jogo de adivinhação!       \n");
    printf("     |:::::/||\\:::::|                             \n");
    printf("     |:#:::||||::#::|                              \n");
    printf("    #*###&*##&*&#*&###                              \n");
    printf("   ##*###&*##&*&#*&####                             \n");
    

    int segundos = time(0);//passa o numero de segundos corrente para fazer um cálculo randomico.
    srand(segundos);

    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;

    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade você deseja jogar?\n");
    printf("(1) Fácil; (2) Médio; (3) Difícil.\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel) {
        case 1:
        numerodetentativas = 20;
        break;
        case 2:
        numerodetentativas = 15;
        break;
        default:
        numerodetentativas = 6;
        break;
    }
    
    for(int i = 1; i <= numerodetentativas; i++) {
        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos.\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if(acertou) {
            break;
        } 
        else if(maior) {
            printf("O número que você chutou é MAIOR que o número secreto.\n");
        } 
        else {
            printf("O número que você chutou é MENOR que o número secreto.\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos; 
    }

    printf("Fim de jogo!\n");

    if(acertou){
        printf("    Parabéns!         \n");
        printf("      Você            \n");
        printf("     Ganhou          \n\n");
        printf("Você acertou em %d tentativas.\n\n", tentativas);
        printf("Total de pontos: %.1f\n\n", pontos);
    } else {
        printf("Você perdeu! Tente de novo.\n");
        printf("O número secreto era: %d", numerosecreto);
    }

}