#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i, j, l, o, p;
  int B[k];
  int C[k];
  B[k - 1] = 0;
  for(i = 0; i < k - 1; i++){
    B[i] = A[i];
    C[i] = 1;
  }
  for(j = k - 1; j < n; j++){
    B[k - 1] = B[k - 1] + A[j];
  }
  C[n - k] = n - k + 1;

  for(l = 0; l < k; l++){
    if(B[l] <= m){
      if(l == k - 1) return B[l] <= m;
    }
    else {
      if((C[l] == 1) || (l == 0)) return B[l] <= m;
      p = 0;
      for(o = 0; o < l; o++){
        p = p + C[o];
      }
      B[l] = B[l] - A[p];
      B[l - 1] = B[l - 1] + A[p]; 
      C[l] = C[l] - 1;
      C[l - 1] = C[l - 1] + 1;
      l = l - 2;
    }
  }
  return 0;
}

/* pの計算量はO(n * (2 ** n)) */

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 10000 * (n - k + 1);
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
