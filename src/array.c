#include <stdio.h>

int n;
int k;
int A[100000];

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

	lb = -1;		//x:æ‚è‚¤‚éÅ¬0 = •Ô‚è’l0
	ub = n;			//x:æ‚è‚¤‚éÅ‘ån = •Ô‚è’l1

	while(ub - lb > 1){
		int mid = (lb + ub) / 2;

		if (A[mid] >= k){
			ub = mid;
		}
		else{
			lb = mid;
		}
	} 
	
	printf("%d\n", ub);		//ã‚©‚ç—}‚¦‚é
  return 0;
}
