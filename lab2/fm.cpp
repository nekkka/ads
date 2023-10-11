#include <bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  Node* next = 0;
  Node* prev = 0;
  
  Node(int data){
    this -> data = data;  
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
   
   void push_back(int data){
    Node* new_node = new Node(data);
    if(head == 0){
      head = new_node;
    }
    else{
      Node * cur = head;
      while(cur!=0){
        if(cur->next ==0){
          cur->next = new_node;
          break;
        }
        cur = cur->next;
      }
    }
    size++;
  }

  void push_pos(int data, int position){
        Node* new_node = new Node(data);
        if(head == 0){
          head = new_node;
        }
        else if (position == 0){
          new_node -> next = head;
          head->prev = new_node;
          head= new_node;
        }
        else{
          Node *cur = head;
          int i=1;
          while(cur!=0){
            if (i==position){
              new_node->next = cur->next;
              cur->next = new_node;
              break;
            }
            cur =cur->next;
            i++;
          }
        }
        size++;

  }
  void print(){
    Node *cur = head;
    while(cur!=0){
      cout<<cur->data<<" ";
      cur= cur-> next;
    }
  }

   
};


int main() {
  LinkedList l;
  int n;
  cin >> n;
  int date, pos;
  for(int i = 0; i < n; i++ ){
    int s;
    cin >> s;
    l.push_back(s);
  }
  cin>>date>>pos;
  l.push_pos(date, pos);
  l.print();
}
