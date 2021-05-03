#include <iostream>
#include <vector>

using namespace std;

enum DIRECTIONS{
    DOWN=0,
    LEFT_DOWN,
    LEFT_UP,
    UP,
    RIGHT_UP,
    RIGHT_DOWN
};

#define SIZE 100000

int main(){
    vector<vector<int> > dirs{{0, 1}, {-1, 1}, {-1, 0},
                              {0, -1}, {1, -1}, {1, 0}};
    vector<vector<int> > pos(SIZE+1, {0, 0});
    int i = 1;
    for(int area = 0; i<SIZE; area++){
        // down
        for(int t=0; t<=area && i<SIZE; t++, i++)
            pos[i+1] = {pos[i][0]+dirs[DOWN][0], pos[i][1]+dirs[DOWN][1]};
        // left-down, less one times than other directions
        for(int t=0; t<area && i<SIZE; t++, i++)
            pos[i+1] = {pos[i][0]+dirs[LEFT_DOWN][0], pos[i][1]+dirs[LEFT_DOWN][1]};           
        // left-up
        for(int t=0; t<=area && i<SIZE; t++, i++) 
            pos[i+1] = {pos[i][0]+dirs[LEFT_UP][0], pos[i][1]+dirs[LEFT_UP][1]};
        // up
        for(int t=0; t<=area && i<SIZE; t++, i++)
            pos[i+1] = {pos[i][0]+dirs[UP][0], pos[i][1]+dirs[UP][1]};
        // right-up
        for(int t=0; t<=area && i<SIZE; t++, i++)
            pos[i+1] = {pos[i][0]+dirs[RIGHT_UP][0], pos[i][1]+dirs[RIGHT_UP][1]};
        // right-down
        for(int t=0; t<=area && i<SIZE; t++, i++)   
            pos[i+1] = {pos[i][0]+dirs[RIGHT_DOWN][0], pos[i][1]+dirs[RIGHT_DOWN][1]};
    }
    int k;    
    while(cin >> k)
        cout << pos[k][0] << " " << pos[k][1] << endl;
    return 0;
}
