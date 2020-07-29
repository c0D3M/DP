#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 55
unsigned int dp[MAX_N];

class SentenceDecomposition{
bool can(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a==b;
}
int cost(string a, string b)
{
	int diff =0;
	for (int i = 0; i < a.size(); ++i)
		if(a[i] != b[i])
			++diff;
	return diff;
}
unsigned int solution(string sentence, int pos, vector <string> validWords)
{
	if(sentence.size()<= pos)
		return 0;
	if(dp[pos]!=INT_MAX-1)
		return dp[pos];
	dp[pos] = INT_MAX ;
	for (int i = 0; i < validWords.size(); ++i)
	{
		unsigned int c = cost(validWords[i], sentence.substr(pos, validWords[i].size()));
		if(can(validWords[i], sentence.substr(pos, validWords[i].size())))
			dp[pos] = min(dp[pos],  c + solution(sentence, pos+validWords[i].size(), validWords));
	}	
	return dp[pos];
}
public:
int decompose(string sentence, vector <string> validWords)
{
	fill_n(dp, sizeof(dp), INT_MAX-1);
	// For every position of sentence against each word in validWords
	return solution(sentence, 0, validWords)== INT_MAX ? -1 : dp[0];
}
};
int main(int argc, char*argv[])
{
	class SentenceDecomposition a;
	
	//cout << a.decompose("neotowheret", {"one", "two", "three", "there"}); // 8
	//cout << a.decompose("abba", {"ab", "ac", "ad"}); // 2
	//cout << a.decompose("wjeutntaifytaqnwqmdsdwcojyfhpqyljbitldumrbbytijnmu", {"lud", "m", "qna", "fyj", "iat", "tnu", "ljy", "nut", "bit", "cow", "tib", "itb", "dsd", "mrb", "woc", "bty", "jni", "owc", "phq", "qhp", "udl", "dds", "yfj", "tnu", "tia", "m", "udl", "wej", "mwq", "anq", "ait", "dsd", "tyb", "jfy", "ljy", "aqn", "jni", "ewj", "qph", "jwe", "mbr", "rmb", "yft", "jni", "wmq", "wqm", "ytf", "ytf", "jyl", "bty"}); // -1
	//cout << a.decompose("ogodtsneeencs", {"go", "good", "do", "sentences", "tense", "scen"}); // 8
	cout << a.decompose("ommwreehisymkiml", {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}); // 10
	//cout << a.decompose("sepawaterords", {"separate","words"}); // -1
	return 0;
}
