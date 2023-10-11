#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    int cnt;
    Node *prev= 0;
    Node *next = 0;
    Node (int data){
        this->data = data;
        cnt =1;
    }
};
class LinkedList{
    Node *head;
    Node *tail;

    public:
        LinkedList(){
        head = 0;
        tail = 0;
        }
    void push_back(int data){
        Node *newnode = new Node(data);
        if (head == 0){
            head = newnode;
        }
        else{
            Node *cur = head;
            while(cur!=0){
                if(cur ->data == data){
                    cur -> cnt++;
                }
                else if (cur->next ==0){
                    cur->next = newnode;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    int maximumCount(){
        Node *cur = head;
        int maxi =0;
        while(cur!=0){
            if(cur->cnt > maxi){
                maxi = cur->cnt;
            }
            cur=cur->next;
        }
        return maxi;
    }
    void findModa(){
        vector<int> ans;
        Node *cur = head;
        while(cur!=0){
            if(cur->cnt == maximumCount()){
                ans.push_back(cur->data);
            }
            cur = cur -> next;
        }
        sort(ans.rbegin(),ans.rend());
        for (int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }
};

int main(){
    int n;
    cin>>n;
    LinkedList MyList;
    for (int i=0; i<n; i++){
        int k;
        cin>>k;
        MyList.push_back(k);
    }
    MyList.findModa();
}