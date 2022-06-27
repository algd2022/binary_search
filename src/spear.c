#include <stdio.h>

int n;
int k;
int A[100000];

/*槍の長さをxとした時に作れる槍の総数がkを上回るか判別する。*/
int p(int x){
  int i;
  int sum = 0;
  for(i = 0; i < n; i++){
    sum += (A[i]) / x;/*槍の長さをxとすると、i番目の木から作れる槍の数はA[i] / xを切り捨てたものである。*/
  }
  return sum >= k;
}

/*返す値がlbであるから*/
/*lbはlb <= xであることが分かっている最大の数*/
/*ubはub > xであることが分かっている最小の数*/
/*p(x)について、槍が作れない場合も考慮りてxの取りうる値の最小値は0であるからlb = 0*/
/*xが最大となるのは木が一本につき一つしか槍を作れなくて、どれかの木が入力制約範囲内で最大の長さである場合だから、ub = 1 + 1e9*/
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1 + 1e9;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      lb = mid;
    }
    else {
      ub = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
