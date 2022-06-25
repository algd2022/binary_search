#include <stdio.h>

int n;
int k;
int A[100000];

int possible(int work){ // calculates how many people will needed if each person work "work"
  int i, j, countppl;
  int max = A[0];
  for(i = 1; i<  n; i++){
    if(max < A[i]) max = A[i];
  }

  if(work < max)return 0;
  else{
    j = 0;
    countppl = 1;
    for(i = 0; i < n; i++){
      j += A[i];
      printf("%d %d\n", i, j);
      if(j == work && i != n-1){
        j = 0;
        countppl++;
      }else if(j > work){
        j = 0;
        countppl++;
        i--;
      }
    }
  }
  if(countppl <= k){
    printf("return 1\n");
   return 1;
  }
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = A[0];
  for(i = 1; i < n; i++){
    if(lb > A[i]) lb = A[i];
  }
  ub = 0;
  for(i = 0; i < n; i++){
    ub += A[i];
  }
  
  while(ub - lb > 1){
    int mid = (ub + lb +1) / 2;
    printf("mid: %d\n", mid);
    if(possible(mid)){
      printf("old ub: %d ", ub);
      ub = mid;
      printf("new ub: %d ", ub);
    }
    else{
      lb = mid;
      printf("failed lb: %d ", lb);

    }
  }
  printf("%d\n", ub);

  return 0;
}
