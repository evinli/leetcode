#include <iostream>
#include <vector>
#include<iterator>
#include <string>
#include<queue>
#include <map>

using namespace std;
int numIslands(vector<vector<char>> &grid);
void dfs(vector<vector<char>> &grid, int row, int col);

// Alternative problem: "Counting # of connected components in an undirected graph"
int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            if (grid[row][col] == '1') {
                dfs(grid, row, col);
                count++;
            }
        }
    }
    return count;
}

void dfs(vector<vector<char>> &grid, int row, int col) {
    // Base case
    if (row < 0 || row == grid.size() || col < 0 || col == grid[0].size() || grid[row][col] == '0') {
        return;
    }

    // Mark each node of island as visited to avoid double counting
    grid[row][col] = '0';

    // Recursive step
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
}

// Driver code
int main() {
    vector<char> vect = {'1', '1', '0', '1'};
    vector<char> vect1 = {'0', '0', '0', '1'};

    vector<vector<char>> island;
    island.push_back(vect);
    island.push_back(vect1);

    cout << "Number of islands is: " << numIslands(island);
    return 0;
}
