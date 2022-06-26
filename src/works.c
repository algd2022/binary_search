#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int x){
  int i, workernum, work_volume;
  workernum = 1;
  work_volume = 0;
  for(i = 0;i < n;i++){
    if(work_volume + A[i] > x){
      if(A[i] > x){
        return 0;
      }
      work_volume = 0;
      workernum += 1;
    }
    work_volume += A[i];
  }
  if(workernum <= k){
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
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if (p(mid) == 1){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n" , ub);
  return 0;
}