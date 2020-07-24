//
// Created by tao hu on 2020/7/11.
//
#include <set>
using namespace std;
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    set<int> unvisited,visited;
    int n=rooms.size();
    for(int i=0;i<n;i++)
      unvisited.insert(i);
    unvisited.erase(0);
    visited.insert(0);
    for(auto room:rooms){
      for(auto)
    }
};

int main(){
  Solution obj;
  vector<vector<int>> rooms={{1},{2},{3},{}}};
  obj.canVisitAllRooms(rooms);
}