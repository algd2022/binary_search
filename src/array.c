#include <stdio.h>

//更新：ファイルを入れ替えました。

int n = 0;
int k = 0;
int A[100000];

int p(int i1,int i2,int X[]){
  return X[i2] >= i1;
}

int main(){
  int i, lb, ub = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1;
  ub = n;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(k,mid,A)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
