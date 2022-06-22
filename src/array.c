#include <stdio.h>

unsigned int n, k;
unsigned int A[100000];


int main() {
  // 入力
  scanf("%d%d", &n, &k);
  for(unsigned int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  int lb, ub;
  lb = -1;
  ub = n;
  while(ub - lb > 1) {
    unsigned int mid = (lb + ub) / 2;
    if(A[mid] >= k) {
      ub = mid;
    } else {
      lb = mid;
    }
  }

  printf("%d\n", ub);

  return 0;
}
