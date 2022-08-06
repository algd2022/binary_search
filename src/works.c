#include <stdio.h>

int n;
int k;
int A[100000];

int dw(int x){
  int pc = 0;
  int i = 0;
  int wc;
  while (pc < k && i < n){
    wc = 0;
    while (wc <= x && i <= n-1){
      wc = wc + A[i];
      i = i + 1;
    }
    i = i - 1;
    pc = pc + 1;
  }
  if (pc == k && wc > x){
    return 0;
  }
  else{
    return 1;
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
  while (ub - lb > 1){
    int m = (ub + lb)/2;
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
