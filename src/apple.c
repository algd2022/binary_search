#include <stdio.h>

int n;
int k;
int A[100000];
//x個のりんごが入るバッグがk個で足りるかを返す関数
int enough_bags(int x){
  int i, sum = 0;
  for(i = 0 ; i < n; i++){
    sum += (A[i] + x - 1) / x ; //小数点以下は切り上げる
  }
  return sum <= k ;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //xの最小値は1のため、そこから1を引いた0が初期値
  ub = 1e9; //制約から考えられるxの最大値10^9が初期値
  while(ub - lb > 1){ //バッグに入るりんごの個数について二分探索
    int mid = (lb + ub) / 2;
    if(enough_bags(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n",ub);
  return 0;
}
