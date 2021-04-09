#include<stdio.h>
#include<stdlib.h>

#define swap(a,b) {int tmp; tmp = a; a= b; b=tmp;} //교체

void MaxHeapify(int arr[], int size, int index) {
	int parent = index; //heapify 시작 인덱스
	int left = index * 2; //왼쪽 자식
	int right = index * 2 + 1;  //오른쪽 자식
	int check = index; //자식이 더 큰 작은 교체할 인덱스

	if (left <= size) {		//자식이 있는지 확인
		if (arr[left] > arr[check]) //자식이 더 작으면 체크 인덱스 변경
			check = left;
	}

	if (right <= size) {		//자식이 있는지 확인
		if (arr[right] > arr[check]) //자식이 더 작으면 체크 인덱스 변경
			check = right;
	}

	if (parent != check) { //check 인덱스가 변경됐으면 자식이 더 작은 경우가 존재했다는 뜻이기에 교체해준다
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
	int k, i, j, num;
	int arr[105][105] = { {0, }, };	//배열을 받을 이차원배열
	int index[105] = { 0, };	//각 배열의 사이즈를 받을 배열
	int SortArr[10005] = { 0, };	//정렬할 배열
	char EnterCheck;	//엔터 및 파일 마지막인지 확인할 변수
	int total = 1;	//총 원소의 수를 구할 변수
	FILE* fp = fopen("input1-2.txt", "r");


	

	if (fp == NULL)
		printf("Error\n");	//파일 제대로 열리지 않으면 에러 표시
	
	else {
		for (i = 0; i < 104; i++) {
			for (j = 1; j < 104; j++) {
				fscanf(fp, "%d%c", &arr[i][j], &EnterCheck);
				if (feof(fp) || EnterCheck == '\n')	//끝이거나 엔터가 있는지 확인해서 배열 구성
					break;
				index[i] = j + 1;	//각 배열 사이즈 체크를 위함

			}

			if (arr[0][1] == i)	//처음 입력받은 k개의 배열만 받기 위함
				break;
		}
	}


	for (int a = 1; a <= arr[0][1]; a++) {		//각 배열의 원소를 넣어줌
		for (int b = 1; b <= index[a]; b++) {
			SortArr[total] = arr[a][b];	
			total++;
		}
	}

	
	HeapSort(SortArr, total - 1);		//정렬
	
	for (int q = 1; q <= total - 1; q++)
		printf("%d ", SortArr[q]);

	fclose(fp);
	return 0;



}