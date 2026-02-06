#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // =========================
    // Declaração do tabuleiro 10x10
    // =========================
    int tabuleiro[TAM][TAM];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // Vetores que representam os navios
    // =========================
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // =========================
    // Coordenadas iniciais escolhidas
    // =========================
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 6, colunaV = 1; // Navio vertical

    // =========================
    // Validação e posicionamento do navio horizontal
    // =========================
    if (colunaH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica sobreposição
            if (tabuleiro[linhaH][colunaH + i] == 0) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // =========================
    // Validação e posicionamento do navio vertical
    // =========================
    if (linhaV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica sobreposição
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // =========================
    // Exibição do tabuleiro
    // =========================
    printf("Tabuleiro Batalha Naval (0 = agua | 3 = navio)\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
