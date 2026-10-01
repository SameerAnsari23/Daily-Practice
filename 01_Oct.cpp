class Solution {
public:
    int m, n;

    // Memoization   
    int memo[105][105][205];
    bool solve(int i, int j, int openCnt, vector<vector<char>>& grid) {
        openCnt += (grid[i][j] == '(') ? 1 : -1;

        // if (memo[i][j][openCnt] != -1) return memo[i][j][openCnt];

        if (openCnt < 0) return false;

        // Pruning: if remaining cells are fewer than required closing brackets
        int remainingSteps = (m - 1 - i) + (n - 1 - j);
        if (openCnt > remainingSteps) return false;

        if (i == m-1 && j == n-1) {
            return memo[i][j][openCnt] = (openCnt == 0);
        }

        if (memo[i][j][openCnt] != -1) return memo[i][j][openCnt];
        // recursive relation
        // right
        if (i + 1 < m) {
            if (solve(i+1, j, openCnt, grid)) {
                return memo[i][j][openCnt] = true;
            }
        }

        // down 
        if (j + 1 < n) {
            if (solve(i, j+1, openCnt, grid)) {
                return memo[i][j][openCnt] = true;
            }
        }

        return memo[i][j][openCnt] = false;
    }



    /* Recursive solution
    bool solve(int i, int j, int openCnt, vector<vector<char>>& grid) {
        openCnt += (grid[i][j] == '(') ? 1 : -1;
        if (openCnt < 0) return false;
        
        // Pruning: if remaining cells are fewer than required closing brackets
        int remainingSteps = (m - 1 - i) + (n - 1 - j);
        if (openCnt > remainingSteps) return false;

        if (i == m-1 && j == n-1) {
            return (openCnt == 0);
        }


        // recursive relation
        // right
        if (i + 1 < m) {
            if (solve(i+1, j, openCnt, grid)) {
                return true;
            }
        }

        // down 
        if (j + 1 < n) {
            if (solve(i, j+1, openCnt, grid)) {
                return true;
            }
        }

        return false;
    }*/


    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // some tests
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        if ((m + n - 1) % 2 != 0) return false;

        return solve (0, 0, 0, grid);

    }
};
