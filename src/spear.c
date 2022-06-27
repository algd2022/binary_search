#include <stdio.h>

int n;
int k;
int A[100000];
//長さxの槍をk本作ることができるかを返す関数。xについて単調非増加である。(1,...,1,0,...,0)
int enough_spears(int x){
  int i, sum = 0;
  for(i = 0; i < n; i++){
    sum += A[i] / x ; //小数点以下は切り捨てる
  }
  return sum >= k ;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //lb = [enough_spears(lb)=1となる最大の整数]
  ub = 1e9 + 1; //ub=[enough_spears(ub)=0となる最小の整数]
  while(ub - lb > 1){ //作る槍の長さについて二分探索
    int mid = (ub + lb) / 2;
    if(enough_spears(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n",lb); //求める答えはlbであることに注意

  return 0;
}
