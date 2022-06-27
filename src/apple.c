#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m) {
  // (sum_i^n ceil(a_i / m)) <= k
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += (A[i] + m - 1) / m;
  }
  return s <= k;
}

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
  // 入力・ubを決める
  int i, lb, ub;
  scanf("%d%d", &n, &k);

  // ub は a_i の最大値とする
  ub = -1;
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    if (ub < A[i]) {
      ub = A[i];
    }
  }

  // 計算
  lb = 0;

  int x = binary_search(lb, ub);

  // 出力
  printf("%d\n", x);

  return 0;
}
