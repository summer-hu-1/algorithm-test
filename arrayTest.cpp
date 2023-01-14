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
    //二分法 核心思路：1.定义左右边界区间，2.利用中间值缩小区间，3循环判断区间继续与否，中间值判断是否相等。

    ///方法一：左闭右闭
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

    ///方法二：左闭右开
    /*int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2; 
        if (target > nums[mid]) left = mid + 1;
        else if (target < nums[mid]) right = mid;
        else return mid;
    }
    return -1;*/
    ///一些思考：只需要考虑如何保持这个区间始终为不变量。
    ///例如：中间值判断不是目标值后，左边和右边取值是否为实心就变的有”理“可依。

    ///方法三:简洁版本 
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target < nums[mid]) right = mid - 1;
        else if (target > nums[mid]) left = mid + 1;
        else return mid;
    }
    return -1;
    ///一些思考：左右采用相同闭区间，实心点。
    ///1.区间相等时存在 2.左右区间变化均移动，需要实际点。
}

int arrayTest::removeElement(vector<int>& nums, int val)
{
    ///双指针法-核心思路：1.确定快慢指针的运动方向  2.确定两者之间前进的关系；

    ///方法一：快慢指针法
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

    ///方法二：相向指针法
    size_t leftIndex = 0, rightIndex = nums.size() - 1;
    while (leftIndex <= rightIndex)
    {
        while (leftIndex <= rightIndex && nums[leftIndex] != val) leftIndex++;
        while (leftIndex <= rightIndex && nums[rightIndex] == val) rightIndex--;
        if (leftIndex < rightIndex) swap(nums[leftIndex++], nums[rightIndex--]);
    }
    return leftIndex;
    ///一些思考：利用循环找到左边第一待替换元素(不等于val)，右边第一个需替换元素（等于val),
    ///找到一对后就开始替换，直到代替换区间全部处理完毕。
    ///最终leftIndex必然处于替换区间的下一个元素。（否则就还存在待处理区间,每次增加1，所以必然处于直接下家）

    ///简洁版本：
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (nums[fastIndex] != val)
            nums[slowIndex++] = nums[fastIndex];
    }
    return slowIndex;
    ///一些思考：以快指针为主对象，遍历整个数组元素，依次处理“符合条件”（不等于给定值元素），进行备份处理，并实现向前移动的操作。
}

vector<int> arrayTest::sortedSquares(vector<int>& nums)
{
    ///双指针法：

    ///方法一:直接法（采用直接模拟的思维处理即可）
    /*for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        *it *= *it;
    sort(nums.begin(), nums.end());
    return nums;*/

    ///方法二：相向双指针法
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
    ///一些思考：特征是大者在两端，从两端逐个缩小处理域。

    ///简洁版本：
    int len = nums.size();
    vector<int>temp(len);
    for (int left = 0, right = len - 1, cur = len - 1; left <= right; )
    {
        temp[cur--] = (nums[left] * nums[left] >= nums[right] * nums[right]) ? nums[left] * nums[left++] : nums[right] * nums[right--];
    }
    return temp;
    /// 一些思考：什么叫简洁，应该是逻辑清晰，代码恰到好处。
}

int arrayTest::minSubArrayLen(int target, vector<int>& nums)
{
    ///核心思路：滑动窗口方法。所谓滑动窗口，就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果。
    
    ///方法一：滑动窗口方法攻略
    int cur = INT_MAX, sum = 0;   ///bug one: cur的当前值处理不恰当，要定义为最大值才能返回既定值大小。
    for (int slow = 0, fast = 0; fast < nums.size(); )
    {
        sum += nums[fast++];
	    while (sum >= target && slow <= fast)
	    {
            cur = min(fast - slow, cur); ///fast总是指向窗口的下一个。
            sum -= nums[slow++];
	    }
    }
    return cur == 0x7fffffff ? 0 : cur;
    ///一些思考：1.保持窗口持续一格单位向前滑动  2.每次统计窗口值总和  3.当前窗口总和大于目标值时，更新当前最小连续数，并窗口前移
    ///最大值 ： 0x七个f.
}

vector<vector<int>> arrayTest::generateMatrix(int n)
{
    ///模拟法：核心思想：确定控制移动变量（方向，执行行），模拟运行路径即可。

    ///方法一：左闭右闭 下标统一  上右下左消消乐，一行一行干掉（一个循环）。结束时机与处理数量一层控制即可。
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
    ///一些思考：不知道如何动笔开始行动是最麻烦的。
    ///1.两层数组需要变化的量，总共1~n*n,一层循环可以控制。
    ///2.上右下左四个方向，一行一行消掉。
    ///
    ///bug:容易出现消掉当行，下一行的处理位置越界，两个控制变量要同时控制。

    ///方法二：左闭右开   TODO
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


    ///简介版：下标临时，上下左右控制下标。左闭右闭
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

    ///面试版：一入代码深似海，从此offer是路人。
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
 