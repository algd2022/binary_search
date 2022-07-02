#include <stdio.h>

int n;
int k;
int A[100000];

int p(int a) {
    if (a >= k) return 1;
    else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = -1;
  ub = n;
  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (p(A[mid]) == 1) {
          ub = mid;
      }
      else lb = mid;
  }
  printf("%d\n", ub);
  
  
  return 0;
}
