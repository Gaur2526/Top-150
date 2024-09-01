Problem Statement Break Down :

1. we have an array of non-overlapping intervals and a new interval
2. we have to insert new interval into the intervals and merge if needed
3. we have to return the updated intervals array


Solution :


// Optimised approach

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;

        int i = 0;
        int n = intervals.size();
        // inserting those intervals which are less than new - interval

        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        // inserting those intervals which are overlapping

        while(i < n && intervals[i][0] <= newInterval[1]){

            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }

        res.push_back(newInterval);

        // inserting rest of the intervals

        while(i < n){

            res.push_back(intervals[i]);
            i++;
        }
       
       return res;

    }
};

Time complexity : O(n)
Space complexity : O(n)
