#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int binary_search(int A[], int x, unsigned int l, unsigned int r){
  unsigned int m;
  if(x > A[r]) return r+1;
  if(l == r) return r;
  m = (l + r)/2;
  if(A[m] >= x) return binary_search(A, x, l, m);
  else return binary_search(A, x, m+1, r);
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = n-1;
  printf("%u", binary_search(A, k, lb, ub));
  return 0;
}
