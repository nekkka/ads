#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool backspaceCompare(string S, string T) {
    stack <char> stack1, stack2;
    for (char c : S) {  
        if (c != '#') {
            stack1.push(c);
        } else if (!stack1.empty()) {
            stack1.pop();
        }
    }

    for (char c : T) {
        if (c != '#') {
            stack2.push(c);
        } else if (!stack2.empty()) {
            stack2.pop();
        }
    }

    return stack1 == stack2;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (backspaceCompare(s1, s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
