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
	///����˼�룺����hash�ķ�ʽʵ��ȥ�ء�����find�������ٲ��ҡ�
	///����һ������ʽ set��ķ�ʽ
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

	///���������������鴦��
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
	///���ģ�����ѭ����ע���߼��жϡ�������ѭ�����ж�������
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
	///һЩ˼���������жϣ�����һ�����룬һ��bool����жϣ����Բ����ֶ�ģ����Ծ޶��������𽥷��ֹ��ɡ�
}

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
	return a.first <= b.first;
}
vector<int> hashTest::twoSum(vector<int>& nums, int target)
{
	///����һ:ģ�ⷨ  ����+�������+��ǰ�˳��ķ�ʽ��
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
	///һЩ˼���������������÷�������������

	///���汾
	unordered_map<int, int> map;  ///�������浱ǰֵ�����±�Ķ�Ӧ��ϵ��
	for (int i = 0; i < nums.size(); i++)
	{
		if (map.find(target - nums[i]) != map.end())
		{
			return { i, map[nums[i]]};
		}
		else
		{
			map[nums[i]] = i; //��֤��ǰѰ��ֵ���Ǵ����Ѿ��������������С�
		}
	}
	return {};
	///һЩ˼�����������������õļ��ã������Լ���˼ά��������Ϊ�㣻
	///��ǰ�����Ѿ����������±����Ի�ȡ��ǰֵ��Ȼ������һ��map��ֵ�����������±��ֵ�Ķ�Ӧ��ϵ��
	///ÿ�ε�ǰֵ����Ҫ�����Ƿ����ҵ�һ�����ʵ�ֵ���������±ꡣ
}
