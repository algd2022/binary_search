#include <stdio.h>

int n;
int k;
int A[100000];
int max = 1;

int p(int m){
  	int i,a = 0;
  	for(i = 0; i < n; i++){
  		a = a + (A[i] + m - 1) / m ;
	  }
	return a <= k;
  }

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if(A[i] > max){
    	max = A[i];
	}
  }
  lb = 0;
  ub = max;
  
 
  while(ub - lb > 1){
  	int mid = (lb + ub) / 2;
  	if(p(mid)){
  		ub = mid;
	  }
	else{
		lb = mid;
		}
	}
	printf("%d\n",ub);
	return 0;
}
