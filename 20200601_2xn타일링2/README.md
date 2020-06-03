# 11727_2xn 타일링 2

2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
   

**입력**  
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

**출력**  
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다. 

**Example1:**   
```
2

3
```

**Example2:**   
```
8

171
```

**Example3:**   
```
12

2731
```

## trial
### Intuition
```
dp를 사용하는 문제였다.
지난 2xn타일링1 문제와 같이 피보나치 수열의 규칙이 있는데, 이번에는 2x2의 사각형이 한개 더 생겼으므로
n-2번째에 2배를 곱해준다.

```

### Codes  
```cpp
#include <iostream>
using namespace std;
#define MAX 1001

int main(){
    int n;
    int result;
    cin>>n;
    int dp[MAX]={0,};
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+(dp[i-2]*2))%10007;
    }
    result=dp[n]%10007;
    cout<<result;
    return 0;
}
```

### Results (Performance)  
**Runtime:**  0 ms
**Memory Usage:** 	1984 KB  


### 문제 URL (백준)  
https://www.acmicpc.net/problem/11727
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
