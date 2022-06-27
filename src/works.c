#include <stdio.h>

int n;
int k;
int A[100000];

/*
  仕事量の最大値について二分探索をする。
  仕事量 w:0 ~ 1e9(= 1e4 * 1e5) の範囲で、一人当たりの仕事量が w 以下になるように仕事を分配した時、k人で足りるかどうかを p とする。
*/

int p(int w){
  int i, works, worker;
  works = 0;
  worker = 1;
  for(i = 0; i < n; i++){
    if(w < A[i]) return 0;
    
    if(works + A[i] <= w){
      works += A[i];
    }
    else{
      worker++;
      works = A[i];
    }
  }
  return (long long int) worker <= k;
}

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
    else{
      lb = mid;
    }
  }

  printf("%d\n", ub);

  return 0;
}
