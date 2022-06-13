Line Sweep Algorithms
-------------------------
Conept: Think it as an imaginary line (vertical or horizontal) when swept across that axis, some points would enter and some exit.
An observation to see is that since point (x or y co-ordinate) would occur in increasing order , we have to use some ordered dats structure like set/map or even arrays.

Lets see with an easy example:
This is going to be a long post, so lets divide in 3 parts
1. 1D Easy/Medium problem  
2. 1D Hard  
3. 2D problems  

### 1D Easy/Medium problem ###   
[1854. Maximum Population Year](https://leetcode.com/problems/maximum-population-year/) [**Easy**]  
Here we are given birth & death year of persons.
Imagine this as a line , when a person born , population of that year +1 and when he expires population decreases by 1.  
![image](https://user-images.githubusercontent.com/20656683/173176474-fb0392a8-82c5-4620-8c1a-1cb54cf4cad6.png)

Plot the population year on a number line.
When a person is born increment by +1 and when he expire decrement by -1 .
Scan from left and accumulate the population, everytime check if current population is greater than global max , if yes update population count and year both.
This scanning from left to right is line sweep.

Time Complexity = O(n log n) (due to tree map)

[253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) [ **Medium**]  
Same as above just we have to keep track of count and return it.  
Time Complexity = O(n log n )

[731. My Calendar II](https://leetcode.com/problems/my-calendar-ii/) [ **Medium** ]  
We have to count if there are triple booking , so if at any time we have count >=3 (==3 is enough)  
We return false and also remove this booking from the entry.  
Same approach, use a map and +1 when booking start and -1 when booking end.  
Sweep the line from left to right.  

Time Complexity = O(n^2) as for every booking we are sweeping entire line.  

[2237. Count Positions on Street With Required Brightness](https://leetcode.com/problems/count-positions-on-street-with-required-brightness/) [ **Medium** ]  
Similar, here we are given a threshold of brightness for each index, first fill up the count by +1 and -1 index where brightness start and end.  
Now scan the vector and see if threshold achieved , if yes ++ans.  

Time Complexity = O(n)

[1893. Check if All the Integers in a Range Are Covered](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/) [**Easy** ]  
Mark start and end( end+1 since its a closed interval] as +1/-1 respectively.  
Now scan the line from 1 to 50 , see which co-ordinate falls in given [left right] range and overlap is 0, that mean no range is covering , return false.  

Time Complexity = O(n)  

[370. Range Addition](https://leetcode.com/problems/range-addition/) [ **Medium**]  
Accumulate +update in start and -update in end+1  
After that sweep the line and accumulate sum in a variable and keep assigning to every index.  

Time Complexity = O(n)  

Type 2:

[452. Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) [ **Medium**]  
In this kind of problem, we dont use marking on axis, instead axis is already given, we sort it.
After that we do operation  
[435  Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) [ **Medium** ]  

[252. Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) [ **Easy**]  
Just scan and if ith start < i-1 end return false

[1272. Remove Interval](https://leetcode.com/problems/remove-interval/) [ **Medium** ]  

**Approach #1**:
increment at start and decrement end , while for remove interavl do reverse since we have to remove
standard logic of count==i.start and count > 0 
and for closing interval count=0 and we have added previously(use a bool flag)

**Approach #2**:
Input is sorted, so we sweep and if removed_start > ith_end or remove_end < ith_start , we simply add the ith boundary to o/p.  
Otherwise if ith_start < remove_start -> add ith_start, remove_start  
Also if ith_end > remove_end then add [remove_end, ith_end]  

Both approach coded for comparison, Merge Interval and Insert Interval can also be solved using similar approach.  
Please let me know in comment section which approach is preferable as I am still learning.  
Its a bit tough to come up Approach 1 for all problem but Approach 2 works for all.  

<table>
<tr>
<th> Using Map counter </th>
<th> Using  prev interval </th>
</tr>
<tr>
<td>

```c++
        map<int, int> line;
  
	for(auto& i : intervals)
	{
		++line[i[0]];
		--line[i[1]];
	}
	--line[toBeRemoved[0]];
	++line[toBeRemoved[1]];
	vector<vector<int>> ans;
	int count =0; bool added =false;
	for(auto& i : line)
	{
		count += i.second;
		if(count > 0 and count==i.second){
			ans.push_back({i.first, -1});
			added = true;
		}
		if(count==0 and added){
			ans.back()[1] = i.first;
			added = false;
		}
	}
	return ans;
```

</td>
<td>

```c++
	vector<vector<int>> ans;
	
	for(auto &i :  intervals)
	{
		int left = i[0];
		int right = i[1];
		if( (toBeRemoved[0] > right ) or (toBeRemoved[1] < left ))
		{
			ans.push_back({left, right});
		}
		else
		{
			if(left < toBeRemoved[0])
			{
				ans.push_back({left, toBeRemoved[0]});
			}
			if (right > toBeRemoved[1])
			{
				ans.push_back({toBeRemoved[1], right});
			}
		}
	}
```
</td>
</tr>
</table>

[57. Insert Interval](https://leetcode.com/problems/insert-interval/) [ **Medium** ]  
<table>
<tr>
<th> Using Map counter </th>
<th> Using  Interval </th>
</tr>
<tr>
<td>

```c++
	vector<vector<int>> result;
	const int n = intervals.size();
	if(!n)
		return vector<vector<int>>(vector<vector<int>>({newInterval}));
	int n_s = newInterval[0];
        int n_e = newInterval[1];
        int i;
        for (i = 0; i < n; ++i)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if( (n_s >=s) and (n_e<= e) ) // Complete overlap , just return
                return intervals;
            else if (n_s > e) // left no overlap
                result.push_back(intervals[i]);
            else if (s > n_e) // right overlap
            {
                result.push_back(vector<int>({n_s, n_e}));
                result.push_back(intervals[i]);
                break;
            }
            else
            {
                n_s = min(s, n_s);
                n_e = max(e, n_e);
            }
        }
        
        // It is bound to happen that new interval would be inserted 
	// some-where and break , if that is not the case
        // that means end of intervals, in that case, insert the new interval.
        if(i==n)
            result.push_back(vector<int>({n_s, n_e}));
        else
            for (int j = i +1; j < n ; ++j)
                result.push_back(intervals[j]);
        return result;
```

</td>
<td>

```c++
	vector<vector<int>> ans;
	
	for(auto &i :  intervals)
	{
		int left = i[0];
		int right = i[1];
		if( (toBeRemoved[0] > right ) or (toBeRemoved[1] < left ))
		{
			ans.push_back({left, right});
		}
		else
		{
		    if(left < toBeRemoved[0])
		        {
			    ans.push_back({left, toBeRemoved[0]});
			}
			if (right > toBeRemoved[1])
			{
			    ans.push_back({toBeRemoved[1], right});
			}
		}
	}
```
</td>
</tr>
</table>

[56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) [ **Medium**]  
<table>
<tr>
<th> Using Map counter </th>
<th> Using  prev interval </th>
</tr>
<tr>
<td>

```c++
    	map<int, int> line;
        for(auto& i : intervals){
            ++line[i[0]];
            --line[i[1]];
        }
       
        int count = 0;
        vector<vector<int>> ans;
        for(auto& i : line){
            count += i.second;
            if(count==i.second)
                ans.push_back({i.first, -1});
            if(count==0)
                ans.back()[1] = i.first;
        }
        return ans;
```

</td>
<td>

```c++
	sort(intervals.begin(), intervals.end());// Sort y there start time
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        for(int i =1; i < intervals.size(); ++i){
            if(intervals[i][0] > results.back()[1]) // a new begining
            {
                results.push_back(intervals[i]);
            }
            else
                results.back()[1] = max(results.back()[1], intervals[i][1]);
        }
        return results;
```
</td>
</tr>
</table>

	
	
[1589. Maximum Sum Obtained of Any Permutation](https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/) [ **Medium**]  
[1943. Describe the Painting](https://leetcode.com/problems/describe-the-painting/) [ **Medium** ]  
[1674. Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/) [ **Medium**]  

### 1D Hard problem ### 

These 1D Hard problem require scanning line for each input which can lead to O(n^2) algorithm.  
We have to do something special to optimize it.  
Lets see with an example.  

[2158. Amount of New Area Painted Each Day](https://leetcode.com/problems/amount-of-new-area-painted-each-day/) [**Hard** ]  
In this problem each day we paint some section of a line.  
Brute force way is scan line for each input index.  

Thanks to @cjcoax and @votrubac, I am putting both line sweep version and map interval method here.  
Similar problem
[2251. Number of Flowers in Full Bloom](https://leetcode.com/problems/number-of-flowers-in-full-bloom/) [ **Hard**]  
  
<table>
<tr>
<th> Using Line Sweep </th>
<th> Using Vector Interval </th>
</tr>
<tr>
<td>

```c++
    	auto cmp =[&](const vector<int>& a, const vector<int>& b){
            return a[1]  < b[1];  
        };
        int maxEnd = (*max_element(paint.begin(), paint.end(), cmp))[1];
        int n = paint.size();
        vector<int> ans(n, 0);
        vector<vector<pair<int, int>>> line(1 + maxEnd);
        // We are marking on line that co-oridnate is 
	// painted/not-painted(true-false) between which date
        for(int i =0; i < n ; ++i){
            line[paint[i][0]].push_back(make_pair(i, 1));
            line[paint[i][1]].push_back(make_pair(i, 0));
        }
        
        set<int> days;
        //Scan the line
        for(int i =0; i < maxEnd; ++i){
            
            // Who all present on this x co-ordinate?
            for(auto& [day, state] : line[i]){
                
                if(state)
                    days.insert(day);
                else
                    days.erase(day);
            }
            //Only the first guy can paint this line
            if(!days.empty())
                ans[*(days.begin())]++;
        }
        return ans;
```

</td>
<td>

```c++
	map<int, int> m;
    vector<int> res;
    for (auto &p : pt) {
        int l = p[0], r = p[1];
        auto next = m.upper_bound(l), cur = next;
        
        // Step 1: suppose we have painted [1, 4] [ 5, 8] [10, 20]
        // Now a new interval [4, 21] comes upper_bound gives [5,8]
        // l = 4 then
        if (cur != begin(m) && prev(cur)->second >= l) {
            cur = prev(cur);
            l = cur->second;
        }
        else 
            cur = m.insert({l, r}).first;
        int paint = r - l;
        // Next since r= 21 and that is  > 5, that means this paint is going to span
        // find how much shd we subtract :
        // get min of (21, 8) =  8 and then subtratc with start 5 = 3
        // now r shd be max of (21, 8) =21 , check further more intervals can be erased ?
        // in the end set curr->second = max(curr->second, r);
        while (next != end(m) && next->first < r) {
            paint -= min(r, next->second) - next->first;
            r = max(r, next->second);
            m.erase(next++);
        }
        cur->second = max(cur->second, r);
        res.push_back(max(0, paint));
    }
    return res;
```
</td>
</tr>
</table>

	
	
[732. My Calendar III](https://leetcode.com/problems/my-calendar-iii/) [**Hard** ]  
Same as  Meeting Room II as explained earlier.  


[759. Employee Free Time](https://leetcode.com/problems/employee-free-time/) [**Hard**]  
Same conepts, mark start and end time on line, when will everyone is free i.e. when count is 0.
So whenever count is 0 , it mark the begining of an interval, also set a flag , so that after we non-zero from 0, we use that as closing interval.
```
	map<int, int> line;
        for(auto& s : schedule){
            for(auto& i :  s){
                ++line[i.start];
                --line[i.end];
            }
        }
        
        int count = 0;
        bool found = false;
        vector<Interval> ans;
        for(auto&x : line){
            count += x.second;
            if(found){
                ans.back().end = x.first;
                found = false;
            }
            if(count == 0){
                // mark begining of new interval
                ans.push_back(Interval(x.first, -1));
                found = true;
            }
        }
        ans.pop_back();
        return ans;
```
[1851. Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/) [**Hard**]  
There are possibly better ways to solve this but for explaining line sweep.  
Each start and end (end+1 ) insert the size of interval. We will use set for each co-ordinate of line and the order would be
insert/delete/query, for example so on an index , interval start, end and there is a query also.
We will first add , then subtract and then do a query so that we have final result of minmum at the end.

```
       map<int, set<pair<int, int>>> line;
        // 1 :  Entry  -1 : Exit , 2 : Query & size of interval
        for(auto& i : intervals){
            int size = i[1] -i[0] + 1;
            line[i[0]].insert(make_pair(-1, size));
            line[i[1]+1].insert(make_pair(1, size));
        }
        
        for(int i =0; i < queries.size(); ++i){
            line[queries[i]].insert(make_pair(2, i));
        }
        vector<int> ans(queries.size(), -1);
        multiset<int> sizes;
        for(auto& [x, intervals] :  line){
            for(auto& i : intervals){
                if(i.first==-1)
                    sizes.insert(i.second);
                else if (i.first==1)
                    sizes.erase(sizes.lower_bound(i.second));
                else if (i.first ==2 and !sizes.empty())
                    ans[i.second] = *(sizes.begin());
                
            }
            
        }
        return ans; 
```
	
### 2D Problem's ###  

https://leetcode.com/problems/perfect-rectangle/  
https://leetcode.com/problems/the-skyline-problem/  
https://leetcode.com/problems/rectangle-area-ii/
Closest pair of points  

Resources:
http://39.107.250.150/alg/greedy/%E5%8C%BA%E9%97%B4%E9%97%AE%E9%A2%98.html#%E5%8C%BA%E9%97%B4%E5%88%86%E7%BB%84
https://www.topcoder.com/thrive/articles/Line%20Sweep%20Algorithms
