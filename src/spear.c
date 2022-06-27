#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){//k本以上作れるとき1、作れないとき0を返す関数
  int spear = 0; //やりの長さxのときに作れる槍の数
  int i;
  for(i = 0; i < n; i ++){
    spear = spear +A[i] / x;
  }
    if(spear >= k){
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

  lb = 0; //どのような入力でもp(x)=1になる中で最大のx
  ub = 1e9 + 1; //どのような入力でもp(x)=0となる中で最小のx

  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }
  printf("%d\n", lb); 
  return 0;
}
