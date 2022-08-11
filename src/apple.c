
#include <stdio.h>

int n;
int k;
int A[100000];

int sum(int i, int x){
 if(i >= 1){
     return sum(i - 1, x) + (x + A[i] -1) / x; 
  }
  else{
    return (x + A[0] -1) / x;
    }
}
     

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n ; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
      int mid = (lb + ub) / 2;
      if(sum(n, mid) <= k){
          ub = mid;
        }
      else {
          lb = mid;
        }
} 
  printf("%d\n", ub);
  return 0;
}
