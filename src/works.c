#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int sum = 1,p = 0, m = 1;
    for(int i=0; i < n; i++)
        if(x < A[i]){
          return 0;
            
        }
        else if(m + A[i]<= x){
          m = m + A[i];
            
        }
        else {
          m = A[i];
          sum++;
            
        }

}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb  = 0;
  ub = 1000000;
  while (ub - lb > 1){
    int mid = (ub + lb) / 2;
    if (p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }


  return 0;
}
