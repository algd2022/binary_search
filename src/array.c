#include <stdio.h>

int n;
int k;
int A[100000];

int main(){
  int i;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  int lb = 0;
  int ub = n;

  while (ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(A[mid] >= k) ub = mid;
    else lb = mid;
  } 

  printf("%d", ub);
  
  return 0;
}
