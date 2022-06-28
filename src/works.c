#include <stdio.h>

int n;
int k;
int A[100000];

int p(int everywork){
  int worksum = 0,man = 1,i;
  for(i = 0;i < n;i++){
    //1人当たりの仕事量をある時間の仕事量が超えてしまっている場合０を返す
    if(A[i] > everywork) return 0;
    worksum += A[i];
    if (worksum > everywork){
    //1人当たりの仕事量である時間の仕事を実行できない場合次の人に交代し人数を数える
      man += 1;
      worksum = A[i];
    }
  }
  return man <= k;
}

int main(){
  int i, lb, ub;
  printf("n? k?\n");
  scanf("%d%d", &n, &k);
  printf("A[i]?\n");
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("x = %d\n",ub);
  return 0;
}
