#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int binary_search(int A[], int x, int n){
  int lb = -1;
  int ub = n;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(A[mid] >= x) ub = mid;
    else lb = mid;
  }
  return ub;
}

int main(){
	int i, ub;
 	scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++){
    	scanf("%d", &A[i]);
    }

	ub = binary_search(A, k, n);
	
	printf("%d\n", ub);
	return 0;
}


