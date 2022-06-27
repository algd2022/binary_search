#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){ //バッグに入るりんごの数がxのとき、バッグの数が足りれば1、足りなければ0を返す関数
  int bag = 0; //バッグにx個りんごが入るとき、必要なバッグの数
  int i;
  for(i=0 ; i<n ; i++){
    bag = bag + (A[i] + x - 1) / x;
  }
  if(bag <= k){ //バッグの数kが必要な数以上ある
    return 1;
  }
  else{
    return 0;
  }
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
    if (p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
