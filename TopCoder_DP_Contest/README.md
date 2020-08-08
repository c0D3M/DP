**TopCoder Dynamic Programming Webinar**  
Date: 14th May 2020

Practice Match:
https://www.topcoder.com/tc?module=MatchList  

Resources:  
https://apps.topcoder.com/forums/?module=Thread&threadID=955677&start=0  

https://www.topcoder.com/community/competitive-programming/tutorials/dynamic-programming-from-novice-to-advanced/  

1. [NumberofFiboCalls](https://community.topcoder.com/stat?c=problem_statement&pm=2292&rd=10709)  
Objective of problem is to find how many time {0, 1} would have been called to find n-th(input) fibonacci.  
Iterative we can build the dp array.  
For each number we will maintain number of {0} and {1}.  
Base case is for n=0 {0}= 1 and {1}=0.  
n=1 {0}= 0 and {1}=1.  

2. [EmoticonsDiv2](https://community.topcoder.com/stat?c=problem_statement&pm=13041&rd=15845)  

3. [HandsShaking](https://community.topcoder.com/stat?c=problem_statement&pm=7868&rd=10777)  
n is even.  
base case, if n = 0 dp[0] = 1, n=2 dp[2] = 1, n=4 dp[4] = 2.  
My approach is is to recursively split 'n' into 0 and n-2.  
Why n-2 because we are keeping 2 people fixed and left half is 0 and right half is n-2.  
then we increment left half by2 and decrement right by 2 and keep doingt left != right.  
Before recurse check if dp result is available or not.  


4. [MonstersAndBunnies](https://community.topcoder.com/stat?c=problem_statement&pm=8595&rd=12007)
Observation:  
   - If monsetr is 0, you wont die for sure , so retun 1.  
   - If monster is odd, sure you will die , so return 0.
   


5. [NumberofFiboCalls](https://community.topcoder.com/stat?c=problem_statement&pm=2292&rd=10709)  
6. [NumberofFiboCalls](https://community.topcoder.com/stat?c=problem_statement&pm=2292&rd=10709)  


