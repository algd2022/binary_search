#include <stdio.h>

int n;
int k;
int A[100000];

int max(int n, int A[]) {
  int i, max = A[0];
  for(i = 1; i < n; i++){
    if(A[i] > max)
       max = A[i];
  }
  return max;
}

unsigned int p(int x, int A[]){
  int i, j, l, sum, B[k];
  l = 0;
  for(i = 0; i < k; i++){
     sum = 0;
     for(j = l; j < n-k+i+1; j++){
       sum + A[j]
       if(sum >= x && i < k-1){
         break;
       }
     }
     B[i] = sum;
     l = j + 1;
  }
  return max(n, B) <= x;
}

int main(){
  int i, lb, ub, s=0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    s += A[i];
  }
  lb = max(n, A) - 1;
  ub = s;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(mid, A)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
