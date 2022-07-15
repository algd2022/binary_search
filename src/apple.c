#include <stdio.h>

int n;
int k;
int A[100000];

/*バッグに入るリンゴの数をxとした時に必要なバッグの総数がkを上回るかどうか判別する。*/
int p(int x){
  int i;
  int sum = 0;
  for(i = 0; i < n; i++){
    sum += (A[i] + x - 1) / x;/*バッグに入るリンゴの数をxとすると、i番目の人が必要なバッグの数はA[i] / xを切り上げたものである。*/
  }
  return sum <= k;
}

/*p(x)についてxの取りうる値の最小値は1であるからlb = 1 - 1 = 0*/
/*xが最大となるのは一人につきバッグが一つしかなく、誰かがリンゴを入力制約範囲内で最大個数収穫した場合であるから、ub = 1e9*/
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
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
