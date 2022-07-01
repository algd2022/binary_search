#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m) {
	int i, k_allo = 1, m_rem;
	m_rem = m;
	for (i = 0; i < n; i++) {
		if(A[i] > m) return 0;
		else if(m_rem >= A[i]){
			m_rem -= A[i];
		}
		else{
			k_allo += 1;
			m_rem = m - A[i];
		}
	}
	return (long long int) k_allo <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1) {
	  int mid = (ub + lb) / 2;
	  if (p(mid)) {
		  ub = mid;
	  }
	  else {
		  lb = mid;
	  }
  }
  printf("%d\n", ub);
  return 0;
}
