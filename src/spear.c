#include <stdio.h>

int n;
int k;
int A[100000];
int count;
int p(int center){
  count = 0;
  int i;
  for(i = 0; i < n; i++){
    count += A[i]/center;
 
    }
  return count < k;
}
int main(){
  int i, lb, ub,max_a;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
   if (max_a <A[i]){
    max_a = A[i];
   }
  }
lb = 0;
ub =max_a + 1;
while(ub - lb > 1) {
  int mid = (ub + lb) /2;
  if(p(mid)){
    ub = mid;
  }
 else{
    lb =mid;
  }
 }
  printf("%d\n",lb);
  return 0;
 
}
