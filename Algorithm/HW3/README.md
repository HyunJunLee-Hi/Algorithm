# HW3_1
## DFS(Depth First Search) with edge classification
##### 각 모든 노드들을 color배열에 ‘w’로 초기화 시켜주고 previous node를 담는 함수인 pi 배열도 NULL로 초기화
##### for문을 반복하면서 각 노드의 값이 ‘w’인 경우 DFS_visit함수를 통해 dfs를 진행
##### DFS_visit 함수가 실행되면 해당 노드의 color 배열 값을 ‘g’로 변경시켜준 뒤 time 값을 1증가시켜주고 discovered time에 해당 시간 삽입
##### dtime을 따로 만들어 discovered되는 순서를 따로 값을 받아서 result함수 삽입
##### for문을 돌면서 연결된 노드 탐색
##### 발견한 노드의 color가 ‘g’면 back edge이기 때문에 back edge를 출력
##### 발견한 노드의 color가 ‘b’라면 discovered time을 비교하여 현재 노드가 다음 노드의 discovered time보다 작으면 forward edge출력, 반대라면 cross edge를 출력
##### 발견한 노드의 color이 ‘w’라면 pi배열에 previous node를 저장하고 tree edge를 출력해준 뒤 재귀함수로 DFS_visit를 실행
##### for문을 나오면 노드의 color을 ‘b’로 바꾼 뒤 그 시간을 finished 배열에 저장
##### result 배열의 데이터 크기 순서대로 인덱스 값을 추출한 뒤 result2에 그 값을 넣어 dfs 순서를 출력

# HW3_2
## DFS with connected component identification
##### 각 모든 노드들을 color배열에 ‘w’로 초기화 시켜주고 previous node를 담는 함수인 pi 배열도 NULL로 초기화
##### for문을 반복하면서 각 노드의 값이 ‘w’인 경우 DFS_visit함수를 통해 dfs를 진행
##### DFS_visit 함수가 종료되면 connected component가 아니기 때문에 count 값을 1 증가시켜서 구분
##### DFS_visit 함수가 실행되면 해당 노드의 color 배열 값을 ‘g’로 변경시켜준 뒤 time 값을 1증가시켜주고 discovered time에 해당 시간 삽입
##### dtime을 따로 만들어 discovered되는 순서를 따로 값을 받아서 result함수에 삽입
##### cc 배열에 해당 노드의 component값인 count값 삽입
##### for문을 돌리는데 undirected graph이기 때문에 절반만 탐색
##### 해당 노드와 연결되어 있으며 color가 ‘w’인 노드를 발견하면 연결된 previous node를 pi배열에 넣어주고 재귀함수로 dfs를 진행
##### for문이 종료되면 해당 노드의 color를 ‘b’로 변경해주고 해당 시간을 finished 배열에 저장
##### result 값의 크기 순서대로 인덱스 값을 추출하여서 result2 배열에 삽입
##### 각 노드 번호와 해당 노드의 connected component값을 출력

# HW3_3
## Topological sort
##### 각 모든 노드들을 color배열에 ‘w’로 초기화 시켜주고 previous node를 담는 함수인 pi 배열도 NULL로 초기화
##### for문을 반복하면서 각 노드의 값이 ‘w’인 경우 DFS_visit함수를 통해 dfs를 진행
##### DFS_visit 함수가 실행되면 해당 노드의 color 배열 값을 ‘g’로 변경시켜준  뒤 time 값을 1증가시켜주고 discovered time에 해당 시간 삽입
##### 해당 노드와 연결된 노드를 for문을 통해 찾아가며 color 배열 값이 ‘g’인 값을 발견하면 DAG가 아닌 cycle이 존재하기 때문에 0을 출력하고 프로그램을 종료
##### ‘w’인 값을 발견하면 previous node 배열에 넣어준 뒤 DFS_visit 함수를 재귀함수로 실행
##### for문을 나오면 해당 노드의 color배열 값을 ‘b’로 변경해준 뒤 time을 1 증가시킨 뒤 finished 배열에 ‘b’가 된 시간 삽입
##### 위의 함수를 마치면 DAG이기 때문에 1을 출력하였고finished배열의 크기 역순서로 정렬을 하면 topologica sort의 결과이기 때문에 finished 배열을 sortArr 배열에 복사한 뒤 quicksort를 통해서 내림차순으로 정렬
##### 이중 for문을 돈 뒤 sortArr 값과 같은 finished배열의 index값을 추출하여 result 배열에 넣어주고 그 값을 출력
