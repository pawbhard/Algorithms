//https://leetcode.com/problems/best-sightseeing-pair/

/*
You are given an integer array values where values[i] represents the
value of the ith sightseeing spot. Two sightseeing spots i and j have
 a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is 
values[i] + values[j] + i - j: the sum of the values 
of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.
*/

#include <bits/stdc++.h>
using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    size_t sz = values.size();
    vector<int> endgain(sz, 0);
    endgain[sz-1] = values[sz-1] - (sz-1);
    for(int i = sz-2; i >= 0; i--) {
        endgain[i] = max(values[i] - i, endgain[i+1]);
    }

    int max_gain = INT_MIN;
    for(int i = 0; i < sz; i++) {
        max_gain = max(max_gain, values[i]+i + endgain[i+1]);
    }

    //combined loop
    for(int i = sz-2; i>=0; i++) {
        endgain[i] = max(values[i] - i, endgain[i+1]);
        max_gain = max(max_gain, values[i]+i + endgain[i+1]);
    }
    return max_gain;
}