# 1987_알파벳 

세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.    

**입력**  
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

**출력**  
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다..

**Example1:**   
```
2 4
CAAB
ADCB

3
```

## trial1
### Intuition
```
재귀함수를 이용하여 DFS로 구현하였다.
방문배열은 알파벳 인덱스라 생각하고 해당 알파벳을 방문하면 알파벳-65를 하여 해당하는 인덱스를 1로 바꾸어주었다.
dfs 함수를 호출하기 전에 방문한 지점의 알파벳을 방문한 것으로 체크하고, dfs를 호출한 다음에는 그 전에 방문한 지점의 알파벳을 방문하지 않은 것으로 체크했다.
```

### Codes  
```cpp
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

```
### Results (Performance)  
**Runtime:**  456 ms O(n^2)
**Memory Usage:** 	1984 MB  


### 문제 URL (백준)  
https://www.acmicpc.net/problem/1987
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
