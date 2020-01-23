#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main(){
    //create state for lattice
    vector<vector<int > > state;

    //initial state for lattice 100x100
    state.resize(100);
    for(int i = 0; i < state.size()/2; i++){
        state[i].resize(100);
        fill(state[i].begin(), state[i].end(), 0); //right side 0's
    }
    for(int i = state.size()/2 + 1; i < state.size(); i++){
        state[i].resize(100);
        fill(state[i].begin(), state[i].end(), 1); //left side 1's
    }


    cout << state[3][63] << endl; //testing initial state
}