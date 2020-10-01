class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> m; // cut position, count of such positions
        int x = wall.size();
        if(x == 0)
            return 0;
        int y, ans = 0;
        for(int i=0; i<x; i++) 
        {
            y = wall[i].size();
            int wid = 0;
            for(int j=0; j<y-1; j++)
            {
                wid += wall[i][j];
                m[wid]++;
                ans = max(ans, m[wid]);
            }
        }
        return (x - ans);
    }
};