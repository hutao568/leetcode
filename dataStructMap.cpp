//
// Created by tao hu on 2020/7/17.
//

#include <unordered_map>
#include <iostream>
using namespace std;

int main(){
  unordered_map<string,int> map;
  map.insert({"1",1});
  map.insert(std::make_pair("Scala",1));
  cout<<(map.find("1")==map.end())<<endl;
  cout<<(map.find("2")==map.end())<<endl;

  for(auto it=map.begin();it!=map.end();it++){
    cout<<it->first<<" "<<it->second<<endl;
  }

  return 0;
}