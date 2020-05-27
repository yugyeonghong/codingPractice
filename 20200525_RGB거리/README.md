# 1149_RGB거리 

RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
   

**입력**  
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

**출력**  
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

**Example1:**   
```
3
26 40 83
49 60 57
13 89 99

96
```

## trial
### Intuition
```
dp를 이용하는 문제이다.
먼저 집마다 각각의 색으로 칠했을 때의 비용을 입력하고(house), 그 비용의 최소값을 정하는 배열을 만든다(dp).
직전에 최소값이 선택되면 같은 색은 선택 못하기 때문에 이전에 선택한 색깔을 제외한 나머지 색 중 최소 비용을
선택한다.
N번째 집까지 색칠하여 N번째 행에서 빨강, 초록, 파랑 중 최소 값을 선택하여 출력한다.

```

### Codes  
```cpp
#include <iostream>
#include <algorithm>
//#include <vector>
using namespace std;

#define MAX 1001

int main(){
    int N;
    int house[MAX][3]={0,};
    int dp[MAX][3]={0,};
    int result;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>house[i][0]>>house[i][1]>>house[i][2];//r,g,b 입력
    }

    for(int i=1;i<=N;i++){
        dp[i][0]=house[i][0]+min(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=house[i][1]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=house[i][2]+min(dp[i-1][0],dp[i-1][1]);
    }

    result=min(dp[N][0],min(dp[N][1],dp[N][2]));
    cout<<result;
    return 0;
}
```
### Results (Performance)  
**Runtime:**  0 ms
**Memory Usage:** 	1984 KB  


### 문제 URL (백준)  
https://www.acmicpc.net/problem/1149
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
