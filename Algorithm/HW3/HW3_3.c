#include<stdio.h>
#include<stdlib.h>

int n;				//node�� ����
char color[105];	//color check
int pi[105], d[105], f[105];	//previous node, discovered, finished array
int time;		
int u;
int result[105];

int compare(void* front, void* back)		//quicksort, ��������
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

	color[u] = 'g';		//�߰��ϸ� gray�� �������
	time = time + 1;	//�ð� 1 ����
	d[u] = time;	//�ش� ��忡 discovered time �Է�

	for (int v = 1; v <= n; v++) {
		if (graph[u][v] == 1) {		//����Ǿ� ������
			
			if (color[v] == 'g') {		//gray�� �����ϸ� DAG�� �ƴϱ� ������ 0 ����ϰ� ����
				printf("0");
				exit(1);
			}
			if (color[v] == 'w') {		//white �߰��ϸ� previous node �迭�� �־��ְ� ��ͷ� dfs Ž��
				pi[v] = u;

				DFS_vist(graph, v);
			}


		}
	}

	color[u] = 'b';		//���̻� ����� node������ black �����
	time = time + 1;
	f[u] = time;		//finished �迭�� �ð� �־���
}


int main()
{

	int graph[105][105] = { {0,} };
	int i, j, u, v;
	char EnterCheck;

	//���� ����°���

	FILE* fp = fopen("input3-3.txt", "r");



	if (fp == NULL)		//fp�� �������� error ���
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



	int sortArr[105];	//black �� node�� �ð��� index�� ���ϱ� ���� �迭
	for (i = 1; i <= n; i++)
		sortArr[i] = f[i];


	qsort(sortArr + 1, n * 4, sizeof(int), compare);	//quicksort�� ����


	for (int a = 1; a <= n; a++) {		//for�� ���鼭 ���ĵ� sortArr ���� ���� ���� f�迭�� ���° �ε����� �ִ��� �˾Ƴ��� result�� index�� �־���
		for (int b = 1; b <= n; b++) {
			if (sortArr[a] == f[b])
				result[a] = b;

		}
	}
	printf("1\n");		//DAG������ ����Ǿ����ٵ� �ȵǾ��� ������ DAG �ƴ�
	for (i = 1; i <= n; i++)
		printf("%d ", result[i]);
	fclose(fp);
}