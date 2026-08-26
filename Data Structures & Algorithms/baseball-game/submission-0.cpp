class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        for (string& op : operations) {
            if (op == "+") {
                int temp = record.top();
                record.pop();
                int sum = record.top() + temp;
                record.push(temp);
                record.push(sum);
            }
            else if (op == "D") {
                int d = record.top() * 2;
                record.push(d);
            }
            else if (op == "C") {
                record.pop();
            }
            else {
                record.push(stoi(op));
            }
        }
        // sum stack
        int ans = 0;
        while (!record.empty()) {
            ans += record.top();
            record.pop();
        }
        return ans;
    }
};