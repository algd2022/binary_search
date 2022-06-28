#include <stdio.h>

int n;
int k;
int A[100000];

// hour以下働いてk人に分配できるかどうか
int work(int hour){

  int sum = 0, worker=1;
  for (int i = 0; i < n; i++){
    if(A[i] > hour){
      return 0;
    }
    sum += A[i];
    if(sum > hour){
      worker++;
      sum = A[i];
    }
  }

  return k >= worker;
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
    if(work(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);

  return 0;
}
