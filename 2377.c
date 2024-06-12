#include <stdio.h>
int result(int a[], int n) {
	int i, j, k;
	for (i = n - 1; (i > 0) && (a[i - 1] >= a[i]); i--);
	if (i <= 0) {
		return 0;
	}
	for (j = n - 1; (a[j] <= a[i - 1]); j--);
	k = a[i - 1];
	a[i - 1] = a[j];
	a[j] = k;
	for (j = n - 1; i < j; i++, j--) {
		k = a[i];
		a[i] = a[j];
		a[j] = k;
	}
	return 1;
}
void shaungshe(int a[], int b[], int n, int m) {
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	
	for (;;) {
		printf("{");
		for (int i = 0; i < n; i++) {
			printf("<%d,%d>", a[i], b[arr[i]]);
			if (i < n - 1) {
				printf(",");
			}
		}
		printf("}\n");
		if (!result(arr, n)) {
			break;
		}
	}
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
	shaungshe(a, b, m, n);
	return 0;
}

