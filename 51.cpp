Problem Statement Break Down :

1. we have some spherical ballons tapped on a flat wall represents the xy plane
2. the ballon are represented as 2-d integer array points where points[i] = [xstart,xend] denotes the ballon horizontal diameter
3. we have no idea about the y-coordinates
4. arrow will be shoot in +y axis for different x axis
5. a ballon burst only if xstart <= x <= xend
6. we have to return the min number of arrows required to shoot all ballons
7. a arrow can shoot infinite ballons which comes in his direction


Solution :


// Optimised approach 

bool compare(const vector<int> &a,const vector<int> &b){ // we are sorting the array on the basis of second element of each vector so that overlapping intervals can be shoot down by 1 arrow 

    return a[1] < b[1];
}

class Solution {

public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(),points.end(),compare);
        
        int arrow = 1;
        int end = points[0][1];

        for(int i=1;i<points.size();i++){
               
            if(points[i][0] > end){ // if start of the certain interval is greater than the previous interval end means we need a new array to shoot
                arrow++;
                end = points[i][1]; // here we are updating the end of the new interval 
            }
        }
        
        return arrow;
    }
};

Time complexity : O(nlogn)
Space complexity : O(1)
