#include <stdio.h>

int n;
int k;
int A[100000];

int arrayMax(int a[], int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

unsigned int  binary_search(int A[], int k, int n){
	int lb = 1;
    int ub = arrayMax(A, n);
	int sum = 0;
    while(ub -lb > 1){
    	sum = 0;
    	int mid = (lb + ub) / 2;
    	for(int i = 0; i < n; i++){
        	sum = sum + (A[i] + mid - 1) / mid;
    	}
  		if(sum > k){
  			lb = mid;
  		}
  		else if(sum <= k){
  			ub = mid;
  		}
    }
	sum = 0;
	for(int i = 0; i < n; i++){
        	sum = sum + (A[i] + lb - 1) / lb;
	}
	if(sum > k){
  		return ub;
  	} 
    else {
  		return lb;
  	}
	return 0;
}

int main(){
    int i;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
      scanf("%d", &A[i]);
    }
	int result = binary_search(A, k, n);
	printf("結果=%d\n", result);

    return 0;
}



