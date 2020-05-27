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