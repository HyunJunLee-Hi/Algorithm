#include<stdio.h>
#include<stdlib.h>

int n; //node의 개수
char color[105];//color check
int pi[105], d[105], f[105];//previous node, discovered, finished array
int time;
int dtime = 0;	//gray 되는 순서 저장을 위한 dtime(dfs결과)
int result[105], result2[105];
int u;


void DFS_vist(int graph[][105], int u) {

	color[u] = 'g';//discovered되었기 때문에 gray로 변경해줌
	time = time + 1;
	dtime = dtime + 1;	//gray 되는 순서 
	d[u] = time;//discovered 되는 시간을 저장
	result[u] = dtime;	//gray 되는 순서 = dfs 결과

	int v;

	for (v = 1; v <= n; v++) {
		
		if (graph[u][v] == 1) {
			
			if (color[v] == 'g') {	//다음 연결된 노드의 색이 gray면 back edge
				printf("(%d, %d) back edge\n", u, v);
			}

			if (color[v] == 'b') {	//다음 연결된 노드의 색이 black인데
				if (d[u] < d[v])	//discovered time이 현재 노드가 다음 노드보다 작으면 forward edge
					printf("(%d, %d) forward edge\n", u, v);

				else
					printf("(%d, %d) cross edge\n", u, v);		//반대라면 cross edge

			}

			if (color[v] == 'w') {
				pi[v] = u;
				printf("(%d, %d) tree edge\n", u, v);	//white면 진행하면서
				DFS_vist(graph, v);		//재귀함수 실행
			}

		}
	}

	color[u] = 'b';//for문 나오면 black으로 변경시켜준다.
	time = time + 1;
	f[u] = time;//black되는 시간을 1증가시켜주고 배열에 넣어준다.
}


int main()
{

	int graph[105][105] = { {0,} };
	int i, j;
	char EnterCheck;



	FILE* fp = fopen("input3-1.txt", "r");



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

	fclose(fp);
}