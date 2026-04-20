class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i =0 ;i < n;i++){
            if(tokens[i] == "+") {
                int one = s.top();
                s.pop();
                int two = s.top();
                s.pop();
                s.push(one+two);
            }
            else if(tokens[i] == "-"){
                int one = s.top();
                s.pop();
                int two = s.top();
                s.pop();
                s.push(two-one);
            }
            else if(tokens[i] == "*"){
                int one = s.top();
                s.pop();
                int two = s.top();
                s.pop();
                s.push(two*one);
            }
            else if(tokens[i] == "/"){
                int one = s.top();
                s.pop();
                int two = s.top();
                s.pop();
                if(one !=0 )s.push(two/one);
            }
            else s.push(stoi(tokens[i]));
            
        }
        return s.top();
    }
};