#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for (string token : tokens) {
            if (isOperator(token)) {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                
                if (token == "+") s.push(a + b);
                else if (token == "-") s.push(a - b);
                else if (token == "*") s.push(a * b);
                else if (token == "/") s.push(a / b);
            } else {
                s.push(stoi(token));
            }
        }
        
        return s.top();
    }
    
private:
    bool isOperator(string s) {
        return s == "+" || s == "-" ||
               s == "*" || s == "/";
    }
};
