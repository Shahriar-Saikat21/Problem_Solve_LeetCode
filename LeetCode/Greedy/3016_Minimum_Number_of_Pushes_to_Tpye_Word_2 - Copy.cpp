#include<bits/stdc++.h>

using namespace std;

/*
You are given a string word containing lowercase English letters.
Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used 
to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one 
time to type "a", two times to type "b", and three times to type "c" . It is allowed to remap the keys numbered 2 
to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be 
mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
Return the minimum number of pushes needed to type word after remapping the keys.
An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 
do not map to any letters.

Example 1:

Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.

Example 2:

Input: word = "xyzxyzxyzxyz"
Output: 12
Explanation: The remapped keypad given in the image provides the minimum cost.
"x" -> one push on key 2
"y" -> one push on key 3
"z" -> one push on key 4
Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
It can be shown that no other mapping can provide a lower cost.
Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, 
but to map all the letters.

Example 3:

Input: word = "aabbccddeeffgghhiiiiii"
Output: 24
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
"f" -> one push on key 7
"g" -> one push on key 8
"h" -> two pushes on key 9
"i" -> one push on key 9
Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
It can be shown that no other mapping can provide a lower cost.

*/

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26,0);

        // Count how many times to push each character
        for (char c : word) {
            cnt[c - 'a']++;
        }

        // Sort Descending Order
        sort(cnt.rbegin(), cnt.rend());

        int ans = 0;

        for (int i = 0; i < 26; ++i) {
            if(cnt[i] == 0) break;
            ans += (i / 8 + 1) * cnt[i];
        }

        return ans;
    }
};

/*
Intuition
The core idea behind solving this problem lies in optimizing the key mapping to minimize the total number of key 
presses required to type a given word. The intuition stems from the observation that in an optimal mapping, 
the most frequently occurring letters should be assigned to keys that require the least number of presses.
Consider a standard phone keypad with 8 available keys (2-9). Each key can be pressed multiple times to access 
different letters. For instance, pressing a key once might give you the first letter, twice for the second letter, 
and so on. With this in mind, the optimal strategy would be to assign the 8 most frequent letters to single presses 
across the 8 keys, the next 8 most frequent letters to double presses, and continue this pattern.

This approach naturally leads to a greedy algorithm. By sorting the letters based on their frequency in descending 
order, we can ensure that the most common letters are assigned to the easiest-to-access positions on the keypad.

Approach
The solution implements a greedy algorithm that can be broken down into several key steps:

Frequency Counting:
The first step involves counting the frequency of each letter in the input word. 
This is achieved by iterating through each character in the word and incrementing a counter for the corresponding 
letter in an array. The array letterFrequency is initialized with 26 elements, each representing a letter of the 
alphabet (a-z).
This step has a time complexity of O(n), where n is the length of the input word.

Sorting Frequencies:
After counting the frequencies, the next step is to sort these frequencies in descending order. 
This is crucial for the greedy approach, as it allows us to assign the most frequent letters to the most accessible 
key positions.

Here, a new array sortedFreq is created and populated with the frequency counts. 
The use of Integer objects instead of primitives allows for the use of Collections.reverseOrder() in the sorting 
process, which sorts the array in descending order.
The time complexity of this step is O(1) since we're sorting a fixed-size array of 26 elements.

Calculating Total Presses:
The final step involves calculating the total number of key presses required based on the sorted frequencies. 
This is where the greedy strategy comes into play.
The loop iterates through the sorted frequencies. For each frequency:

i / 8 + 1 determines the number of presses required for the current letter. The first 8 letters (indices 0-7) 
require 1 press, the next 8 (indices 8-15) require 2 presses, and so on.
This number of presses is multiplied by the frequency of the letter (sortedFreq[i]).
The result is added to the total number of presses.
The loop breaks early if it encounters a frequency of 0, as this indicates that all non-zero frequencies have been 
processed.

This step has a time complexity of O(1) since it always processes at most 26 elements.

Returning the Result:
After calculating the total number of presses, the method returns this value as the final result.

return totalPresses;
The greedy nature of this approach ensures that the most frequent letters are assigned to the most accessible key 
positions (requiring fewer presses), thereby minimizing the total number of presses required to type the word.

This solution elegantly handles various scenarios:

For words with a small number of unique letters, it efficiently assigns each letter to a single press on different 
keys.For words with many unique letters, it prioritizes the most frequent ones, assigning them to single presses 
and less frequent ones to multiple presses.
It naturally handles cases where some keys might not be used at all, as it only processes letters that actually 
appear in the word.The approach is particularly effective because it takes advantage of the constraint that 
there are only 26 possible letters. This allows for the use of fixed-size data structures and sorting algorithms 
that operate in constant time relative to the input size.
*/