class Solution {
private:
    stack<string> opord;
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        for (string& token : tokens) {
            if (token == "+") {
                int second = stoi(opord.top());
                opord.pop();
                int first = stoi(opord.top());
                opord.pop();
                opord.push(to_string(first + second));
            }
            else if (token == "-") {
                int second = stoi(opord.top());
                opord.pop();
                int first = stoi(opord.top());
                opord.pop();
                opord.push(to_string(first - second));
            }
            else if (token == "*") {
                int second = stoi(opord.top());
                opord.pop();
                int first = stoi(opord.top());
                opord.pop();
                opord.push(to_string(first * second));
            }
            else if (token == "/") {
                int second = stoi(opord.top());
                opord.pop();
                int first = stoi(opord.top());
                opord.pop();
                opord.push(to_string(first / second));
            }
            else {
                opord.push(token);
            }
        }
        ans = stoi(opord.top());
        return ans;
    }
};
