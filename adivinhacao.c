//tudo que come�a com # em C se chama diretiva
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

//#define NUMERO_DE_TENTATIVAS 5 //#define para declarar v�ri�veis que s�o constante.

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    
    printf("    [][][]  /""\\  [][][]                            \n");
    printf("     |::|  /__\\  |::|       Bem vindo             \n");
    printf("     |[]|_|::::|_|[]|          ao                  \n");
    printf("     |::::::__::::::|   jogo de adivinha��o!       \n");
    printf("     |:::::/||\\:::::|                             \n");
    printf("     |:#:::||||::#::|                              \n");
    printf("    #*###&*##&*&#*&###                              \n");
    printf("   ##*###&*##&*&#*&####                             \n");
    

    int segundos = time(0);//passa o numero de segundos corrente para fazer um c�lculo randomico.
    srand(segundos);

    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;

    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o n�vel de dificuldade voc� deseja jogar?\n");
    printf("(1) F�cil; (2) M�dio; (3) Dif�cil.\n\n");
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
        printf("Qual � o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0) {
            printf("Voc� n�o pode chutar n�meros negativos.\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if(acertou) {
            break;
        } 
        else if(maior) {
            printf("O n�mero que voc� chutou � MAIOR que o n�mero secreto.\n");
        } 
        else {
            printf("O n�mero que voc� chutou � MENOR que o n�mero secreto.\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos; 
    }

    printf("Fim de jogo!\n");

    if(acertou){
        printf("    Parab�ns!         \n");
        printf("      Voc�            \n");
        printf("     Ganhou          \n\n");
        printf("Voc� acertou em %d tentativas.\n\n", tentativas);
        printf("Total de pontos: %.1f\n\n", pontos);
    } else {
        printf("Voc� perdeu! Tente de novo.\n");
        printf("O n�mero secreto era: %d", numerosecreto);
    }

}