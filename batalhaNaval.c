#include <stdio.h>
// nivel mestre

int main() {
    // tabuleiro 10x10: 0 = agua, 3 = navio
    int tabuleiro[10][10];
    int efeito[10][10]; // 0 = nada, 5 = area de habilidade
    int i, j;

    // zera os tabuleiros
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
            efeito[i][j] = 0;
        }
    }

    // navios tamanho fixo 3
    int tamanho = 3;
    int navioH[3] = {3, 3, 3};  // horizontal
    int navioV[3] = {3, 3, 3};  // vertical
    int navioD1[3] = {3, 3, 3}; // diagonal baixo-direita
    int navioD2[3] = {3, 3, 3}; // diagonal cima-direita

    // coordenadas
    int linhaH = 2, colH = 3;
    int linhaV = 6, colV = 1;
    int linhaD1 = 0, colD1 = 0; // desce e vai pra direita
    int linhaD2 = 9, colD2 = 3; // sobe e vai pra direita

    // valida limites
    if (colH + tamanho > 10) { printf("Posicao invalida para o navio horizontal.\n"); return 1; }
    if (linhaV + tamanho > 10) { printf("Posicao invalida para o navio vertical.\n"); return 1; }
    if (linhaD1 + tamanho > 10 || colD1 + tamanho > 10) { printf("Posicao invalida para o navio diagonal 1.\n"); return 1; }
    if (linhaD2 - (tamanho - 1) < 0 || colD2 + tamanho > 10) { printf("Posicao invalida para o navio diagonal 2.\n"); return 1; }

    // checa e marca navio horizontal
    for (j = 0; j < tamanho; j++) {
        if (tabuleiro[linhaH][colH + j] != 0) { printf("Sobreposicao no navio horizontal.\n"); return 1; }
    }
    for (j = 0; j < tamanho; j++) tabuleiro[linhaH][colH + j] = navioH[j];

    // checa e marca navio vertical
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[linhaV + i][colV] != 0) { printf("Sobreposicao no navio vertical.\n"); return 1; }
    }
    for (i = 0; i < tamanho; i++) tabuleiro[linhaV + i][colV] = navioV[i];

    // checa e marca navio diagonal 1 (baixo-direita)
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[linhaD1 + i][colD1 + i] != 0) { printf("Sobreposicao no navio diagonal 1.\n"); return 1; }
    }
    for (i = 0; i < tamanho; i++) tabuleiro[linhaD1 + i][colD1 + i] = navioD1[i];

    // checa e marca navio diagonal 2 (cima-direita)
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[linhaD2 - i][colD2 + i] != 0) { printf("Sobreposicao no navio diagonal 2.\n"); return 1; }
    }
    for (i = 0; i < tamanho; i++) tabuleiro[linhaD2 - i][colD2 + i] = navioD2[i];

    // matrizes 5x5
    int cone[5][5];
    int cruz[5][5];
    int oct[5][5];

    // zera as matrizes
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            oct[i][j]  = 0;
        }
    }

    // CONE. Topo no meio da primeira linha da matriz.
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if ((c - 2 <= r) && (2 - c <= r)) { // equivalente a abs(c-2) <= r
                cone[r][c] = 1;
            }
        }
    }

    // CRUZ: ativa linha central e coluna central.
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (r == 2 || c == 2) {
                cruz[r][c] = 1;
            }
        }
    }

    // OCTAEDRO (losango)
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            int dr = (r > 2) ? (r - 2) : (2 - r);
            int dc = (c > 2) ? (c - 2) : (2 - c);
            if (dr + dc <= 2) {
                oct[r][c] = 1;
            }
        }
    }
    // pontos de origem no tabuleiro
    // cone: origem = APICE
    int origemConeLinha = 3;
    int origemConeCol   = 5;

    // cruz: origem = CENTRO da matriz
    int origemCruzLinha = 7;
    int origemCruzCol   = 7;

    // octaedro: origem = CENTRO da matriz
    int origemOctLinha = 4;
    int origemOctCol   = 1;

    // aplica CONE
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (cone[r][c] == 1) {
                int br = origemConeLinha + r;      // desloca para baixo a partir do apice
                int bc = origemConeCol   + (c - 2);// centraliza pelo meio do topo
                if (br >= 0 && br < 10 && bc >= 0 && bc < 10) {
                    efeito[br][bc] = 5;
                }
            }
        }
    }

    // aplica CRUZ
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (cruz[r][c] == 1) {
                int br = origemCruzLinha + (r - 2);
                int bc = origemCruzCol   + (c - 2);
                if (br >= 0 && br < 10 && bc >= 0 && bc < 10) {
                    efeito[br][bc] = 5;
                }
            }
        }
    }

    // aplica OCTAEDRO
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (oct[r][c] == 1) {
                int br = origemOctLinha + (r - 2);
                int bc = origemOctCol   + (c - 2);
                if (br >= 0 && br < 10 && bc >= 0 && bc < 10) {
                    efeito[br][bc] = 5;
                }
            }
        }
    }

    //0 agua, 3 navio, 5 habilidade
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            int val = (efeito[i][j] == 5) ? 5 : tabuleiro[i][j];
            printf("%d ", val);
        }
        printf("\n");
    }

    return 0;
}
