/* C program for Matrix chain multiplication */
#include <limits.h>
#include <stdio.h>


int MatrixMultiChain(int tp[], int n)
{

	
	int m[n][n];

	int a, b, k, L, q;

	for (a = 1; a < n; a++)
		m[a][a] = 0;

	for (L = 2; L < n; L++) {
		for (a = 1; a < n - L + 1; a++) {
			b = a + L - 1;
			m[a][b] = INT_MAX;
			for (k = a; k <= b - 1; k++) {
				// q = cost/scalar multiplications
				q = m[a][k] + m[k + 1][b] + tp[a - 1] * tp[k] * tp[b];
				if (q < m[a][b])
					m[a][b] = q;
			}
		}
	}

	return m[1][n - 1];
}

int main()
{
	int tp[] = { 1, 2, 3, 4 };
	int size = sizeof(tp) / sizeof(tp[0]);

	printf("Minimum number of multiplications is %d ",
		MatrixMultiChain(tp, size));

	getchar();
	return 0;
}

