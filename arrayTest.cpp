#include "arrayTest.h"

#include <algorithm>

void arrayTest::test_arr(){
    int array[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << &array[0][0] << &array[0][1] << &array[0][2] << endl;
    cout << &array[1][0] << &array[1][1] << &array[1][2] << endl;
}

int arrayTest::search(vector<int>& nums, int target)
{
    //���ַ� ����˼·��1.�������ұ߽����䣬2.�����м�ֵ��С���䣬3ѭ���ж������������м�ֵ�ж��Ƿ���ȡ�

    ///����һ������ұ�
    /*int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }*/

    ///������������ҿ�
    /*int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2; 
        if (target > nums[mid]) left = mid + 1;
        else if (target < nums[mid]) right = mid;
        else return mid;
    }
    return -1;*/
    ///һЩ˼����ֻ��Ҫ������α����������ʼ��Ϊ��������
    ///���磺�м�ֵ�жϲ���Ŀ��ֵ����ߺ��ұ�ȡֵ�Ƿ�Ϊʵ�ľͱ���С���������

    ///������:���汾 
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target < nums[mid]) right = mid - 1;
        else if (target > nums[mid]) left = mid + 1;
        else return mid;
    }
    return -1;
    ///һЩ˼�������Ҳ�����ͬ�����䣬ʵ�ĵ㡣
    ///1.�������ʱ���� 2.��������仯���ƶ�����Ҫʵ�ʵ㡣
}

int arrayTest::removeElement(vector<int>& nums, int val)
{
    ///˫ָ�뷨-����˼·��1.ȷ������ָ����˶�����  2.ȷ������֮��ǰ���Ĺ�ϵ��

    ///����һ������ָ�뷨
    int slow = 0, fast = 0;
    while (fast < nums.size())
    {
	    if (nums[fast] != val)
	    {
            nums[slow++] = nums[fast++];
	    }
        else
        {
            fast++;
        }
    }
    return slow;

    ///������������ָ�뷨
    size_t leftIndex = 0, rightIndex = nums.size() - 1;
    while (leftIndex <= rightIndex)
    {
        while (leftIndex <= rightIndex && nums[leftIndex] != val) leftIndex++;
        while (leftIndex <= rightIndex && nums[rightIndex] == val) rightIndex--;
        if (leftIndex < rightIndex) swap(nums[leftIndex++], nums[rightIndex--]);
    }
    return leftIndex;
    ///һЩ˼��������ѭ���ҵ���ߵ�һ���滻Ԫ��(������val)���ұߵ�һ�����滻Ԫ�أ�����val),
    ///�ҵ�һ�Ժ�Ϳ�ʼ�滻��ֱ�����滻����ȫ��������ϡ�
    ///����leftIndex��Ȼ�����滻�������һ��Ԫ�ء�������ͻ����ڴ���������,ÿ������1�����Ա�Ȼ����ֱ���¼ң�

    ///���汾��
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (nums[fastIndex] != val)
            nums[slowIndex++] = nums[fastIndex];
    }
    return slowIndex;
    ///һЩ˼�����Կ�ָ��Ϊ�����󣬱�����������Ԫ�أ����δ��������������������ڸ���ֵԪ�أ������б��ݴ�����ʵ����ǰ�ƶ��Ĳ�����
}

vector<int> arrayTest::sortedSquares(vector<int>& nums)
{
    ///˫ָ�뷨��

    ///����һ:ֱ�ӷ�������ֱ��ģ���˼ά�����ɣ�
    /*for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        *it *= *it;
    sort(nums.begin(), nums.end());
    return nums;*/

    ///������������˫ָ�뷨
   /* for (int i = 0; i < nums.size(); i++)
        nums[i] *= nums[i];

    vector<int> temp(nums.size());
    int cur = nums.size() - 1;
    int leftIndex = 0, rightIndex = nums.size() - 1;
    while (leftIndex <= rightIndex)
    {
	    if (nums[leftIndex] >= nums[rightIndex])
	    {
            temp[cur--] = nums[leftIndex++];
	    }
        else
        {
            temp[cur--] = nums[rightIndex--];
        }
    }
    return temp;*/
    ///һЩ˼���������Ǵ��������ˣ������������С������

    ///���汾��
    int len = nums.size();
    vector<int>temp(len);
    for (int left = 0, right = len - 1, cur = len - 1; left <= right; )
    {
        temp[cur--] = (nums[left] * nums[left] >= nums[right] * nums[right]) ? nums[left] * nums[left++] : nums[right] * nums[right--];
    }
    return temp;
    /// һЩ˼����ʲô�м�࣬Ӧ�����߼�����������ǡ���ô���
}

int arrayTest::minSubArrayLen(int target, vector<int>& nums)
{
    ///����˼·���������ڷ�������ν�������ڣ����ǲ��ϵĵ��������е���ʼλ�ú���ֹλ�ã��Ӷ��ó�����Ҫ��Ľ����
    
    ///����һ���������ڷ�������
    int cur = INT_MAX, sum = 0;   ///bug one: cur�ĵ�ǰֵ����ǡ����Ҫ����Ϊ���ֵ���ܷ��ؼȶ�ֵ��С��
    for (int slow = 0, fast = 0; fast < nums.size(); )
    {
        sum += nums[fast++];
	    while (sum >= target && slow <= fast)
	    {
            cur = min(fast - slow, cur); ///fast����ָ�򴰿ڵ���һ����
            sum -= nums[slow++];
	    }
    }
    return cur == 0x7fffffff ? 0 : cur;
    ///һЩ˼����1.���ִ��ڳ���һ��λ��ǰ����  2.ÿ��ͳ�ƴ���ֵ�ܺ�  3.��ǰ�����ܺʹ���Ŀ��ֵʱ�����µ�ǰ��С��������������ǰ��
    ///���ֵ �� 0x�߸�f.
}

vector<vector<int>> arrayTest::generateMatrix(int n)
{
    ///ģ�ⷨ������˼�룺ȷ�������ƶ�����������ִ���У���ģ������·�����ɡ�

    ///����һ������ұ� �±�ͳһ  �������������֣�һ��һ�иɵ���һ��ѭ����������ʱ���봦������һ����Ƽ��ɡ�
    /*vector<vector<int>> vec(n, vector<int>(n));
    int left = 0, right = n - 1, up = 0, buttom = n - 1;
    int i = 0, j = 0;
    for (int k = 1; k <= n * n; ) TODO The best version.
    {
        for (j = left; j <= right; j++)
            vec[i][j] = k++;
        j--, up++;
        for (i = up; i <= buttom; i++)
            vec[i][j] = k++;
        i--, right--;
        for (j = right; j >= left; j--)
            vec[i][j] = k++;
        j++, buttom--;
        for (i = buttom; i >= up; i--)
            vec[i][j] = k++;
        i++, left++;
    }
    return vec;*/
    ///һЩ˼������֪����ζ��ʿ�ʼ�ж������鷳�ġ�
    ///1.����������Ҫ�仯�������ܹ�1~n*n,һ��ѭ�����Կ��ơ�
    ///2.���������ĸ�����һ��һ��������
    ///
    ///bug:���׳����������У���һ�еĴ���λ��Խ�磬�������Ʊ���Ҫͬʱ���ơ�

    ///������������ҿ�   TODO
    vector<vector<int>> nums(n, vector<int>(n, 0));
    int i = 0, j = 0;
    int left = 0, right = n - 1, up = 0, buttom = n - 1;
    for (int k = 1; k <= n * n; )
    {
        for (j = left; j < right; j++)
            nums[i][j] = k++;
        for (i = up++; i < buttom; i++)
            nums[i][j] = k++;
        for (j = right--; j > left; j--)
            nums[i][j] = k++;
        for (i = buttom--; i > up; i--)
            nums[i][j] = k++;
        left++;
    }
    return nums;


    ///���棺�±���ʱ���������ҿ����±ꡣ����ұ�
   /* vector<vector<int>> ans(n, vector<int>(n, 0));
    int index = 1;
    int up = 0, down = n - 1, left = 0, right = n - 1;
    while (index <= n * n)
    {
        for (int j = left; j <= right; j++)
            ans[up][j] = index++;
        up++;
        for (int i = up; i <= down; i++)
            ans[i][right] = index++;
        right--;
        for (int j = right; j >= left; j--)
            ans[down][j] = index++;
        down--;
        for (int i = down; i >= up; i--)
            ans[i][left] = index++;
        left++;
    }
    return ans;*/

    ///���԰棺һ��������ƺ����Ӵ�offer��·�ˡ�
    /*vector<vector<int>> ans(n, vector<int>(n, 0));
    int i = 0, j = 0;
    int up = 0, down = n - 1, left = 0, right = n - 1;
    for (int k = 1; k <= n * n; )
    {
        for (j = left; j <= right; j++)
            ans[i][j] = k++;
        j--, up++;
        for (i = up; i <= down; i++)
            ans[i][j] = k++;
        i--, right--;
        for (j = right; j >= left; j--)
            ans[i][j] = k++;
        j++, down--;
        for (i = down; i >= up; i--)
            ans[i][j] = k++;
        i++; left++;
    }
    return ans;*/
}

void arrayTest::practice()
{
    int n = 10;

    vector<vector<int>> ans(n, vector<int>(n, 0));
    int up = 0, down = n - 1, left = 0, right = n - 1;
    int index = 1;
    int i = 0, j = 0;
    while (index <= n * n)
    {
        for (j = left; j <= right; j++)
            ans[i][j] = index++;
        j--; up++;
        for (i = up; i <= down; i++)
            ans[i][j] = index++;
        i--; right--;
        for (j = right; j >= left; j--)
            ans[i][j] = index++;
        j++; down--;
        for (i = down; i >= up; i--)
            ans[i][j] = index++;
        i++; left++;
    }
    ///return ans;
}
 