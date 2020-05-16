#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class EmoticonsDiv2
{
public:
int printSmiles(int n)
{

   int sum = 0;
    while (n % 2 == 0)  
    {  
        sum += 2;
        n = n/2;  
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            sum += i;
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
		sum += n;
    return sum;
}  
};
