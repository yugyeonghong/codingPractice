# 9205_맥주 마시면서 걸어가기

송도에 사는 상근이와 친구들은 송도에서 열리는 펜타포트 락 페스티벌에 가려고 한다. 올해는 맥주를 마시면서 걸어가기로 했다. 출발은 상근이네 집에서 하고, 맥주 한 박스를 들고 출발한다. 맥주 한 박스에는 맥주가 20개 들어있다. 목이 마르면 안되기 때문에 50미터에 한 병씩 마시려고 한다.

상근이의 집에서 페스티벌이 열리는 곳은 매우 먼 거리이다. 따라서, 맥주를 더 구매해야 할 수도 있다. 미리 인터넷으로 조사를 해보니 다행히도 맥주를 파는 편의점이 있다. 편의점에 들렸을 때, 빈 병은 버리고 새 맥주 병을 살 수 있다. 하지만, 박스에 들어있는 맥주는 20병을 넘을 수 없다.

편의점, 상근이네 집, 펜타포트 락 페스티벌의 좌표가 주어진다. 상근이와 친구들이 행복하게 페스티벌에 도착할 수 있는지 구하는 프로그램을 작성하시오.
   

**입력**  
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (t ≤ 50)

각 테스트 케이스의 첫째 줄에는 맥주를 파는 편의점의 개수 n이 주어진다. (0 ≤ n ≤ 100).

다음 n+2개 줄에는 상근이네 집, 편의점, 펜타포트 락 페스티벌 좌표가 주어진다. 각 좌표는 두 정수 x와 y로 이루어져 있다. (두 값 모두 미터, -32768 ≤ x, y ≤ 32767)

송도는 직사각형 모양으로 생긴 도시이다. 두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 이다. (맨해튼 거리)

**출력**  
각 테스트 케이스에 대해서 상근이와 친구들이 행복하게 페스티벌에 갈 수 있으면 "happy", 중간에 맥주가 바닥나면 "sad"를 출력한다. 

**Example1:**   
```
2
2
0 0
1000 0
1000 1000
2000 1000
2
0 0
1000 0
2000 1000
2000 2000

happy
sad
```

## trial
### Intuition
```
DFS를 이용하여 문제를 해결하였다.
집, 편의점, 락 페스티벌의 좌표를 받아 저장한 뒤 각각의 거리가 1000 이하인 위치의 idx를 graph라는 벡터에 저장한다. 양방향 그래프로 해당 좌표를 저장하여 DFS를 돌리고 도착점에 도착했는지를 visited 배열을 통해 확인한다. 만약 도달했으면 "happy", 그렇지 않으면 "sad"를 출력하도록 하였다.
가장 중요할 점은 테스트케이스를 진행할 때마다 배열들을 초기화를 해 주어야 한다는 것이다.

```

### Codes  
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define nMAX 102
int n;
int x, y;
int flag;   //1이면 happy, 0이면 sad
vector<int> graph[nMAX];
int visited[nMAX];

int distance(pair<int, int> p1, pair<int, int> p2) {   //맨해튼 거리
   return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void dfs(int idx) {
   visited[idx] = 1;
   for (int i = 0; i < graph[idx].size(); i++) {
      int nextPos = graph[idx][i];
      if (visited[nextPos] == 0) {
         dfs(nextPos);
      }
   }
}

int main() {
   int t;
   cin >> t;
   for (int i = 0; i < t; i++) {
        /*초기화필수*/
      for (int j = 0; j < nMAX; j++) {
         graph[j].clear();
      }
      memset(visited, 0, sizeof(visited));
      vector<pair<int, int>> pos;
      cin >> n;
      for (int j = 0; j < n + 2; j++) {
         cin >> x >> y;
         pos.push_back(make_pair(x, y));
      }

      for (int j = 0; j < n + 2; j++) {
         for (int k = j + 1; k < n + 2; k++) {
            if (distance(pos[j], pos[k]) <= 1000) {  //거리 내에 맥주 구할 수 있으면
               graph[j].push_back(k);
               graph[k].push_back(j);
            }
         }
      }
      dfs(0);
      if (visited[n + 1] == 1) {
         cout << "happy" << endl;
      }
      else {
         cout << "sad" << endl;
      }
   }
   return 0;
}
```
### 참고
https://jaimemin.tistory.com/709

### Results (Performance)  
**Runtime:**  4 ms
**Memory Usage:** 	1988 KB  


### 문제 URL (백준)  
https://www.acmicpc.net/problem/9205
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
