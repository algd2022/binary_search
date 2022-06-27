#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int m,int y){
  return  (y+m-1)/m <= k;
}

int main(){
  int i, lb, ub,y=0;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1000000000;


  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  for(i=0;i<n;i++){
    y+= A[i];
  }

  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(p(mid,y) == 1){
      ub = mid;
    }else{
      lb = mid;
    }
  }

  

printf("%d\n",ub);

  return 0;
}
