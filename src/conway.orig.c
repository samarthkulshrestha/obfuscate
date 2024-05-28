#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define ROWS 8
#define COLS 16

int front[ROWS][COLS] = {0};
int back[ROWS][COLS] = {0};

void display(void) {
  for (int y = 0; y < ROWS; ++y) {
    for (int x = 0; x < COLS; ++x) {
      if (front[y][x]) {
        printf("*");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int count_nbrs(int cx, int cy);

void next(void) {
  for (int y = 0; y < ROWS; ++y) {
    for (int x = 0; x < COLS; ++x) {
      int nbrs = count_nbrs(x, y);
      back[y][x] = front[y][x] ? (nbrs == 2 || nbrs == 3) : nbrs == 3;
    }
  }
}

int mod(int a, int b) {
  return (a%b + b)%b;
}

int count_nbrs(int cx, int cy) {
  int nbrs = 0;

  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      if (!(dx == 0 && dy == 0)) {
        int x = mod(cx + dx, COLS);
        int y = mod(cy + dy, ROWS);
        if (front[y][x]) nbrs += 1;
      }
    }
  }
  return nbrs;
}

int main(void) {
  //  012
  // 0.*.
  // 1..*
  // 2***

  front[0][1] = 1;
  front[1][2] = 1;
  front[2][0] = 1;
  front[2][1] = 1;
  front[2][2] = 1;
  for (;;) {
    display();
    next();
    memcpy(front, back, sizeof(front));
    // 27 putch "[" puts ROWS putu "A" puts
    // 27 putch "[" puts COLS putu "D" puts
    printf("\033[%dA\033[%dD", ROWS, COLS);
    // for (int i = 0; i < 10000000; ++i);
    usleep(100 * 1000);    // 100ms
  }
  return 0;
}
