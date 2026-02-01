#include <bits/stdc++.h>
using namespace std;

/*
    This function uses Breadth First Search (BFS)
    to find the minimum number of steps needed
    to reach the bottom-right cell from (0, 0)
*/
int findShortestPath(vector<vector<int>> &grid, int rows, int cols)
{
    // Stores distance of each cell from the start
    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    queue<pair<int, int>> q;

    // Start from the top-left corner
    q.push({0, 0});
    distance[0][0] = 0;

    // Direction arrays for up, down, left, right movement
    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;

        // If destination is reached, return distance
        if (r == rows - 1 && c == cols - 1)
            return distance[r][c];

        // Explore neighboring cells
        for (int i = 0; i < 4; i++)
        {
            int newRow = r + rowDir[i];
            int newCol = c + colDir[i];

            // Check boundaries and validity
            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols &&
                grid[newRow][newCol] == 0 &&
                distance[newRow][newCol] == -1)
            {
                distance[newRow][newCol] = distance[r][c] + 1;
                q.push({newRow, newCol});
            }
        }
    }

    // Return -1 if no path exists
    return -1;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;   // Input grid size

    vector<vector<int>> grid(rows, vector<int>(cols));

    // Input grid values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = findShortestPath(grid, rows, cols);

    cout << "Minimum steps: " << result << endl;

}
