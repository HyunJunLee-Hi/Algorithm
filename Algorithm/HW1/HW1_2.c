#include<stdio.h>
#include<stdlib.h>

#define swap(a,b) {int tmp; tmp = a; a= b; b=tmp;} //��ü

void MaxHeapify(int arr[], int size, int index) {
	int parent = index; //heapify ���� �ε���
	int left = index * 2; //���� �ڽ�
	int right = index * 2 + 1;  //������ �ڽ�
	int check = index; //�ڽ��� �� ū ���� ��ü�� �ε���

	if (left <= size) {		//�ڽ��� �ִ��� Ȯ��
		if (arr[left] > arr[check]) //�ڽ��� �� ������ üũ �ε��� ����
			check = left;
	}

	if (right <= size) {		//�ڽ��� �ִ��� Ȯ��
		if (arr[right] > arr[check]) //�ڽ��� �� ������ üũ �ε��� ����
			check = right;
	}

	if (parent != check) { //check �ε����� ��������� �ڽ��� �� ���� ��찡 �����ߴٴ� ���̱⿡ ��ü���ش�
		swap(arr[parent], arr[check]);
		MaxHeapify(arr, size, check); //������ �κк��� �ٽ� Ȯ��(���� ������ �� �� ��ü�ؾ��� ��츦 ����Ͽ�)
	}



}

void HeapSort(int arr[], int size) {
	for (int midIndex = size / 2; midIndex >= 1; midIndex--) {		//Ʈ�� ����, ��ü ũ���� �߰����� �ڽ� ����
		MaxHeapify(arr, size, midIndex);
	}

	for (size; size > 1; ) {
		swap(arr[1], arr[size]);	//�� ���� �Ʒ� ��ü�ϸ� ����
		MaxHeapify(arr, --size, 1);
	}

}

int main() {
	int k, i, j, num;
	int arr[105][105] = { {0, }, };	//�迭�� ���� �������迭
	int index[105] = { 0, };	//�� �迭�� ����� ���� �迭
	int SortArr[10005] = { 0, };	//������ �迭
	char EnterCheck;	//���� �� ���� ���������� Ȯ���� ����
	int total = 1;	//�� ������ ���� ���� ����
	FILE* fp = fopen("input1-2.txt", "r");


	

	if (fp == NULL)
		printf("Error\n");	//���� ����� ������ ������ ���� ǥ��
	
	else {
		for (i = 0; i < 104; i++) {
			for (j = 1; j < 104; j++) {
				fscanf(fp, "%d%c", &arr[i][j], &EnterCheck);
				if (feof(fp) || EnterCheck == '\n')	//���̰ų� ���Ͱ� �ִ��� Ȯ���ؼ� �迭 ����
					break;
				index[i] = j + 1;	//�� �迭 ������ üũ�� ����

			}

			if (arr[0][1] == i)	//ó�� �Է¹��� k���� �迭�� �ޱ� ����
				break;
		}
	}


	for (int a = 1; a <= arr[0][1]; a++) {		//�� �迭�� ���Ҹ� �־���
		for (int b = 1; b <= index[a]; b++) {
			SortArr[total] = arr[a][b];	
			total++;
		}
	}

	
	HeapSort(SortArr, total - 1);		//����
	
	for (int q = 1; q <= total - 1; q++)
		printf("%d ", SortArr[q]);

	fclose(fp);
	return 0;



}