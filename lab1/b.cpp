#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector <int> ages(n);
    stack <int> youngerAges;

    for (int i = 0; i < n; i++) {
        cin >> ages[i];
 
        while (!youngerAges.empty() && youngerAges.top() > ages[i]) {
            youngerAges.pop(); // Удаляем более старший возраст из стека
        }
        
        if (youngerAges.empty()) {
            cout << "-1 ";
        } else {
            cout << youngerAges.top() << " ";
        }
        
        youngerAges.push(ages[i]); // Добавляем текущий возраст в стек
    }
    
    return 0;
    

}