#include <stdbool.h>
#include <stdio.h>

int n;
int k;
int A[100000];

bool is_able_assign(int m) {
  int working_time = 0;
  int worker_id = 1;

  for (int i = 0; i < n; i++) {
    working_time += A[i];
    // 許容量を超過したら次の人に割り振る
    if (working_time > m) {
      // 単一の仕事量が設定した許容量より大きかったらfalseを返す
      if (A[i] > m) {
        return false;
      }

      // 人数超過したらfalseを返す
      if (++worker_id > k) {
        return false;
      }
      working_time = A[i];
    }
  }

  return true;
}

int main() {
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;

  while (ub > lb + 1) {
    int m = (lb + ub) / 2;

    if (is_able_assign(m)) {
      ub = m;
    } else {
      lb = m;
    }
  }

  printf("%d\n", ub);

  return 0;
}
