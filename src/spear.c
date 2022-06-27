#include <stdbool.h>
#include <stdio.h>

int n;
int k;
int A[100000];

bool is_able_length(int m) {
  if (m <= 0) {
    return true;
  }

  int sum_spear = 0;

  for (int i = 0; i < n; i++) {
    sum_spear += A[i] / m;

    if (sum_spear >= k) {
      return true;
    }
  }
  return false;
}

int main() {
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000001;

  while (ub > lb + 1) {
    int m = (lb + ub) / 2;

    if (is_able_length(m)) {
      lb = m;
    } else {
      ub = m;
    }
  }

  printf("%d\n", lb);

  return 0;
}
