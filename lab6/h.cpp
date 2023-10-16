#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partition(vector<char> &str, int low, int high)
{
    int pivot = high;
    int i = low;

    for (int j = low; j < high; j++) {

        if (str[j] < str[pivot]) {
            swap(str[i], str[j]);
            i++;
        }
    }
    swap(str[i], str[pivot]);
    return i;
}

void quickSort(vector<char> &str, int low, int high)
{
    if (low < high) {

        int pi = partition(str, low, high);

        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}


int main() {
    int n; cin >> n;
    vector<char>v;
    for (int i = 0; i < n; i++) {
        char a;cin>>a;
        v.push_back(a);
    }
    char c;cin>>c;
    v.push_back(c);
    quickSort(v, 0, n);
    int index;
    for(int i=0;i<n+1;i++){
        if(v[i]==c){
            index=i;
        }
    }
    if(index==n){
        cout<<v[0];
    }else{
        cout<<v[index+1];
    }
    
}
