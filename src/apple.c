#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, max;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    
  }
  for(i = 0; i < n; i++){
    if(A[i] > max) max = A[i];
  }
  
  int lb = 0;
  int ub = max;
  while (ub - lb > 1){
  int mid = (lb + ub ) / 2;
  int bag=0;
  for(i = 0;i < n; i++){
      int j = 1;
      while(j*mid < A[i]){
        j++;
      }
      bag += j;
  }

  if (k >= bag) ub = mid ;
  else lb = mid ;
}

printf("%d", ub);

  return 0;
}
