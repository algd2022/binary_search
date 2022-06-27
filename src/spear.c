#include <stdio.h>
#include <stdlib.h>

int n;
int k;
int A[100000];

int is_ok(int m) {
  // (sum_1^n floor(a_i / m)) >= k
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += A[i] / m;
  }
  return s >= k;
}

int binary_search(int ng, int ok) {
  while (abs(ok - ng) > 1) {
    int mid = (ng + ok) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int main() {
  // lb と ub を変更しました
  // ng: 常に条件を満たさない
  // ok: 常に条件を満たす
  int i, ng, ok;

  // 入力とngの準備
  scanf("%d%d", &n, &k);

  // a_i の最大値より大きい数を ng をしてあげると、
  // x = ng は常に条件を満たさない(槍を作ることができない)
  ng = -1;
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    if (ng < A[i]) {
      ng = A[i];
    }
  }
  ng++;

  // 計算
  // x = 0 は常に条件を満たす
  ok = 0;

  int x = binary_search(ng, ok);

  // 出力
  printf("%d\n", x);

  return 0;
}
