#include<bits/stdc++.h>

using namespace std;
/*
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, 
return the day number of the year.

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Example 2:

Input: date = "2019-02-10"
Output: 41
*/

class Solution {
public:
    bool isLeapYear(int y){
        if(y%400 == 0 || (y%4 == 0 && y%100 !=0))
            return true;
        return false;
    }

    int dayOfYear(string date) {
        int yy = stoi(date.substr(0,4));
        int mm = stoi(date.substr(5,2));
        int dd = stoi(date.substr(8,2));
        int result = dd;
        vector<int> month ({31,28,31,30,31,30,
                            31,31,30,31,30,31});
        if(isLeapYear(yy)){
            month[1]=29;
        }
        for(int i=0;i<mm-1;i++){
            result += month[i];
        }
        return result;
    }

};