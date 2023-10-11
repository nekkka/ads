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
    int supercounter = 1;
    int candidate = 2;
    queue<int> SuperPrime;

    while (supercounter <= n) {
        if (isPrime(candidate)) {
            if (isPrime(counter)) {
                SuperPrime.push(candidate);
                supercounter++;
            }
            counter++;
        }
        candidate++;
    }

    if (!SuperPrime.empty()) {
        cout << SuperPrime.back();
    }

    return 0;
}
