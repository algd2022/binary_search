#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum = 0;
  int i;
  for(i = 0; i < n; i++){
    sum += (A[i] + x - 1) / x;
  }

  return sum <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; //p(0)=0
  ub = 1000000000; //p(1e9)=1
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){ //バッグが足りた
      ub = mid; //もっと小さなx(バックに入れられるリンゴの数)を探す
    }
    else{ //バッグが足りなかった
      lb = mid; //もっと大きなx(バックに入れられるリンゴの数)を探す
    }
  }
  printf("%d\n", ub);


  return 0;
}
