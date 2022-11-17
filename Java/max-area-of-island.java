class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                maxArea = Math.max(maxArea, dfs(grid, row, col));
            }
        }
        return maxArea;
    }

    public int dfs(int[][] grid, int row, int col) {
        int area = 0;
        if (row < 0 || row == grid.length || col < 0 || col == grid[0].length || grid[row][col] == 0) {
            return area;
        }

        // Mark part of island as visited
        grid[row][col] = 0;
        area++;
        area += dfs(grid, row + 1, col);
        area += dfs(grid, row - 1, col);
        area += dfs(grid, row, col + 1);
        area += dfs(grid, row, col - 1);

        return area;
    }
}