#include <stdio.h>

int n;
int k;
int A[100000];

int cond(int x) {
  if (x < 1)
    return 1;

  int a = 0;
  for (int i = 0; i < n; ++i) 
    a += A[i] / x;
  return a >= k;
}


int main(){
  int i, lb, ub;
  lb = 0; // the largest number that cond(x) == true
  ub = 0; // the smallest number that cond(x) == false

  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if (A[i] > ub)
      ub = A[i];
  }
  ++ub; // set ub to max(A) + 1, so one can craft no spear (less than the required k witn minimum value of 1)

  int mb;
  while (ub - lb > 1) {
    mb = lb + (ub - lb) / 2;
    if (cond(mb))
      lb = mb;
    else
      ub = mb;
  }

  printf("%d\n", lb);

  return 0;
}
