class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> space;
        for (int& ast : asteroids) {
            if (ast > 0) {
                space.push(ast);
            } else {
                bool alive = true;
                while (!space.empty() && space.top() > 0) {
                    if (space.top() < abs(ast)) {
                        space.pop();
                    } else if (space.top() == abs(ast)) {
                        space.pop();
                        alive = false;
                        break;
                    }
                    else {
                        alive = false;
                        break;
                    }
                }
                if (alive) {
                    space.push(ast);
                }
            }
        }
        stack<int> ansStack;
        int size = space.size();
        for (int i = 0; i < size; i++) {
            ansStack.push(space.top());
            space.pop();
        }
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            ans.push_back(ansStack.top());
            ansStack.pop();
        }
        return ans;
    }
};