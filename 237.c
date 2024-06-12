#include <stdio.h>
#include <stdlib.h>

void shuangshe(int *a, int *b, int chu, int mo, int m) {
	if (chu == m) {
		printf("{<%d,%d>", a[0], b[0]);
		for (int i = 1; i < m; i++) {
			printf(",<%d,%d>", a[i], b[i]);
		}
		printf("}\n");
	} else {
		for (int i = chu; i <= mo; i++) {
			int temp = b[chu];
			b[chu] = b[i];
			b[i] = temp;
			shuangshe(a, b, chu + 1, mo, m);
			temp = b[chu];
			b[chu] = b[i];
			b[i] = temp;
		}
	}
}

int sortb(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	
	if (m != n) {
		return 1;
	}
	
	int a[m], b[n];
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	
	qsort(b, n, sizeof(int), sortb);
	shuangshe(a, b, 0, n - 1, m);
	return 0;
}
