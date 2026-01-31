#include <bits/stdc++.h>
using namespace std;

/*
    This function performs Depth First Search (DFS)
    to calculate the size of a connected region of 0s
*/
int dfsRegion(int row, int col,
              vector<vector<int>> &grid,
              vector<vector<bool>> &visited)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Boundary and validity check
    if (row < 0 || col < 0 || row >= rows || col >= cols)
        return 0;
    if (visited[row][col] || grid[row][col] == 1)
        return 0;

    // Mark cell as visited
    visited[row][col] = true;
    int regionSize = 1;

    // Visit all four directions
    regionSize += dfsRegion(row + 1, col, grid, visited);
    regionSize += dfsRegion(row - 1, col, grid, visited);
    regionSize += dfsRegion(row, col + 1, grid, visited);
    regionSize += dfsRegion(row, col - 1, grid, visited);

    return regionSize;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;   // Input grid size

    vector<vector<int>> grid(rows, vector<int>(cols));

    // Read grid data (0 = empty, 1 = blocked)
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int totalRegions = 0;
    vector<int> regionSizes;

    // Traverse grid to find connected regions
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 0 && !visited[i][j])
            {
                totalRegions++;
                regionSizes.push_back(dfsRegion(i, j, grid, visited));
            }
        }
    }

    // Output results
    cout << "Number of regions: " << totalRegions << endl;
    cout << "Region sizes: ";

    for (int size : regionSizes)
    {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
