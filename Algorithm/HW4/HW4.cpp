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
//min heap을 위한  pq
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int n;		//전체 노드
int result[5005];	//결과


void dijkstra(int s) {
	result[s] = 0;	//결과를 저장할 배열
	pq.push(make_pair(result[s], s));	//시작할 노드

	while (!pq.empty()) {
		int weight = pq.top().first;	//현재의 가중치
		int u = pq.top().second;		//현재 노드

		pq.pop();
		//pop한 것이 더 길다면 무시
		if (weight > result[u])
			continue;



		for (int i = 0; i < adj[u].size(); i++) {
			int nextweight = adj[u][i].first;
			int nextnode = adj[u][i].second;
			//새로 발견한 인접행렬로 가는 것이 더 좋다면 갱신
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


	//파일 받기
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


	//인접행렬 생성
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (graph[i][j] == 0)
				continue;
			else
				adj[i].push_back(make_pair(graph[i][j], j));
		}
	}
	//초기화
	for (i = 0; i <= n; i++)
		result[i] = max;
	//노드 1에서 시작
	dijkstra(1);
	//결과 출력
	for (int i = 1; i <= n; i++)
		printf("%d ", result[i]);
	return 0;
}


