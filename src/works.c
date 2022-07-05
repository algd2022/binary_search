#include <stdio.h>

//更新：初期値を変更、ｐ関数の不等号を調節しました。

int n;
int k;
int A[100000];

int p(int k1,int k2,int k3, int X[]){
    int i1 = 0;
    int i2 = 0;
    int sum = 0;
    while(i2<k1){
        sum += X[i2];
        if(sum + X[i2 + 1] <= k3){
            i2++;
        }    
        else if(sum <= k3 && i2 < k1-1 ){
            sum = 0;
            i1++;
            i2++;
        }
        else if(sum <= k3 && i2 == k1-1) i1++;
        else if(sum > k3) return 0;
        
    }
    if(i1 < k2 ) return 1;
    else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int u = 0;
  for(int i = 0;i<n;i++){
      u += A[i];
  }
  lb = 1;
  ub = 10000;
  while(ub - lb >1){
    int mid = ( lb + ub ) / 2;
    if(p(n,k,mid,A)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
