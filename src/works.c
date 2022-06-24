#include <stdio.h>

int n;
int k;
int A[100000];

int dw(int x){
  int pc = 0;
  int i = 0;
  while (pc <= k && i != n - 1){
    int wc = 0;
    while (wc <= x && i < n){
      wc = wc + A[i];
      i = i + 1;
    }
    i = i - 1;
    pc = pc + 1;
  }
  if(i == n - 1){
    return 1;
  }
  else if (pc > k){
    return 0;
  }
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ub = 10000 * n;
  lb = 0;
  int m = (ub + lb)/2;
  while (ub - lb > 1){
    if (dw(m)){
      ub = m;
    }
    else {
      lb = m;
    }
  }
  printf("%d\n", ub);
  return 0;
}
