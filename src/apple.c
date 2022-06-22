#include <stdio.h>

unsigned int division_round_up(unsigned int a, unsigned int x) {
  // 切り上げ除算(a/x)
  return (a + x - 1) / x;
}

unsigned int n, k;
unsigned int A[100000];

unsigned int p(unsigned int x) {
  // リンゴバッグの容量をxとしたときに何個のカバンが必要か
  // n個の要素の配列A
  int tmp = 0;
  for(unsigned int i = 0; i < n; i++) {
    tmp += division_round_up(A[i], x);
  }
  return tmp;
}

int main() {
  // 入力
  scanf("%d%d", &n, &k);
  for(unsigned int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  int lb, ub;
  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1) {
    unsigned int mid = (lb + ub) / 2;
    unsigned int bags = p(mid);
    if(bags <= k) {
      ub = mid;
    } else {
      lb = mid;
    }
  }

  printf("%d\n", ub);

  return 0;
}
