#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a,b) {int tmp; tmp = a; a= b; b=tmp;} //±³Ã¼


void Insert_Sort(int* arr, int cnt)
{
	int i, j, key;
	for (j = 2; j <= cnt; j++) {
		key = arr[j];
		i = j - 1;
		while (i > 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
}
int Partition(int* arr, int start, int cnt)
{
	int i, j, x;

	x = arr[cnt];
	i = start - 1;
	for (j = start; j <= cnt - 1; j++) {
		if (arr[j] <= x) {
			i = i + 1;
			swap(arr[i], arr[j]);
		}

	}
	swap(arr[i + 1], arr[cnt]);


	return i + 1;
}

int Randomized_Partition(int* arr, int start, int cnt)
{
	int pivot1, pivot2, pivot3, pivot, p, pivotIndex;

	p = cnt;
	srand(time(NULL));
	pivot1 = rand() % p + 1;
	pivot2 = rand() % p + 1;
	pivot3 = rand() % p + 1;
	int pivotArr[3] = { arr[pivot1], arr[pivot2], arr[pivot3] };
	Insert_Sort(pivotArr, 2);
	pivot = pivotArr[1];
	if (pivot == arr[pivot1])
		pivotIndex = pivot1;
	if (pivot == arr[pivot2])
		pivotIndex = pivot2;
	if (pivot == arr[pivot3])
		pivotIndex = pivot3;

	swap(arr[cnt], arr[pivotIndex]);


	return Partition(arr, start, cnt);
}

void HybridQuickSort(int* arr, int start, int cnt)
{
	int q;

	if (cnt + 1 <= 10)
		Insert_Sort(arr, cnt);

	else {
		if (start < cnt)
		{
			q = Randomized_Partition(arr, start, cnt);
			HybridQuickSort(arr, start, q - 1);
			HybridQuickSort(arr, q + 1, cnt);
		}
	}

}




int main()
{
	int arr[20005] = { 0, };
	int cnt = 0;
	int i;
	char Spacebar;
	FILE* fp = fopen("input2-1.txt", "r");

	if (fp == NULL)
		printf("Error\n");
	else {
		for (i = 1; i < 20004; i++) {
			fscanf(fp, "%d%c", &arr[i], &Spacebar);
			if (feof(fp))
				break;

		}
		cnt = i - 1;
	}

	HybridQuickSort(arr, 1, cnt);

	for (int j = 1; j <= cnt; j++)
		printf("%d ", arr[j]);

	fclose(fp);
	return 0;
}