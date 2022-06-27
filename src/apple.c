#include <stdbool.h>
#include <stdio.h>

int n;
int k;
int A[100000];

bool is_bag_enough(int m) {
  int sum_bag = 0;

  for (int i = 0; i < n; i++) {
    sum_bag += (A[i] - 1) / m + 1;
    if (sum_bag > k) {
      return false;
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

    if (is_bag_enough(m)) {
      ub = m;
    } else {
      lb = m;
    }
  }

  printf("%d\n", ub);

  return 0;
}
