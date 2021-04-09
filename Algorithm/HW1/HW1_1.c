#include<stdio.h>

#define swap(a,b) {int tmp; tmp = a; a= b; b=tmp;} //교체

void MaxHeapify(int arr[], int size, int index) {
	int parent = index; //heapify 시작 인덱스
	int left = index * 2; //왼쪽 자식
	int right = index * 2 + 1;  //오른쪽 자식
	int check = index; //자식이 더 큰 경우 교체할 인덱스

	if (left <= size) {		//자식이 있는지 확인
		if (arr[left] < arr[check]) //자식이 더 크면 체크 인덱스 변경
			check = left;
	}

	if (right <= size) {		//자식이 있는지 확인
		if (arr[right] < arr[check])
			check = right;
	}

	if (parent != check) { //check 인덱스가 변경됐으면 자식이 더 큰 경우가 존재했다는 뜻이기에 교체해준다
		swap(arr[parent], arr[check]);
		MaxHeapify(arr, size, check); //변경한 부분부터 다시 확인(왼쪽 오른쪽 둘 다 교체해야할 경우를 대비하여)
	}



}

void HeapSort(int arr[], int size) {
	for (int midIndex = size / 2; midIndex >= 1; midIndex--) {		//트리 형성, 전체 크기의 중간부터 자식 존재
		MaxHeapify(arr, size, midIndex);
	}

	for (size; size > 1; ) {
		swap(arr[1], arr[size]);	//맨 위와 아래 교체하며 정렬
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