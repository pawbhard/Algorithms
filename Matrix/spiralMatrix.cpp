
#include <bits/stdc++.h>
using namespace std;

enum dir {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

void spiralOrder(vector<vector<int>>& matrix) {
    int r_end = matrix.size()-1;
    int c_end = matrix[0].size()-1;
    int r_start = 1;
    int c_start = 0;
    dir d = RIGHT;
    int i = 0, j =0;
    int tot = (r_end +1)*(c_end+1);
    int cnt = 0;
    while(cnt++ < tot) {
        cout<<matrix[i][j]<<" ";
        if (d == RIGHT) {
            if (j == c_end) {
                d = DOWN;
                c_end--;
                i++;
            } else {
                j++;
            }
        } else if ( d == DOWN) {
            if (i == r_end) {
                d = LEFT;
                r_end--;
                j--;
            } else {
                i++;
            }
        } else if (d == LEFT) {
            if (j == c_start) {
                d = UP;
                c_start++;
                i--;
            } else {
                j--;
            }
        } else if (d == UP) {
            if (i == r_start) {
                d = RIGHT;
                r_start++;
                j++;
            } else {
                i--;
            }
        }
    }
}

int main() {
    vector<vector<int>> num {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
    spiralOrder(num);
    cout<<endl;
    return 0;
}