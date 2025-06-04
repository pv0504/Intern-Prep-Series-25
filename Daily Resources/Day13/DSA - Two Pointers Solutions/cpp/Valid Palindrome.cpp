#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
    string cleaned;
    for (char c : s)
        if (isalnum(c)) cleaned += tolower(c);
    int i = 0, j = cleaned.size() - 1;
    while (i < j)
        if (cleaned[i++] != cleaned[j--]) return false;
    return true;
}
