#include <stdio.h>

int n;
int k;
int A[100000];

// x個入るバッグをk個配ると全員がりんごを持って帰れるかどうが
unsigned int p(int x){
  int sum = 0;
  for (int i = 0; i < n; i++) {
    //必要なバッグの合計を計算する
    sum += (A[i] + x -1)/x;
  }
  //持って帰れるならtrue
  return sum <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
      if(p(mid)) {
        ub = mid;
      } else {
        lb = mid;
      }
  }
  printf("%d\n", ub);

  return 0;
}
