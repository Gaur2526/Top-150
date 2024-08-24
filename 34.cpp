Problem Statement Break Down : 

1. we have a 9*9 sudoku board
2. we have to return whether it's valid or not
3. sudoku board is valid if :
    a) Each row must contain the digits 1-9 without repetition.
    b) Each column must contain the digits 1-9 without repetition.
    c) Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
4. return true if valid otherwise return false

Solution : 

// Optimised approach

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> subboxes(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                char num = board[i][j];

                if(num == '.') continue;
                
                int subboxes_index = (i/3) * 3 + (j/3);

                if(rows[i].count(num) || cols[j].count(num) || subboxes[subboxes_index].count(num)){

                    return false;
                }

                rows[i].insert(num);
                cols[j].insert(num);
                subboxes[subboxes_index].insert(num);
            }
        }

        return true;
    }
};

Time complexity : O(81) ~ O(1)
Space complexity : O(243) ~ O(1)
