/*
  Expectation = RV * p [ RV random variable ]
  So in coin tossing case lets call head = 1 as RV
  Expctation = p.
  Now we have to find Expectation of n coins after flips
  Expectation(k) =  pk i.e. after k flips denoted in array a of size k.
  At each turn we know we have to flip a[i] coins
  Not flipped = pi * (1 - ai/N) ai/N going to be flipped, so 1-ai/N is not flipped ones
  Flipped = ai/N * (1-pi) -> probability of coins not ye flipped
  
  Another way to look is : Suppose there are 3H and 7T and we flip 3 coins , so how many heads ?
  Either we choose tails and that would become head : 3H * 7/10 +  7 * 3/10 
  First part says 3H remain untouched with 7/10 probability
  Second part says 7T converted to heade with 3/10 probability.
 */
double (int n, vector<int> a)
{
  
  double heads = n;
  double tails = 0;
  for(int i =0; i < a.size(); ++i)
  {
    // For each coin
    heads = ((N-a[i])*heads + a[i]*tails) / N;
    tails = N - heads;
  }
  return head;
}
