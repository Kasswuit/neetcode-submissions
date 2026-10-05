class Solution {
public:
    bool validPalindrome(string s) {
        int front = 0;
        int back = s.size()-1;
        while (front < back) {
            if (s[front] == s[back]){
                front++;
                back--;
            } else {
                if (strictPalindrome(s, front+1,back) 
                || strictPalindrome(s, front,back-1))
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
    bool strictPalindrome(const string& s, int f, int b) {
        while (f < b) {
            if (s[f] == s[b]) {
                f++;
                b--;
            } else {
                return false;
            }
        }
        return true;
    }
};