# 2206_벽 부수고 이동하기

N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
   

**입력**  
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

**출력**  
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

**Example1:**   
```
6 4
0100
1110
1000
0000
0111
0000

15
```

**Example2:**   
```
4 4
0111
1111
1111
1110

-1
```

## trial
### Intuition
```
dfs를 사용하는 문제였다.
queue에 시작좌표와 벽뚫기 가능횟수 정보를 저장한다. 처음 초기좌표 (1,1), 벽뚫기 가능횟수는 1로 초기화한다.
방문여부 배열은 좌표와 block 상태까지 저장하는 3차원 배열을 이용한다.
만약 벽이면서 뚫을 기회가 있거나 벽이 아니고 방문하지 않은 좌표일 경우 visited 배열에 이동횟수를 저장하고
해당좌표와 block의 상태를 queue에 저장한다.
끝까지 탐색을 완료하면 visited에 저장된 이동횟수를 출력하고, 끝까지 탐색하지 못했으면 -1을 출력하도록 한다.

*주의*
queue 인자 선언 전역변수로 해줄것 -> 지역변수 선언시 stack overflow 발생
입력시 string 형식으로 받아 한개씩 넣어주기

```

### Codes  
```cpp
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1001
int N, M;
int map[MAX][MAX];
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,-1,0,1 };
queue<pair<pair<int, int>, int>> q;
int visited[MAX][MAX][2] = { 0, };

int bfs() {
   q.push({ {1,1},1 }); // 처음위치(y,x), 벽뚫기 가능횟수
   visited[1][1][1] = 1;

   while (!q.empty()) {
      int y = q.front().first.first;
      int x = q.front().first.second;
      int block = q.front().second; //1이면 부시기 가능
      q.pop();

      //도착하면//
      if (y == N && x == M) {
         return visited[y][x][block];
      }

      for (int i = 0; i < 4; i++) {
         int ny = y + dirY[i];
         int nx = x + dirX[i];

         if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {
            if (map[ny][nx] == 1 && block == 1) {   //벽이면서 뚫을기회가 있으면
               visited[ny][nx][block - 1] = visited[y][x][block] + 1;
               q.push({ {ny,nx},block - 1 });
            }
            else if (map[ny][nx] == 0 && visited[ny][nx][block] == 0) { //벽이 아니고 방문하지 않은 곳
               visited[ny][nx][block] = visited[y][x][block] + 1;
               q.push({ {ny,nx},block });
            }
         }
      }
   }
   return -1;
}

int main() {
   cin >> N >> M;
   for (int i = 1; i <= N; i++) {
      string str;
      cin >> str;
      for (int j = 1; j <= M; j++) {
         map[i][j] = str[j - 1] - '0';
      }
   }

   cout << bfs();
   return 0;
}
```

### Results (Performance)  
**Runtime:**  96 ms
**Memory Usage:** 	13732 KB  


### 문제 URL (백준)  
https://www.acmicpc.net/problem/2206
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
