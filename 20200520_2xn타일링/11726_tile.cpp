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