#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub, sum = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    sum = sum + A[i];
  }
  lb = -1;
  ub = n;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    int capa = sum / k;
    if(A[mid] > capa) {
        ub = mid;
    }
    else {
        lb = mid;
    }
  }
  printf("%d\n", A[ub]);
  return 0;
}