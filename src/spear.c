#include <stdio.h>

int n;
int k;
int A[100000];

//長さxの槍をk本作れるか判定する
int CanCreateSpear(int x){
  int Spears = 0;//今何本作ったか判定する
  int i;
  for (i = 0; i < n; i++){
    Spears += A[i] / x;
  }
  return Spears >= k;//k本以上作れたならOK
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  //初期値をそれぞれ定めるlb,ubをそれぞれ+1,-1するとCanCreateSpear()が常に成立、不成立しなくなる
  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(CanCreateSpear(mid)) {
      lb = mid;
    }
    else {
      ub = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
