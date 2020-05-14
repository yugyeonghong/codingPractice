# 1912_연속합 

n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.    

**입력**  
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

**출력**  
첫째 줄에 답을 출력한다.

**Example1:**   
```
10
10 -4 3 1 5 6 -35 12 21 -1

33
```

**Example2:**   
```
10
2 1 -4 3 4 -4 6 5 -5 1

14
```

**Example3:**   
```
5
-1 -2 -3 -4 -5

-1
```

## trial
### Intuition
```
dp를 사용하는 문제였다.
점화식으로 dp[i]=dp[i]+dp[i-1]를 이용하여 앞에서부터 더한 값과 새로운 값을 비교하여 최댓값을 출력하도록 하였다.
arr 배열에는 입력한 n의 개수만큼 받은 값을 넣었고, dp 배열에는 arr 배열에서 현재값과 이전값+현재값 중 큰 값을 넣어서 arr의 첫번째 idx의 값으로 지정해놓은 ans값과 비교하여 그 중 최댓값으로 ans 값을 갱신시켜주었다.

```

### Codes  
```cpp
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
int main(){
    int n;
    int arr[MAX]={0,};
    int dp[MAX]={0,};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[0]=arr[0];
    int ans=arr[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+arr[i],arr[i]); // 앞에서부터 더한 값과 새로운 값 비교
        ans=max(dp[i],ans);
    }
    cout<<ans;
    return 0;
}
```
### Results (Performance)  
**Runtime:**  28 ms O(n^2)
**Memory Usage:** 	2644 MB  


### 문제 URL (백준)  
https://www.acmicpc.net/problem/1912
=======
# codingPractice
coding practice
>>>>>>> cece3b883c91a6735a3bcace6008593058bf11bb
