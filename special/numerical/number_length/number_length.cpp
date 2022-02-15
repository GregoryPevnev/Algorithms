#include <iostream>
#include <cmath>

using namespace std;

int number_length(long num) {
    int val = abs(num); // Handling both negative and positive in the same way

    if (val == 0) return 1;

    long decimals = (long) floor(log10((double) val));

    return decimals + 1;
}

int main() {
    cout << number_length(1234) << endl;

    cout << number_length(-1234) << endl;

    cout << number_length(14) << endl;

    cout << number_length(1) << endl;

    return 0;
}
