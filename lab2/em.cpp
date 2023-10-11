#include <bits/stdc++.h>

using namespace std;

struct Node{
  string data;
  int cnt;
  Node* next = 0;
  Node* prev = 0;
  
  Node(string data){
    this -> data = data;
    cnt = 1;    
  }
};

class LinkedList{
  Node* head;
  Node* tail;
  int size;
  
  public: 
   LinkedList(){
     head = 0;
     tail = 0;
     size = 0;
   }
   
   
   void push_front(string data){
     Node* new_node = new Node(data);
     if(head == 0){
       head = new_node;
       size = 1;
     }
     else{
       if(head -> data == data){
         head -> cnt++;
       }
       else if (head -> prev == 0){
         head -> prev = new_node;
         new_node -> next = head;
         head = new_node;
         size++;
       }
       }
     }
     void print(){
       Node*cur = head;
       cout << "All in all: " << size << endl;
       cout << "Students:" << endl;
       while(cur != 0){
         cout << cur -> data << endl;
         cur = cur -> next;
       }
     }
   
};


int main() {
  LinkedList l;
  int n;
  string s;
  cin >> n;
  for(int i = 0; i < n; i++ ){
    cin >> s;
    l.push_front(s);
  }
  l.print();
}
