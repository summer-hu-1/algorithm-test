#include "hashTest.h"

bool hashTest::isAnagram(string s, string t)
{
	/// 方法一：哈希表处理方式
	/*if (s.size() != t.size())
		return false;
	vector<int> judge(26, 0);
	for (char str : s)
		judge[str - 'a']++;
	for (char str : t)
	{
		if (--judge[str - 'a'] < 0)
		{
			return false;
		}
		
	}
	return true;*/
	///一些思考：所有字母均可映射到26个字母表中，运用出入栈的思维，及时判断，一旦溢出则出错。
	///字母和下表一一对应，可以处理的更加高效。以空间换时间。  ///数组  -- vector可以处理几乎所有的数组问题。

	///方法二：思路清晰简洁版
	int record[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
		record[s[i] - 'a']++;
	for (int i = 0; i < t.size(); i++)
		record[t[i] - 'a']--;
	for (int i = 0; i < 26; i++)
	{
		if (record[i] != 0) return false;
	}
	return true;
}

vector<int> hashTest::intersection(vector<int>& nums1, vector<int>& nums2)
{
	///核心思想：采用hash的方式实现去重。利用find函数快速查找。
	///方法一：处理方式 set表的方式
	/*unordered_set<int> ans;
	unordered_set<int> set(nums2.begin(), nums2.end());

	for (auto val : nums1)
	{
		if (set.find(val) != set.end())
		{
			ans.emplace(val);
		}
	}
	
	return vector<int>(ans.begin(), ans.end());*/

	///方法二：利用数组处理
	//unordered_set<int> set(nums1.begin(), nums1.end());
	vector<int> hash(1001, 0);

	for (int val : nums1)
		hash[val] = 1;
	unordered_set<int> ans;
	for (int val : nums2)
	{
		if (hash[val])
		{
			ans.insert(val);
		}
	}
	return vector<int>(ans.begin(), ans.end());
}

bool hashTest::isHappy(int n)
{
	///核心：无限循环、注意逻辑判断、巧用死循环的判定条件。
	unordered_set<int> hash;
	while (true) {
		if (n == 1) return true;
		else if (hash.find(n) != hash.end()) {
			return false;
		}
		else {
			hash.insert(n);
			int sum = 0;
			while (n) {
				sum += (n % 10) * (n % 10);
				n /= 10;
			}
			n = sum;
		}
	}
	///一些思考：总体判断，就是一个输入，一个bool结果判断，可以采用手动模拟测试巨多样例，逐渐发现规律。
}

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
	return a.first <= b.first;
}
vector<int> hashTest::twoSum(vector<int>& nums, int target)
{
	///方法一:模拟法  排序+逐层搜索+提前退出的方式。
	/*vector<pair<int, int>> vec;
	for (int i = 0; i < nums.size(); i++)
	{
		vec.push_back({nums[i], i});
	}
	sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int>b)
	{
			return a.first <= b.first;
	});

	for (int i = 0; i < nums.size(); i++)
	{
		int temp = target - vec[i].first;
		for (int j = i + 1; j < nums.size(); )
		{
			cout << "vec[i].first:" << vec[i].first << " vec[j].first:" << vec[j].first << endl;
			if (vec[j].first < temp)
			{
				j++;
			}
			else if (vec[j].first > temp)
			{
				break;
			}
			else
			{
				return { vec[i].second, vec[j].second };
			}
		}
	}
	return { 0, 0 };*/
	///一些思考：匿名函数的用法更加清晰明了

	///简洁版本
	unordered_map<int, int> map;  ///用来保存当前值及其下表的对应关系。
	for (int i = 0; i < nums.size(); i++)
	{
		if (map.find(target - nums[i]) != map.end())
		{
			return { i, map[nums[i]]};
		}
		else
		{
			map[nums[i]] = i; //保证当前寻找值都是处于已经遍历过的样例中。
		}
	}
	return {};
	///一些思考：有人三方库是用的极好，但是自己的思维能力几乎为零；
	///当前考虑已经遍历过的下表，可以获取当前值，然后利用一个map键值对用来保存下标和值的对应关系。
	///每次当前值就需要考虑是否能找到一个合适的值，返回其下标。
}
