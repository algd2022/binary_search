#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m) {
  int i, k_rest;
  k_rest = k;

  for (i = 0; i < n; i++) {
    k_rest -= A[i] / m;
    if (A[i] % m != 0) {
      k_rest--;
    }  
  }
  
  return k_rest >= 0;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;

  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;

    if (p(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }

  printf("%d\n", ub);

  return 0;
}
