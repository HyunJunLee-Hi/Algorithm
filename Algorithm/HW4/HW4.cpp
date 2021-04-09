#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <functional>

using namespace std;

#define max 100000

vector<pair<int, int>> adj[5000];
//min heap�� ����  pq
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int n;		//��ü ���
int result[5005];	//���


void dijkstra(int s) {
	result[s] = 0;	//����� ������ �迭
	pq.push(make_pair(result[s], s));	//������ ���

	while (!pq.empty()) {
		int weight = pq.top().first;	//������ ����ġ
		int u = pq.top().second;		//���� ���

		pq.pop();
		//pop�� ���� �� ��ٸ� ����
		if (weight > result[u])
			continue;



		for (int i = 0; i < adj[u].size(); i++) {
			int nextweight = adj[u][i].first;
			int nextnode = adj[u][i].second;
			//���� �߰��� ������ķ� ���� ���� �� ���ٸ� ����
			if (weight + adj[u][i].first < result[adj[u][i].second]) {
				result[adj[u][i].second] = weight + adj[u][i].first;
				pq.push(make_pair(weight + adj[u][i].first, adj[u][i].second));
			}

		}
	}
}

int main()
{
	int graph[500][500] = { {0,} };
	int i, j;
	char EnterCheck;



	FILE* fp = fopen("input4.txt", "r");


	//���� �ޱ�
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


	//������� ����
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (graph[i][j] == 0)
				continue;
			else
				adj[i].push_back(make_pair(graph[i][j], j));
		}
	}
	//�ʱ�ȭ
	for (i = 0; i <= n; i++)
		result[i] = max;
	//��� 1���� ����
	dijkstra(1);
	//��� ���
	for (int i = 1; i <= n; i++)
		printf("%d ", result[i]);
	return 0;
}


