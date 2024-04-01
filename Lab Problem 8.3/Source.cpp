
#include <iostream>
#include <string>

using namespace std;

int convert_roman_to_int(string s);
int convert(char roman_literal);

int main() {
    string roman_number;

    while (true) {
        cout << "Enter Roman number or Q to quit: ";
        getline(cin, roman_number);
        
        if (roman_number == "Q") break;

        cout << roman_number << ": " << convert_roman_to_int(roman_number) << endl;
    }
}

int convert_roman_to_int(string s) {

    if (s.empty()) return 0;

    int lengthOfRomanLiteralString = static_cast<int>(s.length());

    int sum = convert(s[lengthOfRomanLiteralString - 1]);

    for (int i = lengthOfRomanLiteralString - 2; i >= 0; --i) {

        if (convert(s[i]) < convert(s[i + 1]))
            sum -= convert(s[i]);
        else
            sum += convert(s[i]);
    }
    return sum;
}

int convert(char roman_literal) {
    switch (roman_literal) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}
