#include <stdio.h>

unsigned int bsearch(int A[], unsigned int x, unsigned int n){
  int lb = -1;
  int ub = n;
  while(ub-lb>1){
    int mid = (ub + lb)/2;
    if(A[mid] >= x){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  return ub;
}

int main(){
  int n;
  int k;
  int A[100000];

  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  printf("%d%n", bsearch(A, k, n));
  return 0;
}
