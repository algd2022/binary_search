#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub, max = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if(A[i] > A[max]) max = i;
  }

  if(n == k){
    lb = A[max];
    ub = A[max];
  }else{
    lb = 0;
    ub = 1e9;
  }

  while (ub - lb > 1){
    int able = 1;

    int mid = (lb + ub) / 2;
    int work = 0, p = 1;

    for(i = 0; i < n; i++){
      if(A[i] > mid){
        able = 0;
        break;
      }
      work += A[i];
      if(work > mid){
        p ++;
        work=A[i];
      }
    }
    if(p > k){
      able = 0;
    }


    if(able) ub = mid;
    else lb = mid;
  }

  printf("%d", ub);

  return 0;
}
