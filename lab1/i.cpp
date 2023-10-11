#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue <int> q1, q2;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i = 0; i < n; i++){
        if (s[i]=='K') {
            q1.push(i);
        }
        else  {q2.push(i);}
    }

    while(!q1.empty() && !q2.empty()){
        if (q1.front() > q2.front()){
            q2.push(q2.front()+n);
        }
        else {
            q1.push(q1.front()+n);
        }
        q1.pop();
        q2.pop();
}
    if (q2.empty()){
        cout<<"KATSURAGI"<<endl;
    }
    if (q1.empty()){
            cout<<"SAKAYANAGI"<<endl;
        }



}