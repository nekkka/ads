#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue <int> q1, q2; // Borya, Nurs

    int cnt;
    cnt = 0;
    int b;
    for (int i =0; i<5; i++) {
        int n;
        cin>>n;
        q1.push(n);
        
    }
    for (int i =0; i<5; i++){
        int k;
        cin>>k;
        q2.push(k);
        
    }

    while(!q1.empty() && !q2.empty()){
        cnt++;
        if (cnt == 1e6){
            cout<<"blin nichya";
            return 0;
        }
        if (q1.front()== 0 && q2.front()== 9){
            q1.push(q1.front());
            q1.push(q2.front());
            q1.pop();
            q2.pop();
        }
        else if (q1.front()== 9 && q2.front()== 0){
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop();
            q2.pop();
        }

        else if (q1.front() < q2.front()){
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop();
            q2.pop();
           
        }
        else {
            
            q1.push(q1.front());
            q1.push(q2.front());
            q1.pop();
            q2.pop();

        }

    }
    if (q1.empty()){
        cout<<"Nursik "<<cnt<<endl;
    }
    if (q2.empty()){
        cout<<"Boris "<<cnt<<endl;
    }

}