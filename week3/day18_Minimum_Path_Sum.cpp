class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //dynamic programming
        if(grid.size() == 0) return 0;
        int iLen = grid[0].size();
        int jLen = grid.size();
        for(int i=1; i<iLen; i++)//find current sum for row 0
            grid[0][i] += grid[0][i-1];
        for(int i=1; i<jLen; i++)//same for column 0
            grid[i][0] += grid[i-1][0];
        for(int i=1; i<jLen; i++){//for all other points add in sum the min from
            for(int j=1; j<iLen; j++){//left and up until you reach the end
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[jLen-1][iLen-1];
    }
};
