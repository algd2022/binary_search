#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i;
  int p0 = 0;
  for(i = 0; i < n; i++){
    p0 = p0 + A[i] / m;
  }
  return p0 >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 0;
  for(i = 0; i < n; i++){
    if (A[i] > ub) ub = A[i];
  }
  ub = ub + 1;

  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n", lb);


  return 0;
}
