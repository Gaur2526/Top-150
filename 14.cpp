Problem Statement Break Down :

1. we have an two integer array gas and cost
2. the amount of gas at particular station i  is gas[i]
3. the cost of moving from i-th to (i+1)th station is cost[i]
4. all the stations are arranged in a circular manner
5. we have to return the starting point from where we will return to that index without empty gas tank

Solution : 

// Optimised approach

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total_gas = 0;
        int curr_gas = 0;
        int start_index  = 0;

        for(int i=0;i<gas.size();i++){

            total_gas = total_gas + gas[i] - cost[i];
            curr_gas = curr_gas + gas[i]  - cost[i];

            if(curr_gas < 0){

                start_index = i + 1;

                curr_gas = 0;
            }
        }

        if(total_gas >= 0) return start_index;

        return -1; 
        
    }
};

Time complexity : O(n)
Space complexity : O(1)
