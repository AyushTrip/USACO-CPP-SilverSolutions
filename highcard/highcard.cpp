#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
const int MAXN = 50000;
int current_index = 0;
int bessie_index = 0;
int answer = 0;
int best_card = -1;

int elsie[MAXN];
int bessie[MAXN];


int main() {

  ifstream fin("highcard.in");
  ofstream fout("highcard.out");

  fin >> N;

  //Iterate and read all of elsie's cards
  for (int i=0; i<N; i++){
    fin >> elsie[i];
  }

  sort(elsie, elsie+N);

  //Determine all of the cards Bessie has
  for (int i=1; i<2*N+1; i++){

    //If it's elsies card, move on
    if (i == elsie[current_index]){
      current_index++;
    }

    //If it's bessies card, add it to her array
    else {
      bessie[bessie_index] = i;
      bessie_index++;
    }
  }


  //implement algorithm
  int bessie_ix = 0;
  int elsie_ix = 0;

  while(bessie_ix < N && elsie_ix < N){

    if (bessie[bessie_ix] > elsie[elsie_ix]){
      answer++;
      bessie_ix++;
      elsie_ix++;
    }

    else{
      bessie_ix++;
    }
  }

  fout << answer;

  return 0;
}
