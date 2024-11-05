#include<bits/stdc++.h>

using namespace std;


/*
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this 
notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly 
n times on the screen.

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Example 2:

Input: n = 1
Output: 0

*/

class Solution {
public:
   int solve(int n,int k,int val)
   {
       if(k>=n) return 0;
       if(n%k==0) return 2+solve(n,k+k,k);
       return 1+solve(n,k+val,val);
   }
    int minSteps(int n) {
        return solve(n,1,1);
    }
};

/*
so we have two Choice:-
C-1 copy the text and paste it(2 operations)
C-2 past the copied text(1 operations)

for EX:- n = 5
initially text on notepad text = 'A' count = 1
n%count==0, we can do the C-1 operation(op = 2)
now text = 'AA' count = 2
n%count!=0, can't perform C-1 but C-2 can perform(op = 1)
now text = 'AAA' count = 3
n%count!=0, can't perform C-1 but C-2 can perform(op = 1)
now count = 'AAAA' count = 4
n%count!=0, can't perform C-1 but C-2 can perform(op = 1)
now text  = 'AAAAA' count = 5.
Number of Operations  = 2+1+1+1 = 5

Ex:- n = 4
initially text on notepad text = 'A' count = 1
n%count==0, we can do the C-1 operation(op = 2)
now text = 'AA' count = 2
n%count==0, we can do the C-1 operation(op = 2)
now text = 'AAAA' count = 4
Number of Operations  = 2+2 = 4
*/