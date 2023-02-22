#pragma once
#include <vector>
#include <string> 
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class hashTest
{
public:
	bool isAnagram(string s, string t);
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
	bool isHappy(int n);
	vector<int> twoSum(vector<int>& nums, int target);
};

