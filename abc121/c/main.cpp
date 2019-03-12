#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Shop{
  public:
    int cost;
    int num;
  Shop(int a, int b){
    cost = a;
    num = b;
  }
  bool operator<(const Shop &another) const
  {
    return cost < another.cost;
  };
};
int main(){
  double N,M,m = 0;
  long long ans = 0;
  cin >> N >> M;
  vector<Shop> shopList;
  int tempA, tempB;
  for(int n=0;n<N;n++){
    cin >> tempA >> tempB;
    shopList.push_back(Shop(tempA, tempB));
  }
  std::sort(shopList.begin(),shopList.end());
  for(int n=0;n<N;n++){
    //cout << shopList[n].cost << " "<<shopList[n].num << endl;
    int buy = shopList[n].num;
    if(m + buy > M){
      buy = M - m;
      ans += buy * (long long)shopList[n].cost;
      break;
    }
    m += buy;
    ans += buy * (long long)shopList[n].cost;
  }
 
  cout << ans << endl;
}