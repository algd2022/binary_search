#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int work = 0;
  int ifwork = 0;
  int worker = 1;
  int i;
  for(i = 0; i < n; i++){
    ifwork = work + A[i];
    if(x < A[i]){
      return 0; //iの仕事が行えない
    }
    else if(ifwork <= x){
      work = ifwork; 
    }
    else{
      worker++;
      work = A[i]; //iの仕事は次の人が行う
    }
  }

  return worker <= k;
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
    if(p(mid)){ //仕事をする人の数が足りた
      ub = mid; //もっと小さなx(一人での最大仕事量)を探す
    }
    else{ //仕事をする人の数が足りなかった or ある仕事iが行えなかった
      lb = mid; //もっと大きなx(一人での最大仕事量)を探す
    }
  }
  printf("%d\n", ub);

  return 0;
}
