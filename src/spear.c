#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int m = 0;
    int i;
    for (i = 0; i < n; i++) {
        m += (A[i]) / x;
    }
    if (m >= k) {
        return 1; 
    }
     else 
        return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1000000001;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (p(mid)==0) {
          ub = mid;
      }
      else  lb = mid;
  }
  printf("%d/n", lb);
  return 0;
}
