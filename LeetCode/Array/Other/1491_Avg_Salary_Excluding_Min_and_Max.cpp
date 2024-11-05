#include<bits/stdc++.h>

using namespace std;

/*
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
Return the average salary of employees excluding the minimum and maximum salary. 
Answers within 10^-5 of the actual answer will be accepted.

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
*/

class Solution {
public:
    double average(vector<int>& salary) {
        double ans =0;
        int mn = INT_MAX , mx=INT_MIN;
        for(int i =0;i<salary.size();i++){
            mn = min(mn , salary[i]);
            mx = max(mx,salary[i]);
            ans +=salary[i];
        }
        ans = ans - mn - mx;
        ans = ans/(salary.size()-2);
        return ans;
    }
};

class Solution2 {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double ans =0;
        sort(salary.begin(),salary.end());
        for(int i=1;i<=n-2;i++){
            ans+=salary[i];
        }
        return ans/(n-2);
    }
};