#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1001
#define kMAX 11
int N, M, K;
int map[MAX][MAX];
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,-1,0,1 };
queue<pair<pair<int, int>, int>> q;
int visited[MAX][MAX][kMAX] = { 0, };

int bfs() {
   q.push({ {1,1},K }); // 처음위치(y,x), 벽뚫기 가능횟수
   visited[1][1][K] = 1;

   while (!q.empty()) {
      int y = q.front().first.first;
      int x = q.front().first.second;
      int block = q.front().second;
      q.pop();

      //도착하면//
      if (y == N && x == M) {
         return visited[y][x][block];
      }

      for (int i = 0; i < 4; i++) {
         int ny = y + dirY[i];
         int nx = x + dirX[i];

         if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {
            if (map[ny][nx] == 1 && block>0&&visited[ny][nx][block-1]==0) { //벽이면서 뚫을기회가 있으면
               visited[ny][nx][block-1] = visited[y][x][block] + 1;
               q.push({ {ny,nx}, block-1 });
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
   cin >> N >> M>>K;
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