class Solution {
private:
    stack<int> opord;
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        for (string& token : tokens) {
            if (token == "+") {
                int second = opord.top();
                opord.pop();
                int first = opord.top();
                opord.pop();
                opord.push(first + second);
            }
            else if (token == "-") {
                int second = opord.top();
                opord.pop();
                int first = opord.top();
                opord.pop();
                opord.push(first - second);
            }
            else if (token == "*") {
                int second = opord.top();
                opord.pop();
                int first = opord.top();
                opord.pop();
                opord.push(first * second);
            }
            else if (token == "/") {
                int second = opord.top();
                opord.pop();
                int first = opord.top();
                opord.pop();
                opord.push(first / second);
            }
            else {
                opord.push(stoi(token));
            }
        }
        ans = opord.top();
        return ans;
    }
};
