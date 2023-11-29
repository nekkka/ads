#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n][n];
queue<int> q;
vector<int> v[n];
unordered_map<int,int>m,k;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
        if(arr[i][j]==1){
            v[i].push_back(j);
        }
    }
}
int x,y;
cin>>x>>y;
x-=1;
y-=1;
q.push(x);
m[x]=0;
while(!q.empty()){
        int cur = q.front();
        k[cur]=1;


        q.pop();
        for(auto i : v[cur]){
                if(k[i]!=1){
                    q.push(i);
                    m[i]=m[cur]+1;
                    if(i==y){
                        cout<<m[i];
                        return 0;
                    }
                }


        }
    }


cout<<-1;

return 0;
}