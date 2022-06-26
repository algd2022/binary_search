#include <stdio.h>

unsigned int n, k;
unsigned int A[100000];

unsigned int p(unsigned int x) {
  unsigned int divs = 1;
  unsigned int sum = 0;
  for(unsigned int i = 0; i < n; i++) {
    if(sum + A[i] <= x) {
      sum += A[i];
    } else {
      divs += 1;
      sum = A[i];
    }
  }
  return divs;
}

int main() {
  unsigned int lb = 0;
  unsigned int ub = 1000000001;

  scanf("%d%d", &n, &k);
  for(unsigned int i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if(A[i] > lb) {
      lb = A[i];
    }
  }
  lb -= 1;

  while(ub - lb > 1) {
    unsigned int mid = (lb + ub) / 2;
    if(p(mid) <= k) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
