#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int m){
  int y=0;
  for (int i = 0; i < n; i++) {
            y += (A[i] + m - 1) / m;
        }
  return  y <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1000000000;


  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }



  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(p(mid) == 1){
      ub = mid;
    }else{
      lb = mid;
    }
  }

  

printf("%d\n",ub);

  return 0;
}
