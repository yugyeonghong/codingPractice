#include <iostream>
using namespace std;
#define MAX 13
int k;
int S[MAX];
int visited[MAX]={0,};

void dfs(int cur, int len){ //cur: 현재 위치 || len: 조합 길이
    if(cur==k&&len==6){
        for(int i=0;i<k;i++){
            if(visited[i]==1){
                cout<<S[i]<<" ";
            }
        }
        cout<<endl;
    }
    if(cur==k) return;
    visited[cur]=1;
    dfs(cur+1,len+1);
    visited[cur]=0;
    dfs(cur+1,len);
}

int main(){
    while(1){
        cin>>k;
        if(k==0) 
            break;
        for(int i=0;i<k;i++){
            cin>>S[i];
        }
        dfs(0,0);
        cout<<endl;
    }
    return 0;
}