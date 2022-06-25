#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int sigma = 0;
    int j;
    int number = 1;
    for (j =0; j<n; j++){
      if (A[j]>m){
      return 0;
      }
      else if(sigma + A[j]<= m){
      sigma  = sigma + A[j];
      }
      else{ 
      sigma = A[j];
      number = number + 1;
      }
      }
    return number <= k;
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
