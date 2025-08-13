#include <stdio.h>
// nivel aventureiro

int main() {
    // tabuleiro 10x10: 0 = agua, 3 = navio
    int tabuleiro[10][10];
    int i, j;

    // zera o tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // navios tamanho fixo 3
    int tamanho = 3;
    int navioH[3] = {3, 3, 3}; // horizontal
    int navioV[3] = {3, 3, 3}; // vertical
    int navioD1[3] = {3, 3, 3}; // diagonal para baixo-direita (linha++, col++)
    int navioD2[3] = {3, 3, 3}; // diagonal para cima-direita   (linha--, col++)

    // coordenadas iniciais definidas no codigo (ajustadas para nao sobrepor)
    int linhaH = 2; // 0..9
    int colH   = 3; // 0..9

    int linhaV = 6; // 0..9
    int colV   = 1; // 0..9

    // diagonal 1: desce e vai pra direita (ex.: (0,0)->(1,1)->(2,2))
    int linhaD1 = 0;
    int colD1   = 0;

    // diagonal 2: sobe e vai pra direita (ex.: (9,3)->(8,4)->(7,5))
    int linhaD2 = 9;
    int colD2   = 3;

    // valida limites do navio horizontal
    if (colH + tamanho > 10) {
        printf("Posicao invalida para o navio horizontal.\n");
        return 1;
    }

    // valida limites do navio vertical
    if (linhaV + tamanho > 10) {
        printf("Posicao invalida para o navio vertical.\n");
        return 1;
    }

    // valida limites da diagonal 1 (baixo-direita)
    if (linhaD1 + tamanho > 10 || colD1 + tamanho > 10) {
        printf("Posicao invalida para o navio diagonal 1.\n");
        return 1;
    }

    // valida limites da diagonal 2 (cima-direita)
    if (linhaD2 - (tamanho - 1) < 0 || colD2 + tamanho > 10) {
        printf("Posicao invalida para o navio diagonal 2.\n");
        return 1;
    }

    // checa sobreposicao do horizontal
    for (j = 0; j < tamanho; j++) {
        if (tabuleiro[linhaH][colH + j] != 0) {
            printf("Sobreposicao detectada no navio horizontal.\n");
            return 1;
        }
    }

    // marca o navio horizontal no tabuleiro
    for (j = 0; j < tamanho; j++) {
        tabuleiro[linhaH][colH + j] = navioH[j];
    }

    // checa sobreposicao do vertical
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[linhaV + i][colV] != 0) {
            printf("Sobreposicao detectada no navio vertical.\n");
            return 1;
        }
    }

    // marca o navio vertical no tabuleiro
    for (i = 0; i < tamanho; i++) {
        tabuleiro[linhaV + i][colV] = navioV[i];
    }

    // checa sobreposicao da diagonal 1 (baixo-direita)
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[linhaD1 + i][colD1 + i] != 0) {
            printf("Sobreposicao detectada no navio diagonal 1.\n");
            return 1;
        }
    }

    // marca o navio diagonal 1
    for (i = 0; i < tamanho; i++) {
        tabuleiro[linhaD1 + i][colD1 + i] = navioD1[i];
    }

    // checa sobreposicao da diagonal 2 (cima-direita)
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[linhaD2 - i][colD2 + i] != 0) {
            printf("Sobreposicao detectada no navio diagonal 2.\n");
            return 1;
        }
    }

    // marca o navio diagonal 2
    for (i = 0; i < tamanho; i++) {
        tabuleiro[linhaD2 - i][colD2 + i] = navioD2[i];
    }

    // exibe o tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
