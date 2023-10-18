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
    string str; cin >> str;
    vector <char> vec;
    for (int i=0; i<str.size(); i++){
        vec.push_back(str[i]);
    }

    quickSort(vec, 0, str.size() - 1);
    for (int i=0; i<vec.size(); i++){
        cout<<vec[i];
    }
}
