// Problem#: 1922
// Submission#: 3711309
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
	
	int CaseNum;
	scanf("%d\n", &CaseNum);
	
	while (CaseNum--) {

		int N, Sum = 0, Stones[50005], k = 0, XorSum = 0;
		scanf("%d\n", &N);
		char C[600000];
		gets(C);

		// Use the gets() function to read a line with lots of datas is fast than scanf()
		for (int i = 0; C[i] != '\0'; i++) {
			if (C[i] == ' ') {
				Stones[k++] = Sum;
				Sum = 0;
			} else {
				Sum = Sum * 10 + C[i] - '0';
			}
		}
		Stones[k] = Sum;

		for (int i = 0; i < N; i++) XorSum ^= Stones[i];
		if (XorSum == 0) printf("0\n");
		else {
			int Ways = 0;
			for (int i = 0; i < N; i++) if ((XorSum ^ Stones[i]) <= Stones[i]) Ways++;
			printf("%d\n", Ways);
		}

	}

	return 0;
}                                 