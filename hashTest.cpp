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
	vector<int> ans;
	return {};
}
