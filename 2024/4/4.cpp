#include <bits/stdc++.h>

std::vector<std::pair<int, int>> dirs = {
    {0, 1},   
    {0, -1}, 
    {1, 0}, 
    {-1, 0},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
};

bool is_xmas(const std::vector<std::string>& grid, int x, int y, int dx, int dy) {
    std::string chars = "XMAS";
    for (int i = 0; i < 4; i++) {
        int rx = x + dx * i;
        int ry = y + dy * i;

        if (ry < 0 || ry >= grid.size() || rx < 0 || rx >= grid[ry].size() || grid[ry][rx] != chars[i]) {
            return false;
        }
    }
    return true;
}

int get_ex1(std::vector<std::string>& grid) {
    int sum = 0;

    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            for (const auto& [dx, dy] : dirs) {
                if (is_xmas(grid, x, y, dx, dy)) {
                    sum++;
                }
            }
        }
    }

    return sum;
}


std::vector<std::vector<std::string>> xmas = {
    {"M", ".", "M"},
    {".", "A", "."},
    {"S", ".", "S"}
};

// Function to clone the XMAS matrix
std::vector<std::vector<std::string>> clone_xmas(std::vector<std::vector<std::string>>& mat) {
    return mat; // This does a shallow copy which is sufficient for the simple grid structure
}

// Function to rotate the matrix 90 degrees clockwise
std::vector<std::vector<std::string>> rotate_matrix(std::vector<std::vector<std::string>>& mat) {
    int size = mat.size();
    std::vector<std::vector<std::string>> rotated(size, std::vector<std::string>(size));

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            rotated[x][size - y - 1] = mat[y][x];
        }
    }
    return rotated;
}

// Function to check if the X-MAS pattern exists starting at (x, y)
bool check(std::vector<std::vector<std::string>>& grid, int x, int y, const std::vector<std::vector<std::string>>& mat) {
    for (int dy = 0; dy < mat.size(); ++dy) {
        for (int dx = 0; dx < mat[dy].size(); ++dx) {
            if (mat[dy][dx] == ".") continue; // Skip empty parts of the pattern
            if (y + dy >= grid.size() || x + dx >= grid[y].size() || grid[y + dy][x + dx] != mat[dy][dx]) {
                return false;
            }
        }
    }
    return true;
}

// Main function to count all X-MAS occurrences
int get_ex2(std::vector<std::string>& input) {
    int sum = 0;
    std::vector<std::vector<std::string>> grid;

    // Convert the input into a 2D grid
    for (const auto& line : input) {
        std::vector<std::string> row;
        for (char c : line) {
            row.push_back(std::string(1, c));
        }
        grid.push_back(row);
    }

    // Check all positions on the grid
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            std::vector<std::vector<std::string>> mat = clone_xmas(xmas);

            // Try all 4 rotations (0, 90, 180, 270 degrees)
            for (int r = 0; r < 4; ++r) {
                if (check(grid, x, y, mat)) {
                    sum++;
                }
                mat = rotate_matrix(mat); // Rotate the pattern for the next check
            }
        }
    }

    return sum;
}
