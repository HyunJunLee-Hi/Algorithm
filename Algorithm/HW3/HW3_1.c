#include<stdio.h>
#include<stdlib.h>

int n; //node�� ����
char color[105];//color check
int pi[105], d[105], f[105];//previous node, discovered, finished array
int time;
int dtime = 0;	//gray �Ǵ� ���� ������ ���� dtime(dfs���)
int result[105], result2[105];
int u;


void DFS_vist(int graph[][105], int u) {

	color[u] = 'g';//discovered�Ǿ��� ������ gray�� ��������
	time = time + 1;
	dtime = dtime + 1;	//gray �Ǵ� ���� 
	d[u] = time;//discovered �Ǵ� �ð��� ����
	result[u] = dtime;	//gray �Ǵ� ���� = dfs ���

	int v;

	for (v = 1; v <= n; v++) {
		
		if (graph[u][v] == 1) {
			
			if (color[v] == 'g') {	//���� ����� ����� ���� gray�� back edge
				printf("(%d, %d) back edge\n", u, v);
			}

			if (color[v] == 'b') {	//���� ����� ����� ���� black�ε�
				if (d[u] < d[v])	//discovered time�� ���� ��尡 ���� ��庸�� ������ forward edge
					printf("(%d, %d) forward edge\n", u, v);

				else
					printf("(%d, %d) cross edge\n", u, v);		//�ݴ��� cross edge

			}

			if (color[v] == 'w') {
				pi[v] = u;
				printf("(%d, %d) tree edge\n", u, v);	//white�� �����ϸ鼭
				DFS_vist(graph, v);		//����Լ� ����
			}

		}
	}

	color[u] = 'b';//for�� ������ black���� ��������ش�.
	time = time + 1;
	f[u] = time;//black�Ǵ� �ð��� 1���������ְ� �迭�� �־��ش�.
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


	//������ ũ�� ������� �ε��� �� ����
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