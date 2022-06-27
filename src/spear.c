#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int m,int a[]){
  int i,y=0;
  for(i=0;i<n;i++){
    y += a[i]/m;
  }
  return  y < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1000000001;


  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }


  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(p(mid,A) == 1){
      ub = mid;
    }else{
      lb = mid;
    }
  }

  

printf("%d\n",lb);

  return 0;
}