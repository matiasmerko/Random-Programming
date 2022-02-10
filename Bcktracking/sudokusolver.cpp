//SUDOKU BACKTRACKING
#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
#include <cstring>
using namespace std;
typedef long long ll;
typedef long double ld;
void printvec(vector<ll> v);
// Input: 0 0 0 0 9 3 6 5 4 3 0 0 0 8 0 0 0 0 0 0 0 0 6 5 0 1 8 5 0 2 0 0 9 0 0 0 0 0 6 3 0 7 0 0 0
//  4 0 7 0 0 0 9 2 3 6 0 1 0 0 4 0 0 0 2 0 3 9 0 0 0 0 0 7 0 0 0 0 2 0 3 6
#define N 9
void printsudoku(int sudoku[N][N])
{
    for (int i = 0; i < N; i++)
    {
        if(i%3==0){
            cout<<" ----------------------------"<<endl;
        }
        for (int j = 0; j < N; j++)
        {
            if(j%3==0){
                cout<<" | ";
            }
            cout << sudoku[i][j]<<" ";
            if(j==8){
                cout<<" | "; 
            }
        }
        cout << endl;
    }
    cout<<" ----------------------------";
    cout << endl;
}
bool isSafe(int sudoku[][N],int val, int row, int col)
{
    for (int i = 0; i < N; i++)
    {
        if (sudoku[row][i] == val)
        {
            return false;
        }
        if (sudoku[i][col] == val)
        {
            return false;
        }
    }
    int SquareRow = row - row % 3;
    int SquareCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[i + SquareRow][j + SquareCol] == val)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(int sudoku[N][N],int row,int col){
    if(col==N && row==8){return true;}
    if(col==N){
        row++;
        col=0;
    }
    if(sudoku[row][col]>0){
        return solve(sudoku,row,col+1);
    }
    for(int i=1;i<=N;i++){
        if(isSafe(sudoku,i,row,col)){
            sudoku[row][col]=i;
            if(solve(sudoku,row,col+1)){
                return true;
            }
        }
        sudoku[row][col]=0;
    }
    return false;
}
int main()
{
    int sudoku[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    if(solve(sudoku,0, 0)){
        printsudoku(sudoku);
    }
}

void printvec(vector<ll> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
