// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=study-plan&id=programming-skills-i
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int numOfOdds = 0;
        if (low%2 == 1) numOfOdds++;
        if (high%2 == 1) numOfOdds++;
        return (high - low + numOfOdds)/2;
    }
};


int main() {

}
