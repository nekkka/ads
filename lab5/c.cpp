#include <iostream>
#include <vector>
using namespace std;

struct MaxHeap {
    vector<long long> heap;
   // parent 3 7 8
    long long parent(long long i) {
        return (i - 1) / 2;
    }
    long long left(long long i) {
        return 2 * i + 1;
    }
    long long right(long long i) {
        return 2 * i + 2;
    }
    void insert(long long value) {
        this->heap.push_back(value);
        long long i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    int extractMax() {
        if (this->heap.size() == 0) return 0;
        if (this->heap.size() == 1) {
            long long root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }
    void print(){
        for(long long i = 0; i < heap.size(); i++){
            cout << heap[i] << ' ';
        }
        cout << endl;
    }
    void heapify(long long i) {
        long long l = this->left(i);
        long long r = this->right(i);
        long long smallest = i;
        if (l < this->heap.size() && this->heap[l] > this->heap[i])
            smallest = l;
        if (r < this->heap.size() && this->heap[r] > this->heap[smallest])
            smallest = r;
        if (smallest != i) {
            swap(this->heap[i], this->heap[smallest]);
            this->heapify(smallest);
        }
    }
    void answer(int x) {
        long long answer=0;
        while (x--) {
            long long m1 = extractMax();
            answer+=m1;
            insert(m1-1);

        }
        cout<<answer;
    }

};



int main() {
    MaxHeap heap;
    long long n,m; cin >> n>>m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        heap.insert(x);
    }

    heap.answer(m);


}
