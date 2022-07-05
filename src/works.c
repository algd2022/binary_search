#include <stdio.h>

int n;
int k;
int A[100000];

/* total・仕事量の総量 how_many・人数の総量 As_whole・一人当たりの仕事量 */

int total(int x){ 
  int how_many = 1; 
  int As_whole =0; 
  for(int i = 0; i < n; i++){
    if(A[i] > x) {
      return 0; 
    }
    else if (As_whole + A[i] <= x){
       As_whole += A[i]; 
    }
    else{
      how_many += 1; 
      As_whole = A[i];
    }
  }
 return how_many <= k;
} 


int main(){
  int i, lb, ub;
  lb = 0;
  ub = 1000000000;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  while (ub - lb > 1){
    int mid = (lb + ub) / 2;
    if (total(mid)){
     ub = mid;
    }
    else {
     lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}