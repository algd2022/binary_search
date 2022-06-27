#include <stdio.h>

int n;
int k;
int A[100000];

/*一番仕事量の多い人の仕事量をxとした時に、n時間の仕事すべてを終わらせるのに必要な人数がkを上回るか判別する。*/
int p(int x){
  int i;
  int total = 0;/*ある人の行う仕事量の小計*/
  int sum = 1;/*仕事をする人数のカウント*/
  for(i = 0; i < n; i++){
    if(A[i] > x)
      return 0;
    if(total + A[i] > x){/*仕事量の小計がxを上回ったら小計をi番目の仕事量にして、次の人ができる仕事量について考えるので人数のカウントを増やす。*/
      total = (A[i]);
      sum += 1;
    }
    else{/*仕事量の小計がxを上回ってなければ次の仕事量も足して判定する。*/
      total += A[i];
    }
  }
  return sum <= k;
}

/*p(x)についてxの取りうる値の最小値は1であるからlb = 1 - 1 = 0*/
/*xが最大値をとるのは、仕事が1e5時間あってすべての仕事の仕事量が1e4であり一人しかいない場合であるから、ub = 1e9*/
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
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
  }
  return 0;
}
