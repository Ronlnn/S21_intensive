#include <math.h>
#include <stdio.h>

void tennis_display(int ball_pos_x, int ball_pos_y, int r1_pos_y, int r2_pos_y, int width, int heigth);

int Racket_move(char move, int r1_pos_y, int r2_pos_y, int heigth);

int Racket_rebound_condition(int ball_x, int ball_y, int r1_pos_y, int r2_pos_y, int width);

int Top_bottom_detection(int heigth, int pos_y);

int Racket_drawing_conditions(int i, int j, int r1_pos_y, int r2_pos_y, int width);

int Ball_hitting_racket(int ball_pos_x, int ball_pos_y, int r1_pos_y, int r2_pos_y, int width, int deltax,
                        int deltay);

void Render(int ball_pos_x, int ball_pos_y, int r1_pos_y, int r2_pos_y, int width, int heigth, int score1,
            int score2);

int main() {
    int heigth = 25, width = 80;
    int ball_position_x, ball_position_y = 13, racket1_st_y = 13, racket2_st_y = 13;

    tennis_display(ball_position_x, ball_position_y, racket1_st_y, racket2_st_y, width, heigth);

    return 0;
}

void tennis_display(int ball_pos_x, int ball_pos_y, int r1_pos_y, int r2_pos_y, int width, int heigth) {
    char move1, move2, enter;
    int score1 = 0, score2 = 0;

    while ((score1 < 21) && (score2 < 21)) {
        ball_pos_x = 2;  // начальная позиция шарика
        ball_pos_y = 13;
        r1_pos_y = 13;  // начальные позиции ракеток
        r2_pos_y = 13;
        int deltax = -1, deltay = 1;  // начальные перемещения шарика

        while ((ball_pos_x > 0) && (ball_pos_x < (width - 1))) {
            Render(ball_pos_x, ball_pos_y, r1_pos_y, r2_pos_y, width, heigth, score1, score2);

            do {
                rewind(stdin);
            } while (!((scanf("%c%c%c", &move1, &move2, &enter) == 3) && (enter == '\n')) ||
                     !(((move1 == 'A') || (move1 == 'Z') || (move1 == ' ')) &&
                       ((move2 == 'K') || (move2 == 'M') || (move2 == ' '))));

            r1_pos_y = r1_pos_y + Racket_move(move1, r1_pos_y, r2_pos_y,
                                              heigth);  // Эта функция принимает в себя символ и возвращает
                                                        // перемещение ракетки (0, 1, -1)
            r2_pos_y = r2_pos_y + Racket_move(move2, r1_pos_y, r2_pos_y, heigth);

            // Эта функция проверяет условие прислонился ли шарик к правой ракетке
            // Если да - то отскакивает меняя направление по x
            deltax = deltax * Racket_rebound_condition(ball_pos_x, ball_pos_y, r1_pos_y, r2_pos_y, width);

            if (Top_bottom_detection(
                    heigth - 2,
                    ball_pos_y - 1))  //Эта функция проверяет присоединился ли шарик к полу или потолку
                deltay = deltay * (-1);  // Если да, то меняет направление по у

            deltax = deltax * Ball_hitting_racket(ball_pos_x, ball_pos_y, r1_pos_y, r2_pos_y, width, deltax,
                                                  deltay);  //Если мяч въезжает в ракетку

            ball_pos_x += deltax;  //перемещает мяч соответственно с расчётами на пред этапе
            ball_pos_y += deltay;

            if (ball_pos_x == 0) {
                score2 += 1;
            }
            if (ball_pos_x >= width - 1) {
                score1 += 1;
            }
        }
    }
    printf("👑 CONGRATULATIONS 🤖 Player %d ! YOU WIN THIS LIFE 👑\n", (score1 > score2) ? 1 : 2);  //Вывод победителя
}

void Render(int ball_pos_x, int ball_pos_y, int r1_pos_y, int r2_pos_y, int width, int score1,
            int score2) {
    char cross = '@', space = ' ', racket = '|';

    for (int j = 0; j < 28; j++) {
        for (int i = 0; i < width; i++) {
            if ((i == ball_pos_x) && (j == ball_pos_y))  // условия отрисовки мяча
                printf("%c", cross);
            else if (Racket_drawing_conditions(i, j, r1_pos_y, r2_pos_y, width))  // условия отрисовки ракеток
                printf("%c", racket);
            else if (Top_bottom_detection(heigth, j))
                printf("-");
            else if (i == 0 || i == width - 1) {
                printf("|");
            } else if ((j == 26) && (i == 38)) {
                printf("%d", score1);
            } else if ((j == 26) && (i == 42)) {
                printf("%d", score2);
            } else
                printf("%c", space);
        }
        printf("\n");
    }
}

int Ball_hitting_racket(int ball_pos_x, int ball_pos_y, int r1_pos_y, int r2_pos_y, int width, int deltax,
                        int deltay) {
    if ((((ball_pos_x + deltax) == 1) && fabs((float)(ball_pos_y + deltay) - (float)r1_pos_y) <= 1) ||
        (((ball_pos_x + deltax) == width - 2) && fabs((float)(ball_pos_y + deltay) - (float)r2_pos_y) <= 1)) {
        return -1;
    } else {
        return 1;
    }
}

int Racket_rebound_condition(int ball_x, int ball_y, int r1_pos_y, int r2_pos_y, int width) {
    if (((ball_x == 2) && fabs((float)ball_y - (float)r1_pos_y) <= 1) ||
        ((ball_x == (width - 3)) && fabs((float)ball_y - (float)r2_pos_y) <= 1))
        return -1;
    else
        return 1;
}

int Racket_drawing_conditions(int i, int j, int r1_pos_y, int r2_pos_y, int width) {
    if (((i == 1) && (fabs((float)j - (float)r1_pos_y) <= 1)) ||
        ((i == (width - 2)) && (fabs((float)j - (float)r2_pos_y) <= 1)))
        return 1;
    else
        return 0;
}

int Racket_move(char move, int r1_pos_y, int r2_pos_y, int heigth) {
    if (((move == 'A') && (r1_pos_y >= 3)) || ((move == 'K') && (r2_pos_y >= 3)))
        return -1;
    else if (((move == 'Z') && (r1_pos_y <= heigth - 4)) || ((move == 'M') && (r2_pos_y <= heigth - 4)))
        return 1;
    else if (move == ' ')
        return 0;
    else
        return 0;
}

int Top_bottom_detection(int heigth, int pos_y) {
    if (pos_y == 0 || pos_y == (heigth - 1)) {
        return 1;
    } else {
        return 0;
    }
}
