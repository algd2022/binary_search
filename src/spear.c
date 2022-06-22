#include <stdio.h>

unsigned int n, k;
unsigned int A[100000];

unsigned int p(unsigned int x) {
  // 作ることのできる槍の総数
  // n個の要素の配列A
  unsigned int tmp = 0;
  for(unsigned int i = 0; i < n; i++) {
    tmp += A[i] / x;
  }
  return tmp;
}

int main() {
  scanf("%d%d", &n, &k);
  for(unsigned int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  unsigned int lb, ub;
  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1) {
    unsigned int mid = (lb + ub) / 2;
    unsigned int spears = p(mid);
    if(k <= spears) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%d\n", lb);

  return 0;
}
