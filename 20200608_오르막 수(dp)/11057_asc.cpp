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