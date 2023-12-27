/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int *numbers, int sum_of_even_num);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
  int data[NMAX], newData[NMAX];
  int length = NMAX;
  int length_new = 0;

  if (input(data, length)) {
    int sum_of_even_num = sum_numbers(data, length);
    printf("%d\n", sum_of_even_num);
    length_new = find_numbers(data, length, newData, sum_of_even_num);
    output(newData, length_new);
  } else {
    printf("n/a \n");
  }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      sum = sum + buffer[i];
    }
  }
  return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int *numbers, int sum_of_even_num) {
  int counter = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] == 0) {
      continue;
    }
    if (buffer[i] != 0 && sum_of_even_num % buffer[i] == 0) {
      numbers[counter] = buffer[i];
      counter++;
    }
  }
  return counter;
}

// Принимает длину и сам массив чисел
int input(int *buffer, int length) {
  int re = 1;
  if (scanf("%d", &length) != 1) {
    printf("n/a");
  }
  for (int *p = buffer; p - buffer < length; p++) {
    if (scanf("%d", p) != 1) {
      re = 0;
    } else {
      re = 1;
    }
  }

  return re;
}

//Вывести сумму  четных элементов и новый массив из элементов старого
void output(int *newData, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", newData[i]);
  }
}