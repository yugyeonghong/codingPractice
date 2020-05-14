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