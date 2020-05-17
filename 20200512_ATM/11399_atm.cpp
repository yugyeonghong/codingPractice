#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000
int main(){
    int N;
    int arr[MAX];
    int result[MAX];
    int ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    result[0]=arr[0];
    ans=arr[0];
    for(int i=1;i<N;i++){
        result[i]=arr[i]+result[i-1];
        ans+=result[i];
    }
    cout<<ans;
    return 0;
}