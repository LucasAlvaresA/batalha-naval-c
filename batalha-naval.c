#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    int tabuleiro[TAM][TAM];

    // =========================
    // Inicializa tabuleiro com água (0)
    // =========================
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // Navios (vetores)
    // =========================
    int navio[TAM_NAVIO] = {3, 3, 3};

    // =========================
    // NAVIO 1 — Horizontal
    // =========================
    int lH = 1, cH = 2;

    if (cH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[lH][cH + i] == 0) {
                tabuleiro[lH][cH + i] = navio[i];
            }
        }
    }

    // =========================
    // NAVIO 2 — Vertical
    // =========================
    int lV = 5, cV = 8;

    if (lV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[lV + i][cV] == 0) {
                tabuleiro[lV + i][cV] = navio[i];
            }
        }
    }

    // =========================
    // NAVIO 3 — Diagonal principal (↘)
    // =========================
    int lD1 = 2, cD1 = 5;

    if (lD1 + TAM_NAVIO <= TAM && cD1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[lD1 + i][cD1 + i] == 0) {
                tabuleiro[lD1 + i][cD1 + i] = navio[i];
            }
        }
    }

    // =========================
    // NAVIO 4 — Diagonal secundária (↙)
    // =========================
    int lD2 = 6, cD2 = 6;

    if (lD2 + TAM_NAVIO <= TAM && cD2 - (TAM_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[lD2 + i][cD2 - i] == 0) {
                tabuleiro[lD2 + i][cD2 - i] = navio[i];
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
