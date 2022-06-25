#include <stdio.h>

int n;
int k;
int A[100000];

  int p(int m){
  	int sigma = 0;
      int j;
      for (j=0; j<n; j++){
      sigma = sigma + A[j]/m;
      } 
      return sigma >= k;
      }

int main(){
  int i, lb, ub;
  lb = 0;
  ub = 1000000001;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
   while(ub - lb > 1){
	int mid = (lb + ub) / 2;  
     
	if( p(mid)) {
      lb = mid;
      }
	else {
      ub = mid;
      }
  }
  printf ("%d\n" , lb);

  return 0;
}
