#include <stdio.h>

int n;
int k;
int A[100000];

//バッグの容量xに対しk個以下で持ち帰れるか判定する
int CanBring(int x) {
  int Bags = 0;
  int i;
  for (i = 0; i < n; i++){
    Bags += (A[i] + x - 1) / x;
  }
  return Bags <= k;//k個以下なら持ち帰れる
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

//初期値をそれぞれ定めるlb,ubをそれぞれ+1,-1するとCanBringが常に不成立、成立しなくなる
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(CanBring(mid)) {
      ub = mid;
    }
    else 
      lb = mid;
  }

  printf("%d\n", ub);
  return 0;
}
