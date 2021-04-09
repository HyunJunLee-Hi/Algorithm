#include<stdio.h>
#include<stdlib.h>
void Cut_Rod(int* p, int n) {
	int r[101] = { 0, };
	int s[101] = { 0, };
	int result[2];
	int i, j, q;
	for (j = 1; j <= n; j++) {
		q = INT_MIN;
		for (i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	printf("%d\n", r[n]);
	while (n > 0)
	{
		printf("%d ", s[n]);
		n = n - s[n];
	}
}


int main()
{
	int arr[105] = { 0, };
	int i, n;
	char EnterCheck;
	FILE* fp = fopen("input2-2.txt", "r");

	if (fp == NULL)
		printf("Error\n");
	else
	{
		fscanf(fp, "%d", &n);
		for (i = 1; i <= 103; i++) {

			fscanf(fp, "%d%c", &arr[i], &EnterCheck);
			if (feof(fp))
				break;
		}
	}
	Cut_Rod(arr, n);

	fclose(fp);
	return 0;

}