#include <stdio.h>

int n;
int k;
int A[100000];


int cond(int i) {
  if (i < 0)
    return 0;
  else if (i >= n)
    return 1;
  else 
    return A[i] >= k;
}

int main(){
  int i, lb, ub; 
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = -1;
  ub = n;
  int mb, c;
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
