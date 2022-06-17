#include <stdio.h>

int n;
int k;
int A[100000];


int p(int m){
  int i;
  int j = 0;
  for(i = 0; i < n; i++){
      if(j >= k){
        return 0;
      }else{
          if(A[i] % m == 0) j = j + (A[i] / m);
          else j = j + 1 + (A[i] / m);
      }
  }
  return j <= k;
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
