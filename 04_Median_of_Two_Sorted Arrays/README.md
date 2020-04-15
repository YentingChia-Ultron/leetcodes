# 4. Median of Two Sorted Arrays ( Hard )
## Description
There are two sorted arrays nums1 and nums2 of size m and n respectively.  
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).  
_You may assume nums1 and nums2 cannot be both empty._  


#### Example 1
nums1 = [1, 3]  
nums2 = [2]  
The median is 2.0  

#### Example 2
nums1 = [1, 2]  
nums2 = [3, 4]  
The median is (2 + 3)/2 = 2.5  

## Solution
從題目的限制 **O(log (m+n))** 可推測此題或許可以用 binary search 來解。  
#### 前置
一開始，都以第一個array比較小為前提來做。  
```
if (n1>n2)
    return findMedianSortedArrays(nums2, nums1);
```
#### Idea
若兩個array合併，則會有 n1 + n2 個元素。
其中，如果 n1 + n2 是奇數，中位數會是正中間的元素（第 k 個元素）。  
如果是偶數，則為中間兩個元素（第 k 、 k + 1 個元素）之平均。  
```
int k = (n1 + n2 + 1) / 2;
```
假設從 nums1 取 **m1** 個元素，則 num2 會取 **m2 = m1 - k** 個元素。  

如果 n1 + n2 是奇數，我們就要找出第 k 個元素，也就是 max(**m1** 個元素的 max, **m2** 個元素的 max)  
如果 n1 + n2 是偶數，我們除了找出第 k 個元素，還要找出第 k + 1 個元素，也就是 min(**m1** 個元素之外的 min, **m2** 個元素之外的 min)  

#### Binary Search
**step 1**   

這邊在 while loop，所們利用 Binary Search 找出 m1、m2。  
```
int left = 0, right = n1; 
while(left < right){
    int m1 = left + (right - left) / 2 ;
    int m2 = k - m1;
```
**step 2**   

我們要保證最後的結果必須 **nums1[m1] >=  nums2[m2-1]**  
如果第 nums1 的第 m1 + 1 個元素小於 nums2 的第 m2 個元素，代表在 nums1 取得元素們的最大值太小，所以必須將目標直往右移
```
if(nums1[m1] < nums2[m2-1])
    left = m1 + 1;
```
反之，則須找到那個最靠近 nums2 的第 m2 個元素，且大於它的那個值
```
else
    right = m1;
}
```
#### 提醒
在最後 assign 結果的時候，要做好超出 nums1、nums2 邊界的打算
```
result = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], 
             m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
```
```
result+= min(m1 >= n1 ? INT_MAX : nums1[m1],
             m2 >= n2 ? INT_MAX : nums2[m2]);
```