#include<stdio.h>
#include<stdlib.h>

int n; //node의 개수
char color[105];//color check
int pi[105], d[105], f[105];	//previous node, discovered, finished array
int time;
int dtime = 0;	//gray 되는 순서 저장을 위한 dtime(dfs결과)
int result[105], result2[105];
int count = 1;		//component 값
int cc[105];		//각 노드의 component 값을 저장하기 위한 배열



void DFS_vist(int graph[][105], int u) {
	int v;

	color[u] = 'g';		//discovered되었기 때문에 gray로 변경해줌
	time = time + 1;
	dtime = dtime + 1;	//gray 순서 
	d[u] = time;	//discovered 되는 시간을 저장
	result[u] = dtime;	//gray 되는 순서 = dfs 결과
	cc[u] = count;	//connected component이기 때문에 같은 count 값을 넣어줌

	for (v = u; v <= n; v++) {		//undirected graph이기 때문에 절반만 check
		if (graph[u][v] == 1) {

			if (color[v] == 'w') {		//white이면 재귀함수로 실행
				pi[v] = u;
				DFS_vist(graph, v);
			}

		}
	}

	color[u] = 'b';		//for문 나오면 black으로 변경시켜준다.
	time = time + 1;
	f[u] = time;		//black되는 시간을 1증가시켜주고 배열에 넣어준다.
}


int main()
{

	int graph[105][105] = { {0,} };
	int i, j, u;
	char EnterCheck;


	//파일 입출력
	FILE* fp = fopen("input3-2.txt", "r");



	if (fp == NULL)
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
		if (color[u] == 'w') {
			DFS_vist(graph, u);
			count++;		//DFS_visit 함수가 끝나면 connect component가 아니기 때문에 component값을 1 증가시켜준다
		}
	}

	

	//데이터 크기 순서대로 인덱스 값 추출
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == result[b])
				result2[a] = b;
		}
	}


	for (i = 1; i <= n; i++)
		printf("%d ", result2[i]);
	printf("\n");
	for (i = 1; i <= n; i++)
		printf("%d : %d \n", i, cc[i]);

	fclose(fp);
}