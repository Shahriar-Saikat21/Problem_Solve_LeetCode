#include<bits/stdc++.h>

using namespace std;

/*
There is a school that has classes of students and each class will be having a final exam. 
You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand 
that in the ith class, there are totali total students, but only passi number of students will pass the exam.
You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed
to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class 
in a way that maximizes the average pass ratio across all the classes.
The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the 
total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided 
by the number of the classes.
Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of 
the actual answer will be accepted.

Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. 
The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485

*/

class Solution {
    #define pdi pair<double,int>
    // Here Greedy approach to find possible impact on avg to add new student in every class
    void heapPush(priority_queue<pdi>& maxheap,vector<vector<int>>& classes,int idx){
        double curr_avg = (double)classes[idx][0]/classes[idx][1];
        double new_avg = ((double)classes[idx][0]+1)/(classes[idx][1]+1);
        double possible_increment = new_avg - curr_avg;
        maxheap.push(make_pair(possible_increment,idx));
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pdi> maxheap;
        for(int i=0;i<n;++i)
            heapPush(maxheap,classes,i);
        
        while(extraStudents--){
            pdi curr = maxheap.top();
            maxheap.pop();

            //Add 1 extra student to curr index
            int idx = curr.second;
            classes[idx][0]++;
            classes[idx][1]++;

            heapPush(maxheap,classes,idx);
        }
        double final_avg=0.0;
        int total_students=0;
        for(int i=0;i<n;++i)
            final_avg += (double)classes[i][0]/classes[i][1];

        return final_avg/n;
    }
};

