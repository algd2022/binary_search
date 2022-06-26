#include <stdio.h>

int n;
int k;
int A[100000];

int num(int x){
  int sum = 0;
  int i;
  for(i = 0; i < n; i++){
    sum += (A[i] + x - 1) / x;
  }

   if (sum <= k){

     return 1; 
   }
  
   else{
     return 0;
   }
} 


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

lb = 0;
ub = 1e9; /* maximum number of apple picked up is ub*/
while(ub - lb > 1) {
  int mid = (ub + lb) / 2;
   if (num(mid)){
     ub = mid;
   }
   else {
     lb = mid;
   }
 }
  
  printf("%d\n", ub);
  return 0;
}
