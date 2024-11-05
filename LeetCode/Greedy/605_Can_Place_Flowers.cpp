#include<bits/stdc++.h>

using namespace std;

/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, 
flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
and an integer n, return true if n new flowers can be planted in the flowerbed without violating 
the no-adjacent-flowers rule and false otherwise.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true ; 

        for (int i = 0; i < flowerbed.size(); i++){
            if ((i == 0 || flowerbed[i - 1] == 0) && 
               (flowerbed[i] == 0) && 
               (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1 ;
                n -- ;
            } 

            if (n == 0) return true ; 
        }
        
        return false ;
    }
};

/*
Approach
Iterate through the flowerbed array
if ith element is 0, it can be used to place a flower, but we have to check if its previous and next element is 
also 0 we can easily check it using the condition
          if(flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] ==0)
But this 'if' condition misses out on some test cases
If the ith element is the first element, flowerbed[i - 1] will go out of bound of the memory allocated to array so 
we need to add modify the condition.Also, if the ith element is the last element of the array then flowerbed[i + 1] 
will go out of bounds to the memory allocated to the array, so we need to add additional checing condition for that
Therefore, the proper if condition will be -:

if ((i == 0 || flowerbed[i - 1] == 0) && 
    (flowerbed[i] == 0) && 
    (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
*/