#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int counter = 1;
    int candidate = 2;
    queue<int> primeQueue;

    while (counter <= n) {
        if (isPrime(candidate)) {
            primeQueue.push(candidate);
            counter++;
        }
        candidate++;
    }

    if (!primeQueue.empty()) {
        cout << primeQueue.back();
    }

    return 0;
}
