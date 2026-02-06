#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_NAVIO 3
#define TAM_HAB 5

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

    int navio[TAM_NAVIO] = {3, 3, 3};

    // =========================
    // NAVIOS
    // =========================
    int lH = 1, cH = 2;
    for (int i = 0; i < TAM_NAVIO; i++)
        if (tabuleiro[lH][cH + i] == 0)
            tabuleiro[lH][cH + i] = navio[i];

    int lV = 5, cV = 8;
    for (int i = 0; i < TAM_NAVIO; i++)
        if (tabuleiro[lV + i][cV] == 0)
            tabuleiro[lV + i][cV] = navio[i];

    int lD1 = 2, cD1 = 5;
    for (int i = 0; i < TAM_NAVIO; i++)
        if (tabuleiro[lD1 + i][cD1 + i] == 0)
            tabuleiro[lD1 + i][cD1 + i] = navio[i];

    int lD2 = 6, cD2 = 6;
    for (int i = 0; i < TAM_NAVIO; i++)
        if (tabuleiro[lD2 + i][cD2 - i] == 0)
            tabuleiro[lD2 + i][cD2 - i] = navio[i];

    // =========================
    // MATRIZES DE HABILIDADE (5x5)
    // =========================
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;

            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;

            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // =========================
    // PONTOS DE ORIGEM DAS HABILIDADES
    // =========================
    int origemConeL = 2, origemConeC = 2;
    int origemCruzL = 7, origemCruzC = 2;
    int origemOctL = 4, origemOctC = 7;

    // =========================
    // SOBREPOR HABILIDADES NO TABULEIRO (marca com 5)
    // =========================
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l, c;

            l = origemConeL + i - centro;
            c = origemConeC + j - centro;
            if (l >= 0 && l < TAM && c >= 0 && c < TAM)
                if (cone[i][j] == 1 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;

            l = origemCruzL + i - centro;
            c = origemCruzC + j - centro;
            if (l >= 0 && l < TAM && c >= 0 && c < TAM)
                if (cruz[i][j] == 1 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;

            l = origemOctL + i - centro;
            c = origemOctC + j - centro;
            if (l >= 0 && l < TAM && c >= 0 && c < TAM)
                if (octaedro[i][j] == 1 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
        }
    }

    // =========================
    // EXIBIÇÃO FINAL
    // =========================
    printf("\nTabuleiro Batalha Naval\n\n");

    printf("    ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n\n");

    for (int i = 0; i < TAM; i++) {

        printf("%2d | ", i);

        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0)
                printf("~  ");
            else if (tabuleiro[i][j] == 3)
                printf("N  ");
            else if (tabuleiro[i][j] == 5)
                printf("*  ");
        }

        printf("\n");
    }

    return 0;
}
