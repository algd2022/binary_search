#include <stdio.h>

int n;
int k;
int A[100000];

int sumarray(int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
    	sum = sum + a[i];
    }
    return sum;
}



unsigned int  binary_search(int A[], int k, int n){
	int sma = 1;
	int big = sumarray(A, n);
	int mid = 0;
	int nin;
	int chk;
	int midmid=0;
	int max;

	while(big - sma > 1){
    	mid = (big + sma) / 2;
		nin = 1;
		chk = 0;
		max = 0;
		for(int i = 0; i < n; i++){
			if(A[i]>mid){
				nin=0;
				break;
			}
			if(max<chk){
				max=chk;
			}
			chk = chk + A[i];
			if(chk > mid){
				nin++;
				chk = A[i];
				if(i==(n-1) && max<chk){
					max=chk;
				}
			}else if(i==(n-1)){
				if(max<chk){
					max=chk;
				}
			}
		}
		if(nin==0){
			sma = mid;
		}else if(nin < k){
			big = mid;
			midmid = max;
		}else if(nin == k){
			big = mid;
			midmid = max;
		}else{
			sma = mid;
		}
    }	
	return midmid;    	
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
