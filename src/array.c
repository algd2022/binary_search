#include <stdio.h>

int n;
int k;
int A[100000];

/* define p to simplify code */

int p(int m){
  return (long long int) A[m] >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

/* lb and ub is the outside number of the array */

lb = -1;
ub = n;
while(ub - lb > 1) {
  int mid = (ub + lb) / 2;
   if (p(mid)){
     ub = mid;
   }
   else {
     lb = mid;
   }
 }
  
  printf("%d\n", ub);

  return 0;
}
