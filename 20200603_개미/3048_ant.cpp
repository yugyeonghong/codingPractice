#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int N1, N2, T;
   char ant;
   cin >> N1 >> N2;
   int size = N1 + N2;
   vector<pair<char, int>> group(size);
   for (int i = 0; i < N1; i++) {
      cin >> ant;
      group[N1 - 1 - i] = make_pair(ant, 0);
   }
   for (int i = N1; i < N1 + N2; i++) {
      cin >> ant;
      group[i] = make_pair(ant, 1);
   }
   cin >> T;
   for (int i = 0; i < T; i++) {
      for (int j = 0; j < N1 + N2 - 1; j++) {
         if (group[j].second != group[j + 1].second&&group[j].second == 0) {
            swap(group[j], group[j + 1]);
            j++;
         }
      }
   }
   for (int i = 0; i < group.size(); i++) {
      cout << group[i].first;
   }
   return 0;
}