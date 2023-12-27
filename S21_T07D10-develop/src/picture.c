#include <stdio.h>
#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void print(int **picture, int n, int m);

int main() {
  int picture_data[N][M];
  int *picture[N];
  transform(*picture_data, picture, N, M);

  make_picture(picture, N, M);
  print(picture, N, M);
  return 0;
}

void make_picture(int **picture, int n, int m) {
  int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int tree_thin_trunk[] = {0, 7, 7, 0};
  int tree_trunk[] = {7, 7, 7, 7};
  int tree_thin_foliage[] = {0, 3, 3, 0};
  int tree_foliage[] = {3, 3, 3, 3};
  int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                        {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

  reset_picture(picture, n, m);

  int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
  int height_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

  for (int j = 0; j < height_frame_h; j++) {
    for (int i = 0; i < length_frame_w; i++) {
      if (j == 0 j == 7 j == 14) {
        picture[j][i] = frame_w[i];
      } else if (i == 0 i == 6 i == 12) {
        picture[j][i] = frame_w[i];
      } else if ((j == 2 || j == 5) && (i > 1 && i < 6)) {
        picture[j][i] = tree_thin_foliage[i - 2];
      } else if (j > 0 && j < 7 && i > 6) {
        picture[j][i] = sun_data[j - 1][i - 7];
      } else if ((j == 3 || j == 4) && (i > 1 && i < 6)) {
        picture[j][i] = tree_foliage[i - 2];
      } else if ((j == 6 j == 8 j == 9) && (i > 1 && i < 6)) {
        picture[j][i] = tree_thin_trunk[i - 2];
      } else if (j == 10 && (i > 1 && i < 6)) {
        picture[j][i] = tree_trunk[i - 2];
      }
    }
  }
}

void reset_picture(int **picture, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      picture[i][j] = 0;
    }
  }
}

void transform(int *buf, int **matr, int n, int m) {
  for (int i = 0; i < n; i++) {
    matr[i] = buf + i * m;
  }
}

void print(int **picture, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", picture[i][j]);
    }
    printf("\n");
  }
}