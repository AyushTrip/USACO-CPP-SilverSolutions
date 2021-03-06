#include <fstream>
#include <iostream>
#include <vector>

using namespace std; 

const int MAXN = 5000; 

//Create main variables 
int N, Q, pi, qi, ri, k, v;
vector<pair<int, int>> adj[MAXN]; 
pair<int, int> questions[MAXN];
bool visited[5000] = {0};


void dfs(int idx, int r){
  visited[idx] = true;
  for(pair<int, int> &video: adj[idx]){
    if((!visited[video.first]) && (video.second >= r)){
      dfs(video.first, r); 
    }  
  }
}

int count_true(){
  int countr = 0; 
  for(int i=0; i<N; i++){
    if(visited[i]){countr++;}
  }
  return countr - 1; 
}

int main(){

  ifstream fin("mootube.in");
  ofstream fout("mootube.out");

  //Read Input 
  fin >> N >> Q;
  for(int i=0; i<N-1; i++){
    fin >> pi >> qi >> ri;
    pi--;qi--;
    adj[pi].push_back(make_pair(qi, ri));
    adj[qi].push_back(make_pair(pi, ri));
  }

  for(int j=0; j<Q; j++){
    fin >> questions[j].first >> questions[j].second;
  }

  //Implement DFS
  for(int i=0; i<Q; i++){
    //Reset the array
    for(int i=0; i<N; i++){
      visited[i] = false; 
    }
    dfs(questions[i].second-1, questions[i].first);
    fout << count_true() << endl;
  }
  return 0; 
}
