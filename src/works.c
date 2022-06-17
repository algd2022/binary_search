#include <stdio.h>

int n;
int k;
int A[100000];


int p(int m){
  int i;
  int j = 1;
  int l = m;
  for(i = 0; i < n; i++){
    if(m < A[i] || j > k){
      return 0;
    }else if(A[i] > l){
      l = m - A[i];
      j = j + 1;
    }else{
      l = l - A[i];
    }
  }
  if(j > k) return 0;
  else return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
    lb = 0;
    ub = 1000000000;
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if (p(mid)){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    printf("%d\n", ub);
  return 0;
}
