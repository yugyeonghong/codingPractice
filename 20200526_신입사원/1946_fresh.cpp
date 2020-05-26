#include <iostream>
#include <algorithm>
using namespace std;
#define TMAX 21
#define NMAX 100001

int main() {
   int T, N;
   int pass;
   int ans[TMAX];
   cin >> T;
   for (int i = 0; i < T; i++) {
      cin >> N;
      pair<int, int> grade[NMAX];
      for (int j = 0; j < N; j++) {
         cin >> grade[j].first >> grade[j].second;
      }
      sort(grade, grade + N);
      pass = 1; //서류심사 1등
      int min = 0;
      for (int j = 1; j < N; j++) {
         if (grade[j].second < grade[min].second) {
            pass++;
            min = j;
         }
      }
      ans[i] = pass;
   }
   for (int i = 0; i < T; i++) {
      cout << ans[i] << endl;
   }
   return 0;
}