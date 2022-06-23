#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    return A[m]>=k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  //-1 is out of range of index of A, so it cannot be answer

  //if all members of A are not smaller than k, then -1+1=0 is the answer

  lb=-1;

  //a[n] is set to be infinite,so a[n] must be greater than k

  //if all members of A are smaller than k,then n-1 is not the answer
   
  ub=n;
  while (ub-lb>1){
      int mid=(ub+lb)/2;
      if (p(mid)){
          ub=mid;
      }
      else{
          lb=mid;
      }
  }
  printf("%d\n",ub);

  return 0;
}