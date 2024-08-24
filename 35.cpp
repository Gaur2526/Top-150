Problem Statement Break Down :

1. we have an m*n matrix
2. we have to return it in the spiral order

Solution :

// Optimised approach

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;

        if(matrix.size() == 0) return res;

        int cnt = 0;
        int size = matrix.size() * matrix[0].size();

        int row_start = 0;
        int col_start = 0;

        int row_end = matrix.size()-1;
        int col_end = matrix[0].size()-1;

        while(cnt < size){

            // first row

            for(int col = col_start;cnt < size && col<=col_end;col++){

                res.push_back(matrix[row_start][col]);
                cnt++;
            }
            row_start++;

            // last col

            for(int row = row_start;cnt < size && row<=row_end;row++){

                res.push_back(matrix[row][col_end]);
                cnt++;
            }
            col_end--;

            // last row

            for(int col = col_end;cnt < size && col>=col_start;col--){

                res.push_back(matrix[row_end][col]);
                cnt++;
            }
            row_end--;

            // first col

            for(int row = row_end;cnt < size && row>=row_start;row--){
                res.push_back(matrix[row][col_start]);
                cnt++;
            }
            col_start++;
        }
        return res;
    }
};

Time complexity : O(m * n) where m is the rows and n is the cols
Space complexity : O(m * n) 
