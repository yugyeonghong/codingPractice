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