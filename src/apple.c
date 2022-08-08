#include <stdio.h>

int n;
int k;
int A[100000];

int main(){
  int i, lb, ub, mid, max = 0;
  
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if(A[i] > A[max]){
      max = i;
    }
  }

  lb = 0;
  ub = A[max];

  while(ub - lb > 1){
    int l = k;
    mid = (lb + ub) / 2;
    for(i = 0; i < n; i++){
      l -= (A[i] + mid - 1) / mid;  //切り上げ
    }
    if(l >= 0)ub = mid;
    else lb = mid;
  }

  printf("%d", ub);

  return 0;
}
