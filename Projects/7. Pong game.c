#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80
#define ROCKET_SIZE 3

void clear_screen() {
    for (int i = 0; i < 50; i++) {
        printf("\n");
    }
}

void render(int fPr, int sPr, int ballX, int ballY, int score1, int score2, int shift_scr_score1,
            int shift_scr_score2) {
    clear_screen();

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {
                printf("*");
            } else if (x == 2 && y >= fPr && y < fPr + ROCKET_SIZE) {
                printf("|");
            } else if (x == WIDTH - 3 && y >= sPr && y < sPr + ROCKET_SIZE) {
                printf("|");
            } else if (x == ballX && y == ballY) {
                printf("o");
            } else if (x == 20 && y == 1) {
                printf("P1: %d", score1);
                x += shift_scr_score1;
            } else if (x == WIDTH - 20 && y == 1) {
                printf("P2: %d", score2);
                x += shift_scr_score2;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int move_left_paddle(int fPr, char cmd) {
    if (cmd == 'A' || cmd == 'a') {
        if (fPr > 1) {
            fPr--;
        }
    } else if (cmd == 'Z' || cmd == 'z') {
        if (fPr + ROCKET_SIZE < HEIGHT - 1) {
            fPr++;
        }
    }
    return fPr;
}

int move_right_paddle(int sPr, char cmd) {
    if (cmd == 'K' || cmd == 'k') {
        if (sPr > 1) {
            sPr--;
        }
    } else if (cmd == 'M' || cmd == 'm') {
        if (sPr + ROCKET_SIZE < HEIGHT - 1) {
            sPr++;
        }
    }
    return sPr;
}

void game_over(int score1, int score2) {
    if (score1 >= 21) {
        printf("Победил первый игрок!\n");
    } else if (score2 >= 21) {
        printf("Победил второй игрок!\n");
    }
}
void run_game(int fPr, int sPr, int ballX, int ballY, int ballDirX, int ballDirY, int score1, int score2,
              int shift_scr_score1, int shift_scr_score2) {
    while (score1 < 21 && score2 < 21) {
        render(fPr, sPr, ballX, ballY, score1, score2, shift_scr_score1, shift_scr_score2);
        printf("Введите команду (A/Z - лев. ракетка; K/M - прав. ракетка; пробел - пропустить): ");
        char cmd = getchar();
        while (getchar() != '\n');
        if (cmd == 'A' || cmd == 'a' || cmd == 'Z' || cmd == 'z')
            fPr = move_left_paddle(fPr, cmd);
        else if (cmd == 'K' || cmd == 'k' || cmd == 'M' || cmd == 'm')
            sPr = move_right_paddle(sPr, cmd);
        if (cmd == 'A' || cmd == 'a' || cmd == 'Z' || cmd == 'z' || cmd == 'K' || cmd == 'k' || cmd == 'M' ||
            cmd == 'm' || cmd == ' ') {
            ballX += ballDirX;
            ballY += ballDirY;
            if (ballY <= 1 || ballY >= HEIGHT - 2) ballDirY = -ballDirY;
            if (ballX == 3) {
                if (ballY >= fPr && ballY < fPr + ROCKET_SIZE)
                    ballDirX = -ballDirX;
                else {
                    score2++;
                    if (score2 == 10) shift_scr_score2++;
                    ballX = WIDTH / 2;
                    ballY = HEIGHT / 2;
                    ballDirX = 1;
                    ballDirY = 1;
                }
            }
            if (ballX == WIDTH - 4) {
                if (ballY >= sPr && ballY < sPr + ROCKET_SIZE)
                    ballDirX = -ballDirX;
                else {
                    score1++;
                    if (score1 == 10) shift_scr_score1++;
                    ballX = WIDTH / 2;
                    ballY = HEIGHT / 2;
                    ballDirX = -1;
                    ballDirY = 1;
                }
            }
        }
        if (score1 >= 21 || score2 >= 21) {
            render(fPr, sPr, ballX, ballY, score1, score2, shift_scr_score1, shift_scr_score2);
            break;
        }
    }
    game_over(score1, score2);
}

int main() {
    int fPr = 13;
    int sPr = 13;

    int ballX = 40;
    int ballY = 12;
    int ballDirX = 1;
    int ballDirY = 1;

    int score1 = 0;
    int score2 = 0;

    int shift_scr_score1 = 4;
    int shift_scr_score2 = 4;

    run_game(fPr, sPr, ballX, ballY, ballDirX, ballDirY, score1, score2, shift_scr_score1, shift_scr_score2);

    return 0;
}
