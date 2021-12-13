#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int calcular(vector<vector<int>>& grid, int i, int j){
    if (i == grid.size() || j == grid[0].size()){
        return INT_MAX;
    }
    if (i == grid.size() - 1 && j == grid[0].size() - 1){
        return grid[i][j];
    }
    return grid[i][j] +
    min(calcular(grid, i + 1, j), calcular(grid, i, j + 1));
}

int minPathSum(vector<vector<int>>& grid){
    return calcular(grid, 0, 0);
}

int main(){
    vector<vector<int>> x = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(x)<<endl;
    return 0;
}
