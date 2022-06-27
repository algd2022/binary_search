#include <stdio.h>

int n;
int k;
int A[100000];

int p(unsigned int x){
 int h = 0;
 int sum = 0;
 for(int i = 0 ; i < n ; i++){
  sum += A[i];
  if(A[i] > x) return 0;
  else if(sum > x){
   h++;
   sum = A[i];
  }
 }
 return h < k;
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
   
   if(p(mid)){
    ub = mid;
   }

   else{
    lb = mid;
   }
  }

  printf("%d\n" , ub);
  return 0;
}
