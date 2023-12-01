#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<int> v[n+1];
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}

int a,b;
cin>>a>>b;
        unordered_map<int,bool> k;
        queue<int> q;
        q.push(a);


        while(!q.empty()){
            int cur = q.front();
            q.pop();
            k[cur]=true;
            if(cur==b){
                    cout<<"YES";
                    return 0;
                    }


            for(auto i : v[cur]){
                    if(k[i]==false){

                            q.push(i);


                    }

            }
        }
        cout<<"NO";

return 0;
}