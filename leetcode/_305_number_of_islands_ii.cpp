// Unfinished

class Solution
{
public:
    vector<int> numIslands2(int nrow, int ncol, vector<pair<int, int>>& positions)
    {
        using std::vector;

        vector<vector<int>> map(m, std::vector<int>(n, 0));

        std::function<bool(int, int, int, int)> dfs_paint = [&map, &dfs_paint, nrow, ncol](int r, int c, int old_color, int new_color) -> bool
        {
            // Out of bound
            if (!(r >= 0 && r < nrow && c >= 0 && c < ncol))
            {
                return false;
            }
            // Out of island
            if (map[r][c] != old_color)
            {
                return false;
            }

            // paint the island with new color
            map[r][c] = new_color;
            dfs_paint(r+1, c, old_color, new_color);
            dfs_paint(r-1, c, old_color, new_color);
            dfs_paint(r, c+1, old_color, new_color);
            dfs_paint(r, c-1, old_color, new_color);
            return true;
        };

        int count = 0;
        // TODO: unfinished work

        return count;
    }
};
