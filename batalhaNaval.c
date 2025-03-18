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

  // Define o tamanho dos navios
  int navio1[3] = {3, 2, 3}; // Primeiro valor == tamanho; Segundo valor == Linha; Terceiro valor == coluna;
  int navio2[3] = {3, 5, 7};

  // Posiciona o primeiro navio na horizontal
  for (int i = 0; i < navio1[0]; i++) {
    if (tabuleiro[navio1[1]][navio1[2] + i] == 0){
      tabuleiro[navio1[1]][navio1[2] + i] = 3;
    }
  }

  // Posiciona o segundo navio na vertical
  for (int i = 0; i < navio2[0]; i++) {
    if (tabuleiro[navio2[1] + i][navio2[2]] == 0) {
      tabuleiro[navio2[1] + i][navio2[2]] = 3;
    }
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