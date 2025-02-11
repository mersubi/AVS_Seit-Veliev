#include <iostream>
#include <cmath>
using namespace std;

double binaryToDecimal(const string& binary) {
    double decimal = 0.0;
    bool isFraction = false;
    double fractionMultiplier = 0.5;
    
    for (char bit : binary) {
        if (bit == '.') {
            isFraction = true;
            continue;
        }
        if (isFraction) {
            if (bit == '1') decimal += fractionMultiplier;
            fractionMultiplier /= 2;
        } else {
            decimal = decimal * 2 + (bit - '0');
        }
    }
    return decimal;
}

int main() {
    string binaryNumber;
    cout << "Введите дробное двоичное число: ";
    cin >> binaryNumber;
    
    cout << "Десятичное представление: " << binaryToDecimal(binaryNumber) << endl;
    
    return 0;
}
