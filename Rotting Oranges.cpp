class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mins = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
        while(!q.empty()) {
            int t = q.size();
            while(t--) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x > 0 && grid[x-1][y] == 1) {
                    q.push({x-1, y});
                    grid[x-1][y] = 0;
                }
                if(x < n - 1 && grid[x+1][y] == 1) {
                    q.push({x+1, y});
                    grid[x+1][y] = 0;
                }
                if(y > 0 && grid[x][y-1] == 1) {
                    q.push({x, y-1});
                    grid[x][y-1] = 0;
                }
                if(y < m - 1 && grid[x][y+1] == 1) {
                    q.push({x, y+1});
                    grid[x][y+1] = 0;
                }
            }
            if(!q.empty())
                mins++;
        }
        for(auto v : grid)
            for(int i : v)
                if(i == 1)
                    return -1;
        return mins;
    }
};