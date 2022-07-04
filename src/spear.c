#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sgm = 0;
  int i;
  for (i=0; i < n; i++){
    sgm += A[i] / x;
  }
  return sgm >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

int mid;
lb = 0;
ub = 1000000000 + 1;
while (ub - lb > 1) {
    mid = (lb + ub) / 2;
    if (p(mid)){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
} 
