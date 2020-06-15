# 11057_오르막 수

오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.   

**입력**  
첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

**출력**  
첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

**Example1:**   
```
1

10
```

**Example2:**   
```
2

55
```

**Example3:**   
```
3

220
```


## trial
### Intuition
```
dp를 활용하는 문제이다.
2차원 배열을 선언하여 입력받은 자리수와 마지막 자리의 수를 넣도록 한다.
한자리 수 일 경우 0~9까지 1개뿐이기 때문에 먼저 값을 초기화 해준다.
자리 수를 단계라 설명한다면 만약 2단계의 마지막 수가 5일때 답을 구한다면 2단계의 4일때 오르막 수의 개수와
1단계의 5일때의 개수를 합한다.
식으로 설명하자면
dp[1][0]~[1][9]=1
dp[2][1]=dp[1][0]+dp[1][1] => 01,11
dp[2][2]=dp[1][0]+dp[1][1]+dp[1][2]=dp[2][1]+dp[1][2]
이므로
점화식을 작성하면 dp[i][j]=dp[i][j-1]+dp[i-1][j] 가 된다.
N자리의 오르막 개수는 dp[N][0]~dp[N][9]를 합한 값이다

```

### Codes  
```cpp
#include <iostream>
using namespace std;

#define MAX 1001
int main(){
    int N;
    int dp[MAX][10];
    int result=0;
    cin>>N;
    for(int i=0;i<10;i++){
        dp[1][i]=1; //한자리 수 일 경우 : 0~9
    }
    for(int i=2;i<=N;i++){
        dp[i][0]=1; //끝자리가 0인 오르막 수 : 00, 000, 0000 ...
        for(int j=1;j<10;j++){
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%10007;
        }
    }
    for(int i=0;i<10;i++){
        result+=dp[N][i];
    }
    result%=10007;
    cout<<result;
    return 0;
}
```

### Results (Performance)  
**Runtime:**  0 ms
**Memory Usage:** 	1984 KB  


### 문제 URL (백준)  
https://www.acmicpc.net/problem/11057
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
