#include <stdio.h>

void cross_and_toe_display(int cross_pos, int toe_pos);

int main() {
    int cross_position_x, cross_position_y;
    printf("Enter the \"X\" and \"O\" position:");

    if (scanf("%d%d", &cross_position_x, &cross_position_y) != 2 || cross_position_x < 0 || cross_position_y < 0) {
        printf("Invalid position");
        return -1;
    }

    cross_and_toe_display(cross_position_x, cross_position_y);
}

void cross_and_toe_display(int cross_pos_x, int cross_pos_y) {
    char cross = 'X';
    char space = ' ';
    //int max_pos = (cross_pos > toe_pos) ? cross_pos : toe_pos;
    for (int j = 0; j < 24; j++) {
        for (int i = 0; i < 80; i++){
            if ((i == cross_pos_x) && (j == cross_pos_y)) {
                printf("%c", cross);
            } 
            else {
                printf("%c", space);
            }
        }
    printf("\n");
    }
}
