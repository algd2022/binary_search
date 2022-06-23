#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum = 0;
  int i;
  for(i = 0; i < n; i++){
    sum += A[i] / x;
  }

  return sum >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  lb = 0; //p(0)=1
  ub = 1000000001; //p(1e9+1)=0
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){ //k本作れた
      lb = mid; //もっと大きなx(槍の長さ)を探す
    }
    else{ //k本作れなかった
      ub = mid; //もっと小さなx(槍の長さ)を探す
    }
  }
  printf("%d\n", lb);


  return 0;
}
