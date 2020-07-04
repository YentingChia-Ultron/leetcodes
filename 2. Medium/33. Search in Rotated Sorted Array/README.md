# 33. Search in Rotated Sorted Array ( Medium )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.  

(i.e., ```[0,1,2,4,5,6,7]``` might become ```[4,5,6,7,0,1,2]```).  

You are given a target value to search. If found in the array return its index, otherwise return -1.  

You may assume no duplicate exists in the array.  

Your algorithm's runtime complexity must be in the order of O(log n).     

**Example 1:**  

**Input**: nums = [4,5,6,7,0,1,2], target = 0    
**Output**: 4    


**Example 2:**  
 
**Input**: nums = [4,5,6,7,0,1,2], target = 3    
**Output**: -1  


## Solution
首先，我們注意到題目有要求要在 O(log n) 內解決，基於這題是要「尋找」元素的題目，所以我們很適合用 Binary Search 來解。  
而array則會以這種形式排列：

<img width="421" height="271" src="https://i.ibb.co/6ZHJB2y/2020-06-08-19-27-41.png">     

### step 0 規則
我們可以從 array 中找到這兩個規則，並應用在下面解題中：
1. 若是一組 array 是排序好的，那麼他的最左值一定會小於最右值    
2. 若從題目的這種翻轉過的 array 中隨機找一個位置 i ，那麼```[0, i]```或```[i, n]```中必有一組為排序好的 array    

### step 1 找到排序好的那邊
因為要用 BS ，所以我們要先找到中間值 mid ，並以 mid 判斷是左邊還是右邊是排序好的（運用上面兩個規則）。
```c
//mid的左邊是排序好的
if(nums[mid] > nums[r])
```  

### step 2 是否在範圍內
找到排序好的那邊之後，我們就可以判斷 target 是不是在那之中  
如果是，則我們就繼續在這個範圍裡面做 BS  
如果不是， 那我們就可以直接捨棄這一段範圍，繼續找下一個區間  
```c
//mid的左邊是排序好的情況下
//target在其範圍中
if(target < nums[mid] && target >= nums[l])
    r = mid - 1;
else
    l = mid + 1;
```
---

