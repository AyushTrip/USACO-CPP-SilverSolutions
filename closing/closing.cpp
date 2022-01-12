#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

const int MAXN = 3000;
using namespace std;

//Create main variables
int N, M, a, b, removed;
vector<int> adj[MAXN];
bool visited[MAXN] = {0};
bool is_closed[MAXN] = {0};
int rmv[MAXN];

void clear_arrays(){
  for(int i=0; i<N; i++){
    visited[i] = 0;
  }
}

//BFS Function to determine if the remaining barn is connected
string is_connected(int start){

  bool connected = true;
  clear_arrays();

  //Initialize queue
  queue<int> q;
  visited[start] = true;
  q.push(start);

  //Iterate and BFS Log
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int e: adj[v]){
      if(!visited[e] && !is_closed[e]){
        visited[e] = true;
        q.push(e);
      }
    }
  }

  //Iterate through the visited array
  //MUST satisfy both conditions
  for(int i=0; i<N; i++){
    //If the value hasn't been visited
    if(!visited[i]){

      //If its closed then move on - if NOT mark it
      if(is_closed[i]){
        continue;
      }

      else {
        connected = false;
        break;
      }
    }
  }
  //Final Ouput
  if(connected){return "YES";}
  else{return "NO";}
}


int main(){

  //Read Input
  ifstream fin("closing.in");
  ofstream fout("closing.out");

  fin >> N >> M;
  for(int i=0; i<M; i++){
    fin >> a >> b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int j=0; j<N; j++){
    fin >> rmv[j];
  }

  //Output the first value
  fout << is_connected(0) << endl;

  //Utilize Algorithm
  for(int i=0; i<N; i++){
    //print_stuff();
    removed = rmv[i];
    is_closed[removed-1] = true;
    //Apply function on first real value
    for(int i=0; i<N; i++){
      if(!is_closed[i]){
        fout << is_connected(i) << endl;
        break;
      }
    }
  }


  return 0;
}
