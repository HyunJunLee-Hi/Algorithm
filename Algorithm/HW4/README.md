#Dijkstra algorithm
## Min heap을 이용한 Dijkstra algorithm을 구현
##### Min heap을 이용하기 위해서 우선순위 큐를 사용하였으며 max heap을 min heap을 변경해주기 위해서 functional library의 greater을 사용
##### 전체 노드의 수를 n에 받은 뒤 파일 입출력을 통해 받은 자료에서 숫자만 그래프에 넣어준 뒤 vector를 통해서 인접행렬 삽입
##### Dijkstra algorithm의 결과값을 넣어줄 배열 result를 큰 값으로 초기화 해준 뒤 노드 1에서부터 Dijkstra 함수를 실행
##### Dijkstra 함수는 시작할 노드는 0으로 만들어 준 뒤 우선순위 큐에 넣어주고 우선순위 큐가 없을 빌 때까지 가중치가 가장 작은 노드의 weight와 노드 번호를 빼낸 뒤 그 값이 이미 알고 있는 경로보다 크다면 무시하고 인접한 정점들을 for문을 통해서 검사해 나가면서 인접행렬 중에 더 가중치가 짧은 경로를 찾으면 갱신
