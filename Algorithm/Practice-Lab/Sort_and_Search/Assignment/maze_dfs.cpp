#include <bits/stdc++.h>
using namespace std;

size of a connected empty region int exploreRegion(int row, int col,
                                                   vector<vector<int>> &grid,
                                                   vector<vector<bool>> &visited)
{
    int totalRows = grid.size();
    int totalCols = grid[0].size();

    if (row < 0 || col < 0 || row >= totalRows || col >= totalCols)
        return 0;
    if (visited[row][col] || grid[row][col] == 1)
        return 0;

    visited[row][col] = true;
    int area = 1;

    area += exploreRegion(row + 1, col, grid, visited);
    area += exploreRegion(row - 1, col, grid, visited);
    area += exploreRegion(row, col + 1, grid, visited);
    area += exploreRegion(row, col - 1, grid, visited);

    return area;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int regionCount = 0;
    vector<int> regionAreas;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 0 && !visited[i][j])
            {
                regionCount++;
                int currentSize = exploreRegion(i, j, grid, visited);
                regionAreas.push_back(currentSize);
            }
        }
    }

    cout << "Number of regions: " << regionCount << endl;
    cout << "Region sizes: ";

    for (int size : regionAreas)
    {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
