#include <stdio.h>


//更新：ファイルの入れ替えをしました
int n;
int k;
int A[100000];

int p(int i1, int i2, int i3,int X[]){
  int sum = i1;
  for(int m = 0; m < i1; m++){
    sum += (A[m] - 1) / i3;
  }
  return  sum > i2;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb >1){
    int mid = (lb + ub ) / 2;
    
    if(p(n,k,mid,A) ) lb = mid;
    else ub = mid;
  }
  printf("%d\n", ub);

  return 0;
}
