#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int bsearch(int A[], int x, unsigned int l, unsigned int r) {
    unsigned int m;
    if (l >= r) return r;
    m = (l + r) / 2;
    if (A[m] >= x) return bsearch(A, x, l, m);
    else return bsearch(A, x, m + 1, r);
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = n;

  int x = bsearch(A, k, lb, ub);

  printf("%d\n", x);

  return 0;
}
