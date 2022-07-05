#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int n;
int k;
int A[100000];

bool can(int x){
  int people_need = 0, sum = 0;
  for(int j=0; j < n; j++){
    if(A[j] > x){
      return false;
    }else if(sum + A[j] > x){
      people_need++;
      // printf("person %d works %d\n", people_need, sum);
      sum = 0;
    }
    sum += A[j];
  }
  people_need++;
  if(people_need <= k){
    // printf("max work %d can\n", x);
    return true;
  }else{
    // printf("max work %d cannot\n", x);
    return false;
  }
}

int main(){
  int i, lb=0, ub=pow(10,9), mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  // //for upper limit test
  // n = pow(10, 5);
  // k = 1;
  // for(i=0;i<n;i++){
  //   A[i] = pow(10,4);
  // }


  while(ub - lb > 1){
    mid = (ub + lb) / 2;
    if(can(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  // printf("%d\n", lb);
  printf("%d\n", ub);

  return 0;
}
