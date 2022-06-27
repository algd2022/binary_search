#include <stdio.h>

int n;
int k;
int A[100000];

int p(int i, int x){
 if(i == 0){
      return A[0] / x;
    }
 else {
     return p(i - 1, x) + A[i] / x;
  }
}
  

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
 lb = 0;
 ub = 100001;
 while(ub - lb > 1){
     int mid = (ub + lb) / 2;
     if(p(n, mid) >= k){
         lb = mid;
      }
     else {
         ub = mid;
      }
    }
  printf("%d\n", lb);
  return 0;
}