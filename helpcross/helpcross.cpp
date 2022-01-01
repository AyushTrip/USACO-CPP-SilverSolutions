/*My solution was a bit different from the editorial. Instead of sorting by the last value in each cow-pair 
(which was probably easier lol), I sorted each cow range by the amount of flexability they have (i.e given a
pair of [a,b], the vector was sorted based on the absolute difference between both integers). */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//Define initial variables

/*
N - number of cows
C - number of chickens
tc - time that chicken available
aj - first value in cow range
bj - second value in cow range
*/

int N, C, tc, aj, bj;
int ans = 0;

//In this instance chickens and cows refers to the time they are available
vector<int> chicken_times;
vector<pair<int, int>> cow_ranges;

//Create a sort function for the cow ranges j
bool cow_sort(const pair<int, int> &a, const pair<int, int> &b){

  //Three if-statements, each one for sorting the vector by distance between the pairs
  if(abs(a.second-a.first) < abs(b.first-b.second)){
    return true;
  }

  else if(abs(a.second-a.first) > abs(b.first-b.second)){
    return false;
  }

  //This line is in case the pair distances are equal and I need to sort it by the end point.
  else {
    return (a.second < b.second);
  }

}

//Main function for solving
int main(){

  //Read Input
  ifstream fin("helpcross.in");
  ofstream fout("helpcross.out");

  fin >> C >> N;

  //Read the times that the chickens are available
  for(int i=0; i<C; i++){
    fin >> tc;
    chicken_times.insert(lower_bound(chicken_times.begin(), chicken_times.end(), tc), tc);
  }

  //Read the ranges that the cows are available
 for(int i=0; i<N; i++){
   fin >> aj >> bj;
   cow_ranges.push_back(make_pair(aj, bj));
 }

 //Sort the cow ranges
 sort(cow_ranges.begin(), cow_ranges.end(), cow_sort);

 //Sorting algorithm - full double loop
 for(int i=0; i<N; i++){
   for(int j=0; j<chicken_times.size(); j++){

     //If statement conditions
     if((cow_ranges[i].first <= chicken_times[j]) && (chicken_times[j] <= cow_ranges[i].second)){
       ans++;
       chicken_times.erase(chicken_times.begin()+j);
       break;
     }

     else if(chicken_times[j] > cow_ranges[i].second){
      break;
     }
   }
 }

 fout << ans << endl;

 return 0;
}
