#include <stdio.h>

int main(){

  int tabuleiro[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };

  // Define os navios
  int navio1[3] = {3, 2, 3}; // Primeiro valor == tamanho; Segundo valor == Linha; Terceiro valor == coluna;
  int navio2[3] = {3, 4, 7};
  int navio3[3] = {3, 4, 0}; // Terceiro navio (diagonal)
  int navio4[3] = {3, 7, 5}; // Quarto navio (diagonal)

  // Posiciona o primeiro navio na horizontal
  if (navio1[2] + navio1[0] <= 10) {
    for (int i = 0; i < navio1[0]; i++) {
      if (tabuleiro[navio1[1]][navio1[2] + i] == 0) {
        tabuleiro[navio1[1]][navio1[2] + i] = 3;
      }
  }
} else {
    printf("Erro: O primeiro navio horizontal não cabe no tabuleiro.\n");
}

  // Posiciona o segundo navio na vertical
  if (navio2[1] + navio2[0] <= 10) {
    for (int i = 0; i < navio2[0]; i++) {
      if (tabuleiro[navio2[1] + i][navio2[2]] == 0) {
        tabuleiro[navio2[1] + i][navio2[2]] = 3;
      }
    }
} else {
    printf("Erro: O segundo navio vertical não cabe no tabuleiro.\n");
}

// Posiciona o terceiro navio na diagonal
if (navio3[1] + navio3[0] <= 10 && navio3[2] + navio3[0] <= 10) {
  for (int i = 0; i < navio3[0]; i++) {
    if (tabuleiro[navio3[1] + i][navio3[2] + i] == 0) {
      tabuleiro[navio3[1] + i][navio3[2] + i] = 3;
    }
  }
} else {
  printf("Erro: O terceiro navio diagonal crescente não cabe no tabuleiro.\n");
}

// Posiciona o quarto navio na diagonal
if (navio4[1] + navio4[0] <= 10 && navio4[2] + navio4[0] <= 10) {
  for (int i = 0; i < navio4[0]; i++) {
    if (tabuleiro[navio4[1] + i][navio4[2] + i] == 0) {
      tabuleiro[navio4[1] + i][navio4[2] + i] = 3;
    }
  }
} else {
  printf("Erro: O quarto navio diagonal crescente não cabe no tabuleiro.\n");
}

  // Exibe o tabuleiro
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  return 0;
}