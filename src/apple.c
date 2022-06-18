#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m) {
	int i,k_rem;
	k_rem = k;
	for (i = 0; i < n; i++) {;
		k_rem -= (A[i] - 1) / m + 1; //int‚Ì¬”“_ˆÈ‰ºØ‚èÌ‚Ä‚ğ—˜—p
		if (k_rem < 0) {
			break;
		}
	}
	return (long long int) k_rem >= 0;
}

int main(){
	int i, lb, ub;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}

	lb = 0;
	ub = 1000000001;
	while(ub - lb > 1){
		int mid = (ub + lb) / 2;
		if (p(mid)) {
			ub = mid;
		}
		else {
			lb = mid;
		}
	}
	printf("%d\n",ub);
	return 0;
}
