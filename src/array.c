#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m) { return A[m] >= k; }

int binary_search(int lb, int ub) {
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  return ub;
}

int main() {
  int i, lb, ub;

  // 入力
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  // 計算
  lb = -1;
  ub = n;

  int x = binary_search(lb, ub);

  // 出力
  printf("%d\n", x);

  return 0;
}
