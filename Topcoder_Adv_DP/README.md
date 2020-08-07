#### Topcoder Advance DP  
Webinar:  https://www.youtube.com/watch?v=xQ4byx8XbXo  
You can practice these problem in Topcoder Arena Applet under Special Events section.  

1. [MutaliskEasy](https://community.topcoder.com/stat?c=problem_statement&pm=13782&rd=16461)  
From each state, we can go to 6 different state.  
dp[a][b][c], where a,b,c can be max 65.  
[9, 3, 1] , [9, 1, 3], [3, 9, 1] , [3, 1, 9], [1, 3, 9] , [1, 9, 3]  
Before evaluating the state, check in dp tate if it hasnt been evaluated earlier.  
Base condition: when a==0 and b==0 and c==0  
If a or b or c < 0, then call the function but set that to 0.  
This is helpful because we store dp[a][b][c] and we cant have -ve index.  
Also save each state on return.  

2. [SentenceDecomposition](https://community.topcoder.com/stat?c=problem_statement&pm=8692&rd=12183)  
We are given a target string and a dictionary, find the **least** transformation cost.  
dictionary word can be transformed to part of target string.  
Base Case: offset is greater than targetstring.  
State: Take each word(for loop) from dictionary, from the offset(starting from 0) take the substring of dictionary word size and see if we can transform.  
This can checked , sort both of them and if they are equal, transformation is possible.  
Calculate the cost and recurse by incrementing offset.  
dp state will be at each offset position.  

