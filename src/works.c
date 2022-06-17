#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m) {
  int i, tsum, hnum;
  tsum = 0;
  hnum = 1;

  for (i = 0; i < n; i++) {
    if (A[i] > m) {
      return 0;
    } else if (tsum + A[i] <= m) {
      tsum += A[i];
    } else {
      tsum = A[i];
      hnum++;
    }
  }
  
  return hnum <= k;
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
