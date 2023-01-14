#pragma once
#include <vector>
#include <iostream>
using namespace std;

class arrayTest
{
public:
    void test_arr();
    int search(vector<int>& nums, int target);
    int removeElement(vector<int>& nums, int val);
    vector<int> sortedSquares(vector<int>& nums);
    int minSubArrayLen(int target, vector<int>& nums);
    vector<vector<int>> generateMatrix(int n);
    void practice();
};

