This page explain techniques used to solve kth/ k type of problems.  
Often this problem can be solved used max-heap(for kth min problem) or min-heap(for k max problems).  
But this technique involve maintaining heap with attributes to extra space and sometime due to large input one can get TLE with this approach.  
Another way to solve this problem is Binary Search with Sliding Window technique which avoid maintaining priority queue and also faster.  

[378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)  **Medium**  

**Priority Queue Approach**:
1. Maintain a max heap.  
2. Run nested loop for row and column.  
3. If pq size < k , push 
4. Otherwise if element is smaller than top, pop and push.
5. Return top element

Time Complexity = O(n^2 log k)  
Space Complexity = O(k)  


**Binary Search Approach**:
Note that row and column are all sorted.  
That means matrix[0][0] is smallest and matrix[n-1][n-1] is largest.  
These server as lower and upper bound of binary search, our answer lies somewhere in betweem.  
```
        while(l < r){
            int mid = l + ((r-l)>>1);
            if(count(mid, matrix) >=k)
                r = mid;
            else
                l = mid +1;
        }
```
We are guessing an answer which is ```mid``` and then counting how many element are smaller than this guess in matrix.  
Now the key point is how to count.  
r = 0 to n , c = n-1, count 0.    
1. Iterate for each row.  
2. Inside the iterate loop, check keep decrement c until mat[r][c] > guess
3. When this while loop exit, that means those many ```c``` are smaller, add to count.  
Why not reset c to n-1 before next iteration: because we know all column are also sorted.  
```
      for(; r < n ; ++r){
            while(c >=0 and matrix[r][c] > t)
                --c;
            count += (c+1);// why +1 because 0-index will be 1 less.
        }
```
Time Complexity: remember binary search bound , so O( log (max-min) * n )  
Why ```n``` for each bsearch ? because maximum number of column less than guess could be ```c```  

**Example:**  

| | | |
| :---: | :---: |:---: | 
| 1 | 2 | 3 | 
| 4 | 5 | 6 | 
| 7 | 8 | 9 | 

lo = 1 , hi = 9 and k=5
Iter 1: mid = 5 (guess)  
   count:  
   1. r=0 , c= 2, since mat[0][2] smaller while loop wont run and we add count += c+1 count =3 and by looking we know 3 elements are smaller then our guess of 5  
   2. r=1, c = 2, while loop stop at c=1 and we add c+1 and we see 4 & 5 are lesser than guess.  
   3. r=2, c= 1, loop exit at c=-1 and hence we add nothing c+1 =0 so total we have 5  
Iter 2: since 5 >=k , hi =5 , now mid (guess) = 3
And we keep doing until lo < hi finally print answer as lo=5

Key takeaway on how to solve.
1. Look what problem is asking for and establish lower and upper bound for it.  
2. Try to figure out count function and you are done.

[668. Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)  **Hard**  
Exact same as above , some minor tweak on establishing lower/upper bound and what to start with in count function.  

[719. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)  **Hard**  
Exact same procedure.
Sort the input and find the upper and lower bound, why sort because it asking for any pair, sort gives us bound since smaller distance can be 0  
and maximum wuld be nums[n-1] - nums[0]  
How to count: use sliding window  
For each index see how much you can go on right side until the distance <= guess  
count will be (r -l ), these many pairs.  

Example:
[1,2,3,4,5] k =3
lo =0, hi = 5-1= 4 (distance)
Iter :1 Guess distance be as 2
Count how many pair has distance less than 2
Start with left = 1 and extend on right side (inner while loop of count function)  so there are 2 pair [1,2] & [1,3]  count =2
left = 2 we get [2,3] & [2,4] = 2 and total count = 4
left = 3 also 2 of them , count = 6
left = 4 1 pair of [4,5] count = 7
since count >= guess of 4 , hi = 4, lo =0

Similar repeat and we get l = 1 ([1,2] , [2,3], [3,4] , [4,5] ....) There are 4 pair with distance of 1 and we are asking k =3

[1918. Kth Smallest Subarray Sum](https://leetcode.com/problems/kth-smallest-subarray-sum/)  **Hard**  
here we have find the subarray sum whose sum is kth smallest, note the subarray can be of size 1.  
Step 1:
lower bound set as 0 (this is arbitarily chosen)  
upper bound would sum of all element in array.  
Our answer lies in between this.  
Step 2:
Count routine: use sliding window, remember there are problem count how many subarray whose sum is give.  
```
int count(int t, vector<int>& nums){
        int left = 0;
        int n = nums.size();
        int sum =0;
        int count =0;
        for(int right =0; right < n ; ++right){
            sum += nums[right];
            while(sum > t){
                sum -= nums[left++];
            }
            count += right - left +1; //This trick count all subarray between indcies , for example array is [1,2] we know there are 3 subarray [1] [2] [1,2]
                                      // first time right = 0, left =0 , count =1
                                      // 2nd time right =1 left =0 , count **+=** (1-0 +1) = 3
        }
        return count;
    }
```

[1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows](https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)  **Hard**  

[658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)  **Medium**  

[373. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)  **Medium**  
Although it is possible to solve this using binary search approach but since we have to find all k-pairs, in my experince it is better to use
priority queue approach here.  
Put first k-element with nums1 and nums2 index min-heap.
while(k--)
pop out top element
this is surely an answer since its minimum ,
so add a new entry with nums2 index+1 if possible else skip.
Time complexity = K Log(K) 
Space = O(K)


[2040. Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)  **Hard**  

[786. K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/) **Hard**  
This problem involved floating point and we know answer lies between 0 and 1.  
Step 1: For these question set lower bound is 0 and upper bound is 1 and run loop until hi-lo > 1e-9 whatever fine precision is needed.  
Step 2 : count routine and we also need to find the indices of answer to return.  
Tip 1:  to  find whether x/y < guess , do x < y * guess
Tip 2: since we have to also store the number to return , check if new ratio is > old one if yes save that coz if have to return kth and this can be answer.  
```
// Return count and pair of i,j index
    pair<int, pair<int, int>> count(double t, vector<int>& arr){
        int i =-1;
        int count = 0;
        int numer=-1;
        int denom=-1;
        for(int j = 1; j < n ; ++j){
            while(i<n-1 and i < j-1 and arr[i+1] < arr[j] * t)
                ++i;       
            count += i+1;
            // Now since we have to return the index also
            // store the greatest
            
            if(i >=0 and ((numer==-1) or arr[numer] * arr[j] < arr[denom] * arr[i]))
            {
                numer = i;
                denom = j;
            }
        }
        return make_pair(count, make_pair(numer, denom));
    }
```
