#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001
int main(){
    int N;
    int res;
    int card[MAX]={0,};
    int dp[MAX]={0,};
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>card[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i],card[j]+dp[i-j]);
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}