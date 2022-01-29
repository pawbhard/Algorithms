#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_set>

uint32_t reverseBits(uint32_t n) {
    uint32_t res{0};
    for (int i = 0; i < 32; i++) {
        if (n & 1<<i) {
            res |= 1<<(31-i);
        }
    }
    return res;
}