#include <stdio.h>
#include <stdlib.h>
void manshe(int *a, int *b, int m, int n, int *result, int chu) {
	if (chu == m) {
		int jjudge[n];
		for (int i = 0; i < n; i++) {
			jjudge[i] = 0;
		}
		
		int judgeManshe = 1;
		for (int i = 0; i < m; i++) {
			jjudge[result[i]] = 1;
		}
		
		for (int i = 0; i < n; i++) {
			if (jjudge[i] == 0) {
				judgeManshe = 0;
				break;
			}
		}
		
		if (judgeManshe) {
			printf("{");
			for (int i = 0; i < m; i++) {
				printf("<%d,%d>", a[i], b[result[i]]);
				if (i != m - 1) {
					printf(",");
				}
			}
			printf("}\n");
		}
		return;
	}
	
	for (int i = 0; i < n; i++) {
		result[chu] = i;
		manshe(a, b, m, n, result, chu + 1);
	}
}

int sortb(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	
	int a[m], b[n];
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	
	qsort(a, m, sizeof(int), sortb);
	qsort(b, n, sizeof(int), sortb);
	
	int result[m];
	manshe(a, b, m, n, result, 0);
	
	return 0;
}

