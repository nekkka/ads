#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
    deque <int> deq;
    char symb;
    int numb;
    while(true){
        cin>>symb;
        if (symb == '!'){
            break;
        }
    
    
        else if (symb == '*'){
            if (deq.empty()){
                cout<<"error"<<endl;
                
            } 
            else{
                int b = deq.front() + deq.back();

                if (!deq.empty()) deq.pop_front();
                if (!deq.empty()) deq.pop_back();
                cout<<b<<endl;
            }       
           
        }
        if (symb == '+'){
            cin>>numb;
            deq.push_front(numb);
        }
        if (symb == '-'){
            cin>>numb;
            deq.push_back(numb);
        }
    }

}