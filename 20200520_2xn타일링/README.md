# 11726_2xn 타일링 

2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
   

**입력**  
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

**출력**  
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

**Example1:**   
```
2

2
```

**Example2:**   
```
9

55
```

## trial
### Intuition
```
dp를 이용하는 문제였다.
n의 값에 따라 일정하게 경우의 수가 증가하므로 점화식을 세우면
dp[i]=dp[i-1]+dp[i-2]가 된다.

```

### Codes  
```cpp
#include <iostream>
using namespace std;

#define MAX 1001
int main(){
    int dp[MAX]={0,};
    int n;
    int result;
    cin>>n;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%10007;
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
https://www.acmicpc.net/problem/11726
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
