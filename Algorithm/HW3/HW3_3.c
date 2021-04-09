#include<stdio.h>
#include<stdlib.h>

int n;				//node의 개수
char color[105];	//color check
int pi[105], d[105], f[105];	//previous node, discovered, finished array
int time;		
int u;
int result[105];

int compare(void* front, void* back)		//quicksort, 내림차순
{
	if (*(int*)front < *(int*)back)
		return 1;
	
	else if (*(int*)front > * (int*)back)
		return -1;
	
	else
		return 0;
}



void DFS_vist(int graph[][105], int u) {
	int v;

	color[u] = 'g';		//발견하면 gray로 만들어줌
	time = time + 1;	//시간 1 증가
	d[u] = time;	//해당 노드에 discovered time 입력

	for (int v = 1; v <= n; v++) {
		if (graph[u][v] == 1) {		//연결되어 있으면
			
			if (color[v] == 'g') {		//gray가 존재하면 DAG가 아니기 때문에 0 출력하고 종료
				printf("0");
				exit(1);
			}
			if (color[v] == 'w') {		//white 발견하면 previous node 배열에 넣어주고 재귀로 dfs 탐색
				pi[v] = u;

				DFS_vist(graph, v);
			}


		}
	}

	color[u] = 'b';		//더이상 연결된 node없으면 black 만들고
	time = time + 1;
	f[u] = time;		//finished 배열에 시간 넣어줌
}


int main()
{

	int graph[105][105] = { {0,} };
	int i, j, u, v;
	char EnterCheck;

	//파일 입출력과정

	FILE* fp = fopen("input3-3.txt", "r");



	if (fp == NULL)		//fp가 못받으면 error 출력
		printf("Error\n");

	else {

		fscanf(fp, "%d", &n);

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				fscanf(fp, "%d%c", &graph[i][j], &EnterCheck);
				if (feof(fp) || EnterCheck == '\n')
					break;

			}
		}
	}

	//DFS
	for (u = 1; u <= n; u++) {
		color[u] = 'w';
		pi[u] = NULL;
	}
	time = 0;

	for (u = 1; u <= n; u++) {
		if (color[u] == 'w')
			DFS_vist(graph, u);
	}



	int sortArr[105];	//black 된 node의 시간의 index를 비교하기 위한 배열
	for (i = 1; i <= n; i++)
		sortArr[i] = f[i];


	qsort(sortArr + 1, n * 4, sizeof(int), compare);	//quicksort로 정렬


	for (int a = 1; a <= n; a++) {		//for문 돌면서 정렬된 sortArr 값과 같은 값이 f배열의 몇번째 인덱스에 있는지 알아내고 result에 index값 넣어줌
		for (int b = 1; b <= n; b++) {
			if (sortArr[a] == f[b])
				result[a] = b;

		}
	}
	printf("1\n");		//DAG였으면 종료되었을텐데 안되었기 때문에 DAG 아님
	for (i = 1; i <= n; i++)
		printf("%d ", result[i]);
	fclose(fp);
}