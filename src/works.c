#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i,num_1 = 0,num_2 = 1,B[100000],max;
  for(i = 0;i < n; i++ ){
    if(num_1+ A[i] <= m){
      num_1 = num_1 + A[i];
      B[i] = num_1;
    }else{
      num_1 = A[i];
      B[i] = A[i];
      num_2++;
    }
  }
  max = B[0];
  for(i = 0; i < n;i++){
    if(max < B[i]){
      max = B[i];
    }
  }
   
  return (num_2 <= k && max <= m);
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
      ub = mid ;
    }else{
      lb = mid;
    }
  }
  printf("%d\n",ub);
  


  return 0;
}