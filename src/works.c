#include <stdio.h>
#include <stdlib.h>

int n;
int k;
int A[100000];
int B[100000];  // 累積和
int k_2;

int is_ok_2(int m) { return k_2 >= B[m]; }

int binary_search(int ng, int ok, int (*is_ok_ptr)()) {
  while (abs(ok - ng) > 1) {
    int mid = (ng + ok) / 2;
    if (is_ok_ptr(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int is_ok(int m) {
  // x = m のときに仕事を配分できるかを考える
  // is_ok の計算の流れ
  // Step 1. i = 0 とおく
  // Step 2. 累積和 B[j] について， B[j] <= x + B[i] < B[j + 1]
  //         となるような j を二分探索で求める
  // Step 3. i = j として，Step 2 を実行する
  // Step 4. (Step 2 と Step 3) を k 回繰り返す
  // Step 5. k 回繰り返すまでに i == n となれば条件を満たす

  int i = 0;
  int ng = n + 1;
  int ok = 0;
  k_2 = m;
  for (int a = 0; a < k; a++) {
    i = binary_search(ng, ok, is_ok_2);
    if (i == n) {
      return 1;
    }
    k_2 = m + B[i];
    ok = i;
  }
  return 0;
}

int main() {
  // lb と ub を変更しました
  // ng: 常に条件を満たさない
  // ok: 常に条件を満たす
  int i, ng, ok;

  // 下のように ng, ok を設定する
  // ng: 0 -> 条件を満たさない
  // ok: a_i の合計 -> 条件を満たす

  // 入力, 累積和を求める
  scanf("%d%d", &n, &k);

  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    B[i + 1] = A[i] + B[i];
  }

  // 計算
  ok = B[n];
  ng = 0;

  int x = binary_search(ng, ok, is_ok);

  // 出力
  printf("%d\n", x);

  return 0;
}
