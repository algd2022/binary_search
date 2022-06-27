#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){ // xは最大仕事量
  int workers = 1;
  int amt = 0;
  for(int i = 0; i < n; i++){
    if(A[i] > x){
      return 0;
    }
    else if(amt + A[i] > x){
      workers++;
      amt = A[i];
    }
    else{
      amt += A[i];
    }
  }
  return k >= workers;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n" , ub);

  return 0;
}