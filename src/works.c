#include <stdio.h>

int n;
int k;
int A[100000];
int p(int x){
  int i;
  int j = 0;
  int p=1;
  for(i = 0; i<n; i++){
    j += (A[i]);
    if(A[i] > x) return 0;
    if(j > x){
      j = A[i];
      p += 1;
      if(p > k) return 0;

    }
  } 
  return 1;
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
      if(p(mid) == 1) ub = mid;
      else lb = mid;
    }
  printf("%d\n", ub);

  return 0;
}
