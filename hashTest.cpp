#include "hashTest.h"

bool hashTest::isAnagram(string s, string t)
{
	/// ����һ����ϣ����ʽ
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
	///һЩ˼����������ĸ����ӳ�䵽26����ĸ���У����ó���ջ��˼ά����ʱ�жϣ�һ����������
	///��ĸ���±�һһ��Ӧ�����Դ���ĸ��Ӹ�Ч���Կռ任ʱ�䡣  ///����  -- vector���Դ��������е��������⡣

	///��������˼·��������
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
