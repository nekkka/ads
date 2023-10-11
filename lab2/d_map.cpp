#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct node {
    int data;
    node* nxt = NULL;
    node() {
        data = 0;
    }
    node(int _data) {
        data = _data;
    }
    node(int _data, node* _nxt) {
        data = _data;
        nxt = _nxt;
    }
};

int main() {
    map<int, int> frequencyMap;
    int n;
    cin >> n;
    int beg;
    cin >> beg;
    node* head = new node(beg);
    node* cur = head;
    frequencyMap[cur->data]++;

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        node* newNode = new node(x);
        cur->nxt = newNode;
        cur = cur->nxt;
        frequencyMap[cur->data]++;
        //frequencyMap[x]++;
        //берет ли он в счет голову?
    }

    int maxFrequency = 1;
    vector<int>modes;
    
    for (map<int, int>::iterator it = frequencyMap.begin(); it!= frequencyMap.end(); it++) {
        if (it->second > maxFrequency) {
            maxFrequency = it->second;
        } 
    } 
    
    for (map<int, int>::iterator it = frequencyMap.begin(); it!= frequencyMap.end(); it++) {
        if (it->second == maxFrequency) {
            modes.push_back(it->first);}
    }

    sort(modes.rbegin(), modes.rend());

    for (int i = 0; i < modes.size(); i++) {
        cout << modes[i] << " ";
    }

    return 0;
}
