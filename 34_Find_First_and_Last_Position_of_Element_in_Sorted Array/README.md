# 34. Find First and Last Position of Element in Sorted Array( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given ```target``` value.  

Your algorithm's runtime complexity must be in the order of O(log n).  

If the target is not found in the array, return ```[-1, -1]```.  

**Example 1:**  

**Input**: nums = [5,7,7,8,8,10], target = 8  
**Output**: [3,4]      


**Example 2:**  
 
**Input**: nums = [5,7,7,8,8,10], target = 6   
**Output**: [-1,-1]  


## Solution
首先，我們注意到題目有要求要在 O(log n) 內解決，基於這題是要「尋找」元素的題目，所以我們很適合用 Binary Search 來解。  

### solution 1
我們建立兩個 function，分別找出目標範圍的最左邊和最右邊。  
一樣都是用 Binary Search 但在判斷的地方分別會有些不同：  

##### 找左邊的函式   
```c
int findLeftEqual(const vector<int>& nums, const int target)
        ...
if(nums[mid] < target)
    l = mid + 1;
else
    r = mid;
```  
因為```(nums[mid] < target)```，l 和 r 最後會交會在**大於等於** target 的那個位置。  

##### 找右邊的函式     
```c
int findRightEqual(const vector<int>& nums, const int target)
        ...
if(nums[mid] <＝ target)
    l = mid + 1;
else
    r = mid;
//最後 l 要減掉 1
```  
因為```(nums[mid] <＝ target)```，l 和 r 最後會交會在**大於等於** target 再**右邊一個**的位置，所以這邊最後 l 要記得減掉 1。  

### solution 2
我們可以把解法一稍微改一點點，讓他運行的速度微微加快一些。  
因為我們要找的範圍最右邊，它一定會大於等於最左邊，所以我們可以再找完左邊之後，直接使用找到的最左邊來做。
```c
int left = findLeftEqual(nums, target);
if(left == -1) return {-1, -1};
return {left, findRightEqual(nums, target, left)};
```  

### solution 3
我們可以把解法二再稍微改一點點。  
因為我們上面找最左邊的方法```findLeftEqual()```，其實就是找到**大於等於**目標的位置，所以就算目標本身不存在，我們找到的位置也一定是最靠近它且大於它的元素（的位置）。    
這也表示，最接近但小於目標的這個元素的位置，定在最後找到的位置的左邊一個位置。  
所以，如果我們將搜尋目標定為```target + 1```，最終找到的這個位置一定緊鄰著 target **最右邊**（假如我一開始有找到 target 最左邊）。    
**注意**，這個方法只適用於整數！   
注意，這個方法只適用於整數！  
```c
int left = findLeftEqual(nums, target, 0);
if(left >= nums.size() || nums[left] != target) return {-1, -1};
return {left, findLeftEqual(nums, target + 1, left) - 1};
```  

---

