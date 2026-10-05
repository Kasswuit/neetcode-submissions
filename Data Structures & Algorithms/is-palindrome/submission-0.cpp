class Solution {
public:
    bool isAlphaNumeric(char c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') return (c -'A' + 'a');
        return c;
    }
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size()-1;
        while (front < back) {
            if (!isAlphaNumeric(s[front])) {
                front++;
            } else if (!isAlphaNumeric(s[back])) {
                back--;
            } else {
                if (toLower(s[front]) != toLower(s[back])) return false;
                front++;
                back--;
            }
        }
        return true;
    }
};
