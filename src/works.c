#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m) {
	int i, works = 0, sum = 1;
	for(i = 0; i < n; i++) {
		if(A[i] > m)
			return 0;

		if((works += A[i]) > m) {
			sum++;
			works = A[i];
		}
	}

	return sum <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

	lb = 0;
	ub = 10000 * n;

	while(ub - lb > 1) {
		int mid = (lb + ub) / 2;
		if(p(mid))
			ub = mid;
		else
			lb = mid;
	}

	printf("%d", ub);

  return 0;
}
