#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 0;
  for(i = 0; i < n; i++){
    ub = ub + A[i];
    if(lb < A[i]){
      lb = A[i];
    }
  }
  lb = lb - 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    int completed_work = 0;
    for(i = 0; i < k; i++){
      int works = 0;
      for(int j = completed_work; j < n; j++){
        works = works + A[j];
        if(works > mid){
          completed_work = j;
          break;
        }
        if(j == n - 1){
          completed_work = n;
          break;
        }
      }
      if(completed_work == n){
        ub = mid;
        break;
      }
    }
    if(completed_work < n){
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
