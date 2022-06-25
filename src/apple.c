#include <stdio.h>

int n;
int k;
int A[100000];

 int p(int m){
      int sigma = 0;
	int j;
      for (j =0; j<n; j++){
      sigma  = sigma + (A[j] + m -1)/m;
      }
      return sigma <= k;
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
	int mid = (lb + ub) / 2;  
     
	if( p(mid)) {
      ub = mid;
      }
	else {
      lb = mid;
      }
  }
  printf ("%d\n" , ub);

  return 0;
}
