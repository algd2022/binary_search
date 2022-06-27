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
	int sma = 0;
    int big = arrayMax(A, n);
	int sum = 0;
    while(big - sma > 1){
    	sum = 0;
    	int mid = (big + sma) / 2;
    	for(int i = 0; i < n; i++){
        	sum = sum + A[i] / mid;
    	}
  		if(sum >= k){
  			sma = mid;
  		}
  		else if(sum < k){
  			big = mid;
  		}
    }
	sum = 0;
	for(int i = 0; i < n; i++){
        	sum = sum + A[i] / big;
	}
	if(sum == k){
  		return big;
  	} 
    else {
  		return sma;
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
