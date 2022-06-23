#include <stdbool.h>
#include <stdio.h>

int n;
int k;
int A[100000];

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

    int sum_bag = 0;
    bool is_over = false;

    for (i = 0; i < n; i++) {
      sum_bag += (A[i] - 1) / m + 1;
      if (sum_bag > k) {
        is_over = true;
        break;
      }
    }

    if (is_over) {
      lb = m;
    } else {
      ub = m;
    }
  }

  printf("%d\n", ub);

  return 0;
}
