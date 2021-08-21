class PrimeSoccer
{
    public:
     double getProbability(int A, int B)
         {
            double dp1[20][20] ; // 18 round and 18 goal
            dp1[0][0] = 1.0; // 0 goal in 0 round is always possible

            for(int i = 1; i <=18; ++i)
            {
                dp1[i][0] = dp1[i-1][0] * ( 1 - (double)A/100) ; // Score 0 goal in this round , prev also dont score and here also dont score.
                for(int j =1; j <=18; ++j)
                {
                    dp1[i][j] = dp1[i-1][j] * ( 1 - (double)A/100); // Score j goal in i-1 round and dont score any goal in this round
                    dp1[i][j] += dp1[i-1][j-1] * ((double)A/100); // Dont score in previous round but score in this round.
                }
            }

            double dp2[20][20] ; // 18 round and 18 goal
            dp2[0][0] = 1.0; // 0 goal in 0 round is always possible

            for(int i = 1; i <=18; ++i)
            {
                dp2[i][0] = dp2[i-1][0] * ( 1 - (double)B/100) ; // Score 0 goal in this round , prev also dont score and here also dont score.
                for(int j =1; j <=18; ++j)
                {
                    dp2[i][j] = dp2[i-1][j] * ( 1 - (double)B/100); // Score j goal in i-1 round and dont score any goal in this round
                    dp2[i][j] += dp2[i-1][j-1] * ((double)B/100); // Dont score in previous round but score in this round.
                }
            }
            unordered_set<int> prime = { 2, 3, 5, 7, 11, 13, 17};
            double sum = 0;
            for(auto i : prime)
            {
                sum += dp1[18][i]; // After 18 round this many prime goal is score
                sum += dp2[18][i];        
            }
            // Inclusion Exclusion principle, i.e. delete the common double counted.
            for(auto i : prime)
                for(auto j : prime)
                    sum -= (dp1[18][i]*dp2[18][j]);
         return sum;
}
