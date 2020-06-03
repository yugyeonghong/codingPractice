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