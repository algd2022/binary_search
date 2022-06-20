#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int n, int k, int mid) {
  int spear_n = 0;
  for (int i = 0; i < n; i++) {
    spear_n += A[i] / mid;
  }
  if (spear_n >= k) {
    return 1;
  }
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  int mid;
  lb = 0;
  ub = 1000000001;
  while (ub - lb > 1){
    mid = (lb + ub) / 2;
    if (p(A, n, k, mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n", lb);

  return 0;
}
