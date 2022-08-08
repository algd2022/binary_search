#include <stdio.h>

int n;
int k;
int A[100000];
//2 2 1 1 とかで動かないらしい
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
  
  //all lb valuables will not satisfy possible(lb)==1
  //except when initialized lb satisfies possible(lb)==1 
  if(possible(lb)==1)printf("%d\n", lb);
  else{
    while(ub - lb > 1){
      int mid = (ub + lb) / 2;
      if(possible(mid)){
        ub = mid;
     }
      else{
        lb = mid;
      }
    }
    printf("%d\n", ub);
  }

  return 0;
}
