#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i,j;
  int sum = 0;
  int count = 0;
  for(i = 0;i < n;i++){
	if(A[i] > m){
	  return 0;
	}
  }
  for(j = 0;j < n;j++){
	sum += A[j];
	if(sum > m){
	  count++;
	  sum = A[j];
	  if(sum > m){
		count++;
		sum = 0;
	  }
	}
	else if(sum == m){
	  count++;
	  sum = 0;
	}
  }
  count++;
  return count <= k;
}

int main(){
  int i, lb, ub;
  lb = 0;
  ub = 1000000000;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while ( ub - lb > 1) {
    int mid = ( lb + ub ) / 2;
    if(p ( mid )){
      ub = mid ;
    }
    else {
      lb = mid ;
    }
  }
  printf("%d\n", ub);

  return 0;
}
