# 45. Jump Game II ( Hard )

+ [Description](#Description)  
+ [Solution](#Solution)  

## Description
Given an array of non-negative integers, you are initially positioned at the first index of the array.  

Each element in the array represents your maximum jump length at that position.  

Your goal is to reach the last index in the minimum number of jumps.  

**Example 1:**  

**Input**: [2,3,1,1,4]        
**Output**: 2  
**Explanation**:    
    The minimum number of jumps to reach the last index is 2.  
    Jump 1 step from index 0 to 1, then 3 steps to the last index.      

**Note:**   
You can assume that you can always reach the last index.    


## Solution
題目有提到，並不會出現到不了終點的情況，所以我們在解題時可以不用考慮到這點。  

### step 1
首先，我們可以先看，每個位置他們各自最遠可以跳到哪裡，下面以例題說明：  
輸入：[2,3,1,1,4]  
對應最遠跳躍位置：[0 + 2, 1 + 3, 1 + 2, 1 + 3, xx]（最後一位甭管反正一定會到）= [2, 4, 3, 4, xx]  

上面我們可以觀察到，在位置1和位置2時，他們才有能力跳到最後面（位置4），所以我們就要想辦法找到，如何判斷我們會「經過」這些位置，並在上面做出「跳躍」的動作。   

### step 2
一開始我們先設一個「當前位置」為零。
然後是一邊更新「最大跳躍位置」。  
當更新的位置和「當前位置」重合的時候，我們就檢查，目前的「最大跳要位置」有沒有大於「當前位置」  
如果大於，就表示其實可以用更少的步數，在跳到現在這個位置```之前```，就停下，並跳得更遠，所以我們在這個時候，就要把我們的「當前位置」更新到「最大跳要位置」，並且因為這代表我們在```之前```又跳躍了一次，所以跳躍次數也要記得加一。   
  

```c
    for(int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(maxPos, nums[i] + i);
            if(i == current)
            {
                ++result;
                if(maxPos >= nums.size() - 1)
                    return result;
                current = maxPos;
            }
        }
```

---

