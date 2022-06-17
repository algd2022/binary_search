#include <stdio.h>

#define ceil_div(x, y) ((x + y - 1) / y)

int n;
int k;
int A[100000];

int cond(int x) {
  int p = 0;
  int w = 0;
  int a;
  for (int i = 0; i < n; ++i) {
    a = A[i];
    if (a > x)
      return 0;
    if (w + a > x) {
      w = 0;
      ++p;
    }
    w += a;
  }
  if (w > 0)
    ++p;
  return p <= k;
}


int main(){
  int i, lb, ub;
  lb = 0; // false
  ub = 1; // true
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    ub += A[i];
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
