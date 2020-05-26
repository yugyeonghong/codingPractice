# 1946_신입 사원 

언제나 최고만을 지향하는 굴지의 대기업 진영 주식회사가 신규 사원 채용을 실시한다. 인재 선발 시험은 1차 서류심사와 2차 면접시험으로 이루어진다. 최고만을 지향한다는 기업의 이념에 따라 그들은 최고의 인재들만을 사원으로 선발하고 싶어 한다.

그래서 진영 주식회사는, 다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다. 즉, 어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.

이러한 조건을 만족시키면서, 진영 주식회사가 이번 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수를 구하는 프로그램을 작성하시오.
   

**입력**  
첫째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 20)가 주어진다. 각 테스트 케이스의 첫째 줄에 지원자의 숫자 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개 줄에는 각각의 지원자의 서류심사 성적, 면접 성적의 순위가 공백을 사이에 두고 한 줄에 주어진다. 두 성적 순위는 모두 1위부터 N위까지 동석차 없이 결정된다고 가정한다.

**출력**  
각 테스트 케이스에 대해서 진영 주식회사가 선발할 수 있는 신입사원의 최대 인원수를 한 줄에 하나씩 출력한다.

**Example1:**   
```
2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1

4
3
```

## trial
### Intuition
```
Greedy를 이용하는 문제였다.
먼저 서류 순위에 따라 오름차순으로 sorting을 해준 뒤, 면접 순위를 판별하여
신입사원의 수를 선택한다.
서류 1등은 무조건 선택되므로 신입사원의 수인 pass를 1로 초기화 하여준다.
그리고 서류에 따른 면접 순위를 비교하여 순위가 높은 idx를 min에 저장하여
min 값을 다음 면접 순위와 비교하면서 신입사원의 수를 조건에 맞게 늘려간다.
테스트케이스마다 결과값을 저장해주어야 하므로 ans이라는 배열을 선언하여
해당 테스트케이스의 결과값을 저장하고 출력하였다.

```

### Codes  
```cpp
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
```
### Results (Performance)  
**Runtime:**  412 ms
**Memory Usage:** 	2644 KB  


### 문제 URL (백준)  
https://www.acmicpc.net/problem/1946
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
