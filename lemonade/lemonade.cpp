#include <iostream>
#include <fstream>
#include <algorithm>

#define ll long long
using namespace std;

int N;
int answer = 0;
int in_line = 0;

bool cmp(ll a, ll b){
  return a > b;
}


int main(){

  ifstream fin("lemonade.in");
  ofstream fout("lemonade.out");

  fin >> N;
  ll nums[N];

  for(long long i=0; i<N; i++){
    fin >> nums[i];
  }

  sort(nums, nums+N, cmp);

  for(int i=0; i<N; i++){

    //Variable to find the last cow for the test
    int last_num = N - answer - 1;

    if (nums[last_num] < in_line){
      answer++;
    }

    if (nums[last_num] >= in_line){
      in_line++;
    }
  }

  fout << in_line << endl;
  return 0;
}
