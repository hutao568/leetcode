//
// Created by tao hu on 2020/8/11.
//
#include <vector>
using namespace  std;

class Solution {
 public:
  void dfs(vector<vector<char>>& board,vector<vector<int>>& flag,int x,int y){
    vector<int> Next={-1,0,1,0,-1};
    flag[x][y]=1;
    for(int i=0;i<4;i++){
      int x_=x+Next[i];
      int y_=y+Next[i+1];
      if(x_>=0&&y>=0&&x_<board.size()&&y_<board[0].size()&&board[x_][y_]=='O'&&flag[x_][y_]==0){
        dfs(board,flag,x_,y_);
      }
    }
  }
  void solve(vector<vector<char>>& board) {
    //遍历边界，遇到O就开始深搜，将这些标记为1
    //遍历board，遇到O且标记为0的点，则将当前点改为X
    int n=board.size();
    if(n==0)
      return ;
    int m=board[0].size();
    if(m==0)
      return ;
    vector<vector<int>> flag(n,vector<int>(m,0));
    for(int i=0;i<board.size();i++){
      if(board[i][0]=='O'){
        dfs(board,flag,i,0);
      }
      if(board[i][m-1]=='O'){
        dfs(board,flag,i,m-1);
      }
    }

    for(int j=0;j<m;j++){
      if(board[0][j]=='O'){
        dfs(board,flag,0,j);
      }
      if(board[n-1][j]=='O'){
        dfs(board,flag,n-1,j);
      }
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(board[i][j]=='O'&&flag[i][j]==0){
          board[i][j]='X';
        }
      }
    }
  }
};