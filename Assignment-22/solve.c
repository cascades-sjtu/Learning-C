#include <stdio.h>

#define PLAYER 5

typedef struct {
    int points;
    int games;
} stats;
stats player[PLAYER];

void get_stats(stats *s, int id) {
    printf("Enter Player %d's point total: ", id);
    scanf("%d", &s->points);
    printf("Enter Player %d's game total: ", id);
    scanf("%d", &s->games);
}

void print_ppg(stats s, int id) {
    float avg = (float)s.points / (float)s.games;
    printf("Player %d's scoring average was %.2f ppg.\n", id, avg);
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < PLAYER; i++) {
        get_stats(&(player[i]), i + 1);
    }
    for (int i = 0; i < PLAYER; i++) {
        print_ppg(player[i], i + 1);
    }
    return 0;
}