#include <stdio.h>

#define ceil_div(x, y) ((x + y - 1) / y)

int n;
int k;
int A[100000];

int cond(int s) {
  int t = k;
  for (int i = 0; i < n; ++i)
    t -= ceil_div(A[i], s);
  return t >= 0;
}


int main(){
  int i, lb, ub;

  lb = 0;
  ub = 1;

  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if (A[i] > ub)
      ub = A[i];
  }

  
  int mb;
  while (ub - lb > 1) {
    mb = lb + (ub - lb) / 2;
    if (cond(mb))
      ub = mb;
    else
      lb = mb;
  }
  printf("%d\n", ub);
  return 0;
}
