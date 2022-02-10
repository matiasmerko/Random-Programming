//NQUEENS BACKTRACKING

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
//Size of chess table
#define N 8
void printvec(vector<int>v);
bool isSafe(vector<int>chess[],int row,int col){
    int i,j;
    for(i=0;i<col;i++){
        if(chess[row][i]==1){
            return false;
        }
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(chess[i][j]==1){
            return false;
        }
    }
    for(i=row,j=col;i<N && j>=0;i++,j--){
        if(chess[i][j]==1){
            return false;
        }
    }
    return true;
}
bool solve(vector<int>chess[],int col){
    if(col>=N){return true;}
    for(int i=0;i<N;i++){
        if(isSafe(chess,i,col)){
            chess[i][col]=1;
            if(solve(chess,col+1)){
                return true;
            }
            chess[i][col]=0;
        }
    }
    return false;
}
int main()
{
    vector<int>chess[N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            chess[i].push_back(0);
        }
    }    
    solve(chess,0);
    for(int i=0;i<N;i++){
        printvec(chess[i]);
    }
}

void printvec(vector<int>v){for(unsigned int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;}
