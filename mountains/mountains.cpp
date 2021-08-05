#include <iostream>
#include <algorithm>
#include <fstream>
#define MAXN 100000


using namespace std;
int N;
int X[MAXN], Y[MAXN];
int pos[MAXN], neg[MAXN];
int cid[MAXN];

//Sorting Function
bool cmp(int a, int b){
  if (neg[a] == neg[b]){
    return pos[a] > pos[b];
  }
  return neg[a] < neg[b];
}

int main(){

  //Read Input

  ifstream fin("mountains.in");
  ofstream fout("mountains.out");

  fin >> N;

  for(int i=0; i<N; i++){
    fin >> X[i] >> Y[i];
    neg[i] = X[i] - Y[i];
    pos[i] = X[i] + Y[i];
    cid[i] = i;
  }

  int answer = 0;
  sort(cid, cid+N, cmp);
  int pmax = -1;

  for(int i=0; i<N; i++){
    if(pos[cid[i]] > pmax){
      answer++;
      pmax = pos[cid[i]];
    }
  }

  fout << answer;


  return 0;
}
