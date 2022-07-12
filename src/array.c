#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub, mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  if(A[n-1] < k) printf("%d\n",n);
  else if(k <= A[0]) printf("0\n");
  else{
    lb = -1;
    ub = n;
    while(ub-lb>1){
      mid = (ub+lb)/2;
      if(A[mid]>k) ub = mid;
      else lb = mid;
    }
    printf("%d\n", ub);
  }

  return 0;
}
