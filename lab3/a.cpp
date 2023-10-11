#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    queue<int> q;
    for (int i=0; i<t; i++){
        int val; cin>>val;
        q.push(val);
    }
    int n,m;
    cin>>n>>m;
    vector<int>v[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val; cin>>val;
            v[i].push_back(val);
        }
    }

    while(!q.empty()){
        int num = q.front();
        q.pop();
        vector<int> v1; 
        int row;
        for(int i=0;i<n;i++){
            if((v[i][0]<= num && num<=v[i].back()) or ((v[i][0]>= num && num>=v[i].back())) ){
                v1 = v[i];
                row = i;
            }
        }
        int l = 0; 
        int r = v1.size() - 1;

        int mid;
        int found = 0;
        if((row+1)%2==0){
        while(l <= r){
            mid = l + (r - l)/ 2;
            if(num < v1[mid]){
            r = mid - 1;
            }else if(num == v1[mid]){
                found=1;
           
            break;
            }else{
                l = mid + 1;
            }
        }
        }else{
        while(l <= r){
            mid = l + (r - l)/ 2;
            if(num > v1[mid]){
            r = mid - 1;
            }else if(num == v1[mid]){
                found=1;
           
            break;
            }else{
                l = mid + 1;
            }
        }
        }

        if(found==0){
            cout << -1<<endl;
        }
        if(found==1){
            cout <<row<<" "<< mid << endl;
        }

    }
    

    return 0;
}