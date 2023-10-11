#include <iostream>
#include <cassert>
using namespace std;

struct node {
  int data;
  node *nxt = 0;

  node() {
    data = 0;
  }
  node(int _data) {
    data = _data;
  }

  node(int _data, node *_nxt) {
    data = _data;
    nxt = _nxt;
  }



};
// NULL --> o --> o --> NULL

struct linked_list {
  node *head = 0;

  node* get_tail() {
    if (head == 0)
      return 0;
    node *cur = head;
    while (cur->nxt != 0)
      cur = cur->nxt;
    return cur;
  }

  node* get(int i) {
    // return node at pos i or return NULL
    node *cur = head;
    for (int j = 0; j < i; j++) {
      if (cur == 0)
        return 0;
      cur = cur->nxt;
    }
    return cur;
  }

  void insert_begin(int data) {
    node *new_node = new node(data, head);
    head = new_node;
  }

  void insert_tail(int data) {
    node *tail = get_tail();
    node *new_node = new node(data);
    tail->nxt = new_node;
  }

  void insert(int i, int data) {
    if (i == 0) {
      insert_begin(data);
      return;
    }
    node *A = get(i-1);
    if (A == 0) {
      insert_tail(data);
      return;
    }
    node *B = A->nxt;
    node *new_node = new node(data, B); // new -> B
    A->nxt = new_node; // A -> new
  }

  void output() {
    cout << "[";
    node *cur = head;
    while (cur != 0) {
      cout << cur->data;
      cur = cur->nxt;
      if (cur == 0)
        cout << "]";
      else
        cout << ", ";
    }
    cout << "\n";
  }

  void del_begin() { // oldhead--> newhead-->
    if (head == 0)
      return;
    node *old_head = head;
    head = head->nxt;
    delete old_head; // no memory leakage
  }
  void del_end() { // o--> o--> o-->
    if (head == 0) // empty list
      return;
    if (head->nxt == 0) { // head is a tail
      delete head;
      head = 0;
      return;
    }
    node *cur = head;
    while (cur->nxt->nxt != 0) // search guy before the tail
      cur = cur->nxt;
    delete cur->nxt;
    cur->nxt = 0;
  }
  void del(int i) {
    // exc
  }
};
int main(){
    linked_list MyList;
    int n;
    cin >> n;
    int beg;
    cin >> beg;
    MyList.insert_begin(beg);
    for (int i = 0; i < n-1; i++) {
        int num;
        cin >> num;
        MyList.insert_tail(num);
    }
    
    int k; // Объявляем переменную k
    cin >> k; // Считываем значение k

    int smeshenie = 0;
    int nearest = MyList.head != nullptr ? MyList.head->data : 0; // Добавляем проверку на nullptr
    node *current = MyList.head;
    int currentOffset = 0;
    while (current != nullptr) {
        if (abs(current->data - k) < abs(nearest - k)) {
            nearest = current->data;
            smeshenie = currentOffset;
        }
        current = current->nxt; // Заменяем current->next на current->nxt
        currentOffset++;
    }

    cout << smeshenie << endl;

    return 0;
}
