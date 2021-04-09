#include<stdio.h>
#include<stdlib.h>

int n; //node�� ����
char color[105];//color check
int pi[105], d[105], f[105];	//previous node, discovered, finished array
int time;
int dtime = 0;	//gray �Ǵ� ���� ������ ���� dtime(dfs���)
int result[105], result2[105];
int count = 1;		//component ��
int cc[105];		//�� ����� component ���� �����ϱ� ���� �迭



void DFS_vist(int graph[][105], int u) {
	int v;

	color[u] = 'g';		//discovered�Ǿ��� ������ gray�� ��������
	time = time + 1;
	dtime = dtime + 1;	//gray ���� 
	d[u] = time;	//discovered �Ǵ� �ð��� ����
	result[u] = dtime;	//gray �Ǵ� ���� = dfs ���
	cc[u] = count;	//connected component�̱� ������ ���� count ���� �־���

	for (v = u; v <= n; v++) {		//undirected graph�̱� ������ ���ݸ� check
		if (graph[u][v] == 1) {

			if (color[v] == 'w') {		//white�̸� ����Լ��� ����
				pi[v] = u;
				DFS_vist(graph, v);
			}

		}
	}

	color[u] = 'b';		//for�� ������ black���� ��������ش�.
	time = time + 1;
	f[u] = time;		//black�Ǵ� �ð��� 1���������ְ� �迭�� �־��ش�.
}


int main()
{

	int graph[105][105] = { {0,} };
	int i, j, u;
	char EnterCheck;


	//���� �����
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
			count++;		//DFS_visit �Լ��� ������ connect component�� �ƴϱ� ������ component���� 1 ���������ش�
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
	printf("\n");
	for (i = 1; i <= n; i++)
		printf("%d : %d \n", i, cc[i]);

	fclose(fp);
}