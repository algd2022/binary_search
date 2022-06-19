#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m) {
  int s = 0, i = 0;
  for(i = 0;i < n;i ++) {
    s += A[i] / m;
  }
  return s < k;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9+1;

  while(ub - lb > 1) {
    int m = (lb + ub) / 2;
    if(p(m)) ub = m;
    else lb = m;
  }

  printf("%d\n", lb);

  return 0;
}
