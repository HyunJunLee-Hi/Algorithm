#include<stdio.h>

#define swap(a,b) {int tmp; tmp = a; a= b; b=tmp;} //��ü

void MaxHeapify(int arr[], int size, int index) {
	int parent = index; //heapify ���� �ε���
	int left = index * 2; //���� �ڽ�
	int right = index * 2 + 1;  //������ �ڽ�
	int check = index; //�ڽ��� �� ū ��� ��ü�� �ε���

	if (left <= size) {		//�ڽ��� �ִ��� Ȯ��
		if (arr[left] < arr[check]) //�ڽ��� �� ũ�� üũ �ε��� ����
			check = left;
	}

	if (right <= size) {		//�ڽ��� �ִ��� Ȯ��
		if (arr[right] < arr[check])
			check = right;
	}

	if (parent != check) { //check �ε����� ��������� �ڽ��� �� ū ��찡 �����ߴٴ� ���̱⿡ ��ü���ش�
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
;	int HeapSortArr[105] = { 0, };
	int size, i;
	printf("Input numbers to sort:\n");
	for (i = 1; i <= 100; i++) {

		scanf("%d", &HeapSortArr[i]);
		if (HeapSortArr[i] == -1) {
			HeapSortArr[i] = 0;
			break;
		}
	}
	size = i - 1;

	HeapSort(HeapSortArr, size);

	printf("\nResult\n");
	for (int j = 1; j < i; j++) {
		printf("%d ", HeapSortArr[j]);
	}

	return 0;
}