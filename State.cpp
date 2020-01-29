#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <fstream>

using namespace std;

//print the lattice
string print(vector<vector<int > > current_state) {
    string lat;
    for(int x = 0; x < current_state.size(); x++) {
        for(int y = 0; y < current_state[x].size(); y++) {
            lat += to_string(current_state[x][y]);
        }
        lat += '\n';
    }
    ofstream myfile;
    myfile.open("lattice", ios::app);
    myfile << lat << endl;
    myfile.close();

}

int main(){
    //create state for lattice
    vector<vector<int > > state;

    //initial state for lattice 100x100
    state.resize(100);
    for(int i = 0; i < state.size()/2; i++){
        state[i].resize(100);
        fill(state[i].begin(), state[i].end(), 0); //right side 0's
    }
    for(int i = state.size()/2; i < state.size(); i++){
        state[i].resize(100);
        fill(state[i].begin(), state[i].end(), 1); //left side 1's
    }


    //cout << state[3][63] << endl; //testing initial state

    //getting the random numbers for the lattice
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 99);
    uniform_int_distribution<int> neighbors(1, 4);

    //changing the state of the lattice
    for(int sweep = 0; sweep < 10000; sweep++) {
        for(int step = 0; step < 10000; step++){
            int x = dist(mt);
            int y = dist(mt);
            int neighbor = neighbors(mt);
            
            if(neighbor == 1) {
                if(x-1 < 0) {
                    continue;
                }
                else {
                    int t = state[x][y];
                    state[x][y] = state[x-1][y];
                    state[x-1][y] = t;
                }
            }
            
            else if(neighbor == 2) {
                if(x+1 > 99) {
                  continue;
                }
                else {
                    int t = state[x][y];
                    state[x][y] = state[x+1][y];
                    state[x+1][y] = t;
                }
            }

            else if(neighbor == 3) {
                if(y-1 < 0) {
                    continue;
                }
                else {
                    int t = state[x][y];
                    state[x][y] = state[x][y-1];
                    state[x][y-1] = t;
                }
            }

            else if(neighbor == 4){
                if(y+1 > 99) {
                    continue;
                }
                else {
                    int t = state[x][y];
                    state[x][y] = state[x][y+1];
                    state[x][y+1] = t;
                }
            }


        }
        if (sweep % 500 == 0) {
            print(state);
        }
    }
}