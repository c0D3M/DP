/*
  Expectation = RV * p [ RV random variable ]
  So in coin tossing case lets call head = 1 as RV
  Expctation = p.
  Now we have to find Expectation of n coins after flips
  Expectation(k) =  pk i.e. after k flips denoted in array a of size k.
  At each turn we know we have to flip a[i] coins
  Not flipped = pi * (1 - ai/N) ai/N going to be flipped, so 1-ai/N is not flipped ones
  Flipped = ai/N * (1-pi) -> probability of coins not ye flipped
  
 */
double (int n, vector<int> a)
{
  double p = 1.0;
  for(int i =0; i < a.size(); ++i)
  {
    double q = a[i] / (1.0*n);
    p = p * (1 - q ) + (1-p) *q;
  }
  return p;
}
