#include<iostream>
#include <map>
#include <iomanip>

using namespace std;

map <string, double> grades {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0}
};



bool comparator(pair<pair <string, string>, double> a, pair<pair <string, string>, double> b) {
    if (a.second == b.second) {
        if (a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        }
        else
            return a.first.first < b.first.first;
    }
    else
        return a.second < b.second;
}

int partition(pair<pair <string, string>, double> arr[], int l, int r) {
    int pivot = r;
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (comparator(arr[j], arr[pivot])) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i + 1;
}

void quickSort(pair<pair<string, string>, double> arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

double gpa(pair <string, int> arr[], int size) {
    double sum = 0;
    double credits = 0;
    for (int i = 0; i < size; i++) {
        double g = grades[arr[i].first];
        sum += g * arr[i].second;
        credits += arr[i].second;
    }

    return sum / credits;
}


int main() {
    int n; cin >> n;
    pair<pair <string, string>, double> journal[n];
    for (int i = 0; i < n; i++) {
        string name, surname;
        cin >> surname >> name;
        int numD; cin >> numD;
        pair <string, int> arr[numD];
        for (int j = 0; j < numD; j++) {
            cin >> arr[j].first >> arr[j].second;
        }
        double gpaG = gpa(arr, numD);
        journal[i].first.first = surname;
        journal[i].first.second = name;
        journal[i].second = gpaG;
    }

    quickSort(journal, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << journal[i].first.first << " " <<  journal[i].first.second << " " << setprecision(3) << fixed << journal[i].second << endl;
    }


}
