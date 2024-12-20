#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string sum(const string& a, const string& b) {
    string res;
    int carry = 0;
    int maxl = max(a.length(), b.length());

    string afi = string(maxl - a.length(), '0') + a;
    string bfi = string(maxl - b.length(), '0') + b;

    for (int i = maxl - 1; i >= 0; --i) {
        int bitA = afi[i] - '0';
        int bitB = bfi[i] - '0';
        int sum = bitA + bitB + carry;

        res.insert(res.begin(), (sum % 2) + '0');
        carry = sum / 2;
    }

    if (carry) {
        res.insert(res.begin(), carry + '0');
    }

    return res;
}

int main() {
    string A = "101101";
    string B = "110011";

    bitset<6> abit(A);
    bitset<6> bbit(B);
    bitset<6> ares = abit & bbit;

    cout << "A AND B: " << ares << endl;

    string summ = sum(A, B);

    cout << "A+B: " << summ << endl;

    return 0;
}
