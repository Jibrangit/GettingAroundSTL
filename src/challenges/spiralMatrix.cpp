#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
using namespace std;

struct neighbors {bool left{true}, right{true}, up{true}, down{true}; };

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    void padGrid(int width, int height);
    friend ostream& operator<<(ostream& os, const Solution& sol);
    void updateIndex();

private:
    vector<vector<bool>> paddedGrid;
    std::pair<int, int> gridIndex;
    neighbors Neighbors;
    void updateNeighbors(int i, int j);

};

// Updates Index to the next element in the grid based on its neighbors.
void Solution::updateIndex()
{
    if(!Neighbors.left)
        if(Neighbors.right && !Neighbors.up)
            ++gridIndex.second;
    if(!Neighbors.right)
        if(Neighbors.down && !Neighbors.up)
            ++gridIndex.first;
    if(!Neighbors.right)
        if(Neighbors.left && !(Neighbors.down))
            --gridIndex.second;
    if(!Neighbors.left)
        if(Neighbors.up && !Neighbors.down)
            --gridIndex.first;
    // cout << "GridIndex : (" <<gridIndex.first << ", " << gridIndex.second << ")" << endl; 

}

// Retrieves its neighbors data and stores them in a struct, which is used to update index.
void Solution::updateNeighbors(int i, int j)
{
    Neighbors.right = (paddedGrid[i][j+1]) ? true : false;      
    Neighbors.left = (paddedGrid[i][j-1]) ? true : false;      
    Neighbors.down = (paddedGrid[i+1][j]) ? true : false;      
    Neighbors.up = (paddedGrid[i-1][j]) ? true : false;
    // cout << Neighbors.left << " " << Neighbors.up << " " << Neighbors.right << " " << Neighbors.down << endl;      
}

// Helper function to print elements of the padded grid [DEBUGGING]
ostream& operator<<(ostream& os, const Solution& sol)
{
    for(int i=0; i<sol.paddedGrid.size(); i++)
    {
        for(int j=0; j < sol.paddedGrid[0].size(); j++)
        {
            if(sol.paddedGrid[i][j])
                os << 0 << " ";
            else   
                os << 1 << " ";
        }
        os << "\n";
    }
    return os;
}

// Has the while loop that goes to all elements in the padded grid and pushes the numbers located there to the solution
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix)
{
    const int xSize = matrix[0].size();    // Horizontal length of matrix
    const int ySize = matrix.size();       // Vertical length of matrix
    vector<int> sol;                       // Solution stored here

    padGrid(xSize, ySize);                 // Create a padded grid from the matrix
   

    gridIndex.first = 1;                   // Initial indices
    gridIndex.second = 1;

    sol.push_back(matrix[gridIndex.first - 1][gridIndex.second - 1]);

    updateNeighbors(gridIndex.first, gridIndex.second);
    paddedGrid[gridIndex.first][gridIndex.second] = false;
    updateIndex();

    while(Neighbors.up || Neighbors.left || Neighbors.right || Neighbors.down)
    {
        sol.push_back(matrix[gridIndex.first - 1][gridIndex.second - 1]); 
        updateNeighbors(gridIndex.first, gridIndex.second);
        paddedGrid[gridIndex.first][gridIndex.second] = false;
        updateIndex();
    }

    return sol;
}

// Creates the padded grid from the input matrix which will be used to execute the spital-motion
void Solution::padGrid(int width, int height)
{
    vector<bool> padRow(width + 2, true);
    vector<bool> filledRow(width + 2, false);
    padRow.front() = false;
    padRow.back() = false;

    paddedGrid.emplace_back(filledRow);
    for(int i=0; i < height; i++)
        paddedGrid.emplace_back(padRow);
    paddedGrid.emplace_back(filledRow);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> spiral;
    vector<int> v;
    
    v.insert(v.end(), {1, 2, 3});
    spiral.push_back(v);
    
    v.clear();
    v.insert(v.end(), {4, 5, 6});
    spiral.push_back(v);

    v.clear();
    v.insert(v.end(), {7, 8, 9});
    spiral.push_back(v);
    v.clear();


    Solution sol;
    v = sol.spiralOrder(spiral);
    for(int i{}; i < v.size(); i++)
        cout << v.at(i) << " ";


    // std::cout << spiral.size() << "," << spiral[0].size() << std::endl;
    return 0;
}
