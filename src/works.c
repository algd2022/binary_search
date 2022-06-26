#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum = 0;
  int nop = 1;
  for(int i = 0; i < n; i++)
    if(sum + A[i] > x){
      sum = A[i];
      nop += 1;
    }
    else if(sum + A[i] <= x){
      sum += A[i];
    }
  return nop <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int max = 0;
  for(i = 0; i < n; i++){
    if(max < A[i])
      max = A[i];
  }
  lb = max;
  ub = 10000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  if(p(ub-1))
    ub -= 1;
  }
  printf("%d\n", ub);
  return 0;
}
