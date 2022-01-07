#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


//Create edge structure that will contain the values
struct Edge {
  int x, y, w;

  //Constructor Function
  Edge(int xc, int yc, int weight): x(xc), y(yc), w(weight){}
};


//Create key variables
int N;
vector<Edge> edges;
bool visited[200] = {0}; //create boolean function to keep track of the visited. 200 is the max

//Check if two cows are within range
bool in_range(Edge &a, Edge &b){
  //Overcomplicated Pythag lmfao
  return (a.w*a.w) >= ((abs(b.x - a.x)*abs(b.x - a.x)) + (abs(b.y - a.y)*abs(b.y - a.y)));
}

//Create a DFS function -- will RETURN a modified VISITED array
//Parameter is in the form of the INDEX of the cow
void dfs(int cow, int arr){
  visited[cow] = true;
  for(int i=0; i<arr; i++){
    if((!visited[i]) && (in_range(edges[cow], edges[i]))){
      dfs(i, arr);
      //cout << edges[i].x << " " << edges[i].y << endl;
    }
  }
}

int trueCheck(int n, bool boolarr[]){
  int count = 0;
  for(int i=0; i<n; i++){
    if(boolarr[i]){count++;}
  }
  return count;
}

//Main function
int main(){

  //Read Input
  ifstream fin("moocast.in");
  ofstream fout("moocast.out");

  fin >> N;

  for(int i=0; i<N; i++){
    int a,b,w;
    fin >> a >> b >> w;
    edges.push_back(Edge(a,b,w));
  }


  //Begin Solve
  int max = -1;
  for(int i=0; i<N; i++){
    fill(begin(visited), end(visited), false);
    dfs(i,N);
    if(trueCheck(N, visited) > max){
      max = trueCheck(N, visited);
    }
  }

  fout << max;

  return 0;
}
