#include <stdio.h>
#include <stdlib.h>

#define LINHA_TABULEIRO 10
#define COLUNA_TABULEIRO 10
#define ALTURA_HABILIDADE 3
#define LARGURA_HABILIDADE 5

void aplicar_habilidade(int origem_linha, int origem_coluna, int habilidade[ALTURA_HABILIDADE][LARGURA_HABILIDADE], int tabuleiro[LINHA_TABULEIRO][COLUNA_TABULEIRO]) {
  int offset_linha = ALTURA_HABILIDADE / 2;
  int offset_coluna = LARGURA_HABILIDADE / 2;

  for (int i = 0; i < ALTURA_HABILIDADE; i++) {
    for (int j = 0; j < LARGURA_HABILIDADE; j++) {
      int linha = origem_linha + i - offset_linha;
      int coluna = origem_coluna + j - offset_coluna;

      if (linha >= 0 && linha < LINHA_TABULEIRO && coluna >= 0 && coluna < COLUNA_TABULEIRO) {
        if (habilidade[i][j] == 1) {
          tabuleiro[linha][coluna] = 5;
        }
      }
    }
  }
}

int main() {
  int tabuleiro[LINHA_TABULEIRO][COLUNA_TABULEIRO];

  // Inicializa o tabuleiro com água
  for (int i = 0; i < LINHA_TABULEIRO; i++){
    for (int j = 0; j < COLUNA_TABULEIRO; j++){
      tabuleiro[i][j] = 0;
    }
  }

  // Define os navios
  int navio1[3] = {3, 2, 3}; // Primeiro valor == tamanho; Segundo valor == Linha; Terceiro valor == coluna;
  int navio2[3] = {3, 4, 7};
  int navio3[3] = {3, 4, 0};
  int navio4[3] = {3, 7, 5};

  // Posiciona o primeiro navio na horizontal
  if (navio1[2] + navio1[0] <= LINHA_TABULEIRO) {
    for (int i = 0; i < navio1[0]; i++) {
      if (tabuleiro[navio1[1]][navio1[2] + i] == 0) {
        tabuleiro[navio1[1]][navio1[2] + i] = 3;
      }
    }
  } else {
    printf("Erro: O primeiro navio horizontal não cabe no tabuleiro.\n");
  }

  // Posiciona o segundo navio na vertical
  if (navio2[1] + navio2[0] <= COLUNA_TABULEIRO) {
    for (int i = 0; i < navio2[0]; i++) {
      if (tabuleiro[navio2[1] + i][navio2[2]] == 0) {
        tabuleiro[navio2[1] + i][navio2[2]] = 3;
      }
    }
  } else {
    printf("Erro: O segundo navio vertical não cabe no tabuleiro.\n");
  }

  // Posiciona o terceiro navio na diagonal
  if (navio3[1] + navio3[0] <= LINHA_TABULEIRO && navio3[2] + navio3[0] <= COLUNA_TABULEIRO) {
    for (int i = 0; i < navio3[0]; i++) {
      if (tabuleiro[navio3[1] + i][navio3[2] + i] == 0) {
        tabuleiro[navio3[1] + i][navio3[2] + i] = 3;
      }
    }
  } else {
    printf("Erro: O terceiro navio diagonal crescente não cabe no tabuleiro.\n");
  }

  // Posiciona o quarto navio na diagonal
  if (navio4[1] + navio4[0] <= LINHA_TABULEIRO && navio4[2] + navio4[0] <= COLUNA_TABULEIRO) {
    for (int i = 0; i < navio4[0]; i++) {
      if (tabuleiro[navio4[1] + i][navio4[2] + i] == 0) {
        tabuleiro[navio4[1] + i][navio4[2] + i] = 3;
      }
    }
  } else {
    printf("Erro: O quarto navio diagonal crescente não cabe no tabuleiro.\n");
  }


    int habilidade_cone[ALTURA_HABILIDADE][LARGURA_HABILIDADE] = {0};
    int habilidade_cruz[ALTURA_HABILIDADE][LARGURA_HABILIDADE] = {0};
    int habilidade_octaedro[ALTURA_HABILIDADE][LARGURA_HABILIDADE] = {0};

    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
      for (int j = 0; j < LARGURA_HABILIDADE; j++) {
        habilidade_cone[i][j] = (j >= LARGURA_HABILIDADE / 2 - i && j <= LARGURA_HABILIDADE / 2 + i) ? 1 : 0;
        habilidade_cruz[i][j] = (i == ALTURA_HABILIDADE / 2 || j == LARGURA_HABILIDADE / 2) ? 1 : 0;
        habilidade_octaedro[i][j] = (abs(i - ALTURA_HABILIDADE / 2) + abs(j - LARGURA_HABILIDADE / 2) <= ALTURA_HABILIDADE / 2) ? 1 : 0;
      }
    }

    aplicar_habilidade(1, 2, habilidade_cone, tabuleiro);
    aplicar_habilidade(5, 3, habilidade_cruz, tabuleiro);
    aplicar_habilidade(8, 8, habilidade_octaedro, tabuleiro);

    for (int i = 0; i < LINHA_TABULEIRO; i++) {
      for (int j = 0; j < COLUNA_TABULEIRO; j++) {
        printf("%d ", tabuleiro[i][j]);
      }
      printf("\n");
    }

    return 0;
}