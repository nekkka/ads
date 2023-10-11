#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; //2
    cin >>n;

    while(n--){
        deque<int>d;
        int k;
        cin >>k;

        for(int i = k; i>0; i-- ){
            d.push_front(i);
            // 
            for(int j = 1; j<=i; j++){
                int l = d.back(); // 
                d.pop_back(); // 
                d.push_front(l); // 
            }
        }
        while(!d.empty()){
            cout << d.front() << " ";
            d.pop_front();
        }
        cout << endl;        
    }
}