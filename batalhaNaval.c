#include <stdio.h>
//nível novato

int main() {
    // tabuleiro 10x10: 0 = água, 3 = navio
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

    // coordenadas iniciais definidas no código
    int linhaH = 2; // 0..9
    int colH   = 3; // 0..9

    int linhaV = 6; // 0..9
    int colV   = 1; // 0..9

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

    // checa sobreposição do horizontal
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

    // checa sobreposição do vertical
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

    // exibe o tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
