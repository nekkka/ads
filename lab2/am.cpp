#include <bits/stdc++.h>

using namespace std;

vector <int> v;

struct Node{
  int data;
  Node* nxt = 0;
  Node* prev = 0;
  
  Node(int data){
    this -> data = data;
  }
  
};

class LinkedList{
  Node* head;
  Node* tail;
  
  
public:
  LinkedList(){
    head = 0;
    tail = 0;
  }
  
  void push_back(int data){
    Node* new_node = new Node(data);
    if(head == 0){
      head = tail = new_node;
    }
    else{
      tail -> nxt = new_node; 
      new_node -> prev = tail;
      tail = new_node;
    }
  } //done
  
  void find_value(int k){
    Node* cur = head;
    int min = INT_MAX;
    int index = 0;
    while(cur!= 0){
      v.push_back(abs(k - cur->data));
      cur = cur -> nxt;
    }
    for(int i = 0; i < v.size(); i++){
      if(v[i] < min){
        min = v[i];
        index = i;
      }
    }
    cout << index;
  }
  
};

int main() {
  
  LinkedList l;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    l.push_back(x);
  }
  int k;
  cin >> k;
  l.find_value(k);
}
