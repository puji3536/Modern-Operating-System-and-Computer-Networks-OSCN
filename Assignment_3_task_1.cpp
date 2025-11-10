#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


// XOR between two binary strings
string findXor(string a, string b) {
    string result = "";
    for (int i = 1; i < b.length(); i++)
        result += (a[i] == b[i]) ? '0' : '1';
    return result;
}

// Modulo-2 division
string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);

    while (pick < dividend.length()) {
        if (tmp[0] == '1')
            tmp = findXor(divisor, tmp) + dividend[pick];
        else
            tmp = findXor(string(pick, '0'), tmp) + dividend[pick];
        pick++;
    }

    if (tmp[0] == '1')
        tmp = findXor(divisor, tmp);
    else
        tmp = findXor(string(pick, '0'), tmp);

    return tmp;
}

// Encode data with CRC
string encodeData(string data, string key) {
    int keyLen = key.length();
    string appendedData = data + string(keyLen - 1, '0');
    string remainder = mod2div(appendedData, key);
    cout << "Remainder: " << remainder << endl;
    return data + remainder;
}

int main() {
    string data = "1101011011";
    string key = "10011"; // x^4 + x + 1

    cout << "=== TASK 1 ===" << endl;
    cout << "Data: " << data << endl;
    cout << "Key: " << key << endl;

    string codeword = encodeData(data, key);
    cout << "Transmitted Codeword: " << codeword << endl;

    return 0;
}

