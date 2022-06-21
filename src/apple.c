#include <stdio.h>

int n;
int k;
int A[100000];

int p(int a[], int x) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        sum += (a[i] + x - 1) / x;
    }
    if (sum <= k) return 1;
    else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ub = 1000000000;
  lb = 0;
  while (ub - lb > 1) {
      int mid = (ub + lb) / 2;
      if (p(A, mid) == 1) {
          ub = mid;
      }
      else lb = mid;
  }
  printf("%d", ub);
  

  return 0;
}
