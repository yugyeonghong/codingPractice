#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 21

int r, c;
char board[MAX][MAX];
int visited[26] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int answer = 0;

void dfs(int x, int y, int check) {
   answer = max(answer, check);
   for (int i = 0; i < 4; i++) {
      int nextX = x + dx[i];
      int nextY = y + dy[i];
      if (nextX >= 0 && nextX < r&&nextY >= 0 && nextY < c) {
         int nextAlp = board[nextX][nextY];
         if (visited[nextAlp - 65] == 1)
            continue;
         visited[nextAlp - 65] = 1;
         dfs(nextX, nextY, check + 1);
         visited[nextAlp - 65] = 0;      //백트래킹
      }
   }
}

int main() {
   cin >> r >> c;
   for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
         cin >> board[i][j];
      }
   }
   visited[board[0][0] - 65] = 1;   //첫번째 알파벳((0,0) 지점)의 방문 판단 --> A:0번째 인덱스 / Z: 25번째 인덱스
   dfs(0, 0, 1);
   cout << answer << endl;
}