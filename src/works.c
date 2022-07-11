#include <stdio.h>

int n;
int k;
int A[100000];


int sub(int x){ 
    int p = 0;
    int q = 0;
    for(int i = 0; i < n; i++){
        if(A[i] > x)
        return 0;
        if(q + A[i] > x){
            q = 0;
            p++;
        }
        q = A[i] + q;
    }
    if (q > 0)
      p++;
      return p <= k;
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
     int mid = (ub + lb) / 2;
     if(sub(mid))
         ub = mid;
      else
         lb = mid;
}
  printf("%d\n", ub);
  return 0;
}
