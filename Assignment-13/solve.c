#include <stdio.h>

#define GAME 4
#define PLAYER 5

int main(int argc, char const *argv[]) {
  int scores[GAME][PLAYER] = {0};
  for (int i = 0; i < GAME; i++) {
    printf("Game #%d\n", i + 1);
    for (int j = 0; j < PLAYER; j++) {
      printf("Enter scoring total for Player #%d: ", j + 1);
      scanf("%d", &scores[i][j]);
    }
  }
  float avg_scores[PLAYER] = {0};
  for (int i = 0; i < PLAYER; i++) {
    for (int j = 0; j < GAME; j++) {
      avg_scores[i] += scores[j][i];
    }
    avg_scores[i] /= GAME;
  }
  float max_avg_score = 0;
  int max_player;
  for (int i = 0; i < PLAYER; i++) {
    if (avg_scores[i] > max_avg_score) {
      max_avg_score = avg_scores[i];
      max_player = i + 1;
    }
  }
  printf(
      "Player #%d had the highest scoring average at %.2f points per game.\n",
      max_player, max_avg_score);
  return 0;
}