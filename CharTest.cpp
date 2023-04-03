#include "CharTest.h"

#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

char* CharTest::_strupr(char* src)
{
	char* s = src;
	while (*s != '\0')
	{
		if (*s >= 'a' && *s <= 'z')
		{
			*s -= 32;
		}
		s++;
	};
	cout << endl << src << std::endl;
	return src;
}

int CharTest::StrCmpLogicalW_Imitate(char* csText1, char* csText2)
{
    //static CRegexp reg(MATCH_NUMBERS);
    //int nEnd1 = 0, nEnd2 = 0;

    //while (1)
    //{
    //    MatchResult ret1 = reg.Match(csText1, nEnd1);
    //    MatchResult ret2 = reg.Match(csText2, nEnd2); 

    //    CString const& csSubText1 = ret1.IsMatched() ? csText1.Mid(nEnd1, ret1.GetStart() - nEnd1) : csText1;
    //    CString const& csSubText2 = ret2.IsMatched() ? csText2.Mid(nEnd2, ret2.GetStart() - nEnd2) : csText2;

    //    //子串不同，则返回
    //    if (csSubText1 != csSubText2)
    //        return csSubText1 > csSubText2 ? 1 : -1;

    //    /*
    //        既然两个字符串相等, 而两个字符串又已经消耗完, 那自然可以返回了.
    //    */
    //    if (!ret1.IsMatched() && !ret2.IsMatched()) return 0;

    //    if (ret1.IsMatched() && ret2.IsMatched())
    //    {//字符串还未消耗完毕,继续按逻辑比较
    //        /*
    //            GetGroupStart() 返回正则表达式中"(//.//d+)" 这一个组的起始位置. 如果没有匹配, 则返回-1; (可查看deelx 的说明文档)
    //            这个组是否匹配意味着捕获的数字是否带有小数点以及小数部分.
    //            如果捕获的两个数字有一个带有小数部分. 则按浮点数处理. 否则按整数处理
    //        */
    //        if (ret1.GetGroupStart(1) >= 0 || ret2.GetGroupStart(1) >= 0)
    //        {//带小数点，按浮点数比较数值大小
    //            double dNum1 = _tcstod(csText1.Mid(ret1.GetStart(), ret1.GetEnd() - ret1.GetStart()), 0);
    //            double dNum2 = _tcstod(csText2.Mid(ret2.GetStart(), ret2.GetEnd() - ret2.GetStart()), 0);
    //            if (dNum1 != dNum2) return dNum1 > dNum2 ? 1 : -1;
    //        }
    //        else
    //        {//按整数处理，比较两个数的数值大小
    //            __int64 nNum1 = _ttoi64(csText1.Mid(ret1.GetStart(), ret1.GetEnd() - ret1.GetStart()));
    //            __int64 nNum2 = _ttoi64(csText2.zMid(ret2.GetStart(), ret2.GetEnd() - ret2.GetStart()));
    //            if (nNum1 != nNum2) return nNum1 > nNum2 ? 1 : -1;
    //        }

    //        nEnd1 = ret1.GetEnd();
    //        nEnd2 = ret2.GetEnd();
    //    }
    //    else
    //    {//现在两个里面肯定有且只有一个IsMatch() 不为真
    //        return ret1.IsMatched() ? 1 : -1;
    //    }
    //}
    return 0;
}

void CharTest::removeFilterSemicolon(string& str)
{
    int flag = false;
    for (char& ch : str)
    {
        if (ch == '(')
            flag = true;

        if (ch == ')')
            flag = true;
        if (ch == ';' && flag)
        {
            ch = ' ';
        }
    }
}

string CharTest::reverseLeftWords(string s, int n)
{
    ///方法一: 模拟思路处理方式
    int len = s.size();
	n = (n % len);
    
    string ss(s.begin(), s.begin() +  n);
    cout << ss << endl;
    int slow = 0, fast = n;
    while (fast < len)
    {
        s[slow++] = s[fast++];
    }
    int index = 0;
	while (slow < len)
	{
        s[slow++] = ss[index++];
	}
    return s;
    ///一些思考：采用循环的方式，能够利用取余处理； 双指针实现同步移动问题；局部变量暂时缓存的方式。
}
void getNext(const string& s, vector<int>& next)
{
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); i++)
    {
	    
    }
}

int CharTest::strStr(string haystack, string needle)
{
    if (needle.size() == 0) return -1;
    vector<int> next(needle.size(), 0);
    getNext(needle, next);
}
