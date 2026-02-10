#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 241. Different Ways to Add Parentheses

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        
        // Traverse through the expression to find operators
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            
            // If the current character is an operator
            if (c == '+' || c == '-' || c == '*') {
                // Recursively divide into left and right subexpressions
                vector<int> leftPart = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightPart = diffWaysToCompute(expression.substr(i + 1));
                
                // Combine the results of left and right parts based on the current operator
                for (int left : leftPart) {
                    for (int right : rightPart) {
                        int val = 0;
                        if (c == '+') {
                            val = left + right;
                        } else if (c == '-') {
                            val = left - right;
                        } else if (c == '*') {
                            val = left * right;
                        }
                        result.push_back(val);
                    }
                }
            }
        }
        
        // Base case: if the expression is a pure number, return it as an integer
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        return result;
    }
};
