#include<bits/stdc++.h>

using namespace std;

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

*/

class Solution {
public:
    bool isValid(string s){
      stack<char> stack;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '['){
                stack.push(c);
            }else if (c == ')'){
                if(stack.empty() || stack.top() != '(') return false;
                stack.pop();
            }else if (c == '}'){
                if(stack.empty() || stack.top() != '{') return false;
                stack.pop();
            }else if (c == ']'){
                if (stack.empty() || stack.top() != '[') return false;
                stack.pop();
            }
        }

        return stack.empty();
    }
};