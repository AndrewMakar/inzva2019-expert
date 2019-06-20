const int MAX = 100100;
const int LEN = 18;
const int ALP = 128; // size of the alphabet. 128 for all chars in ASCII order
char S[MAX];     // input string
int Q[MAX];      // indices for each class
int C[LEN][MAX]; // classes of equivalence
int P[LEN][MAX]; // permutations
int CNT[MAX];   // number of occurrences of each equivalence class
void buildArray(int n)
{
	FOR (i, 0, n)
		CNT[(int)S[i]]++;
	int sum = 0;
	FOR (i, 0, ALP)
	{
		Q[i] = sum;
		sum += CNT[i];
	}
	FOR (i, 0, n)
	{
		P[0][Q[(int)S[i]]] = i;
		Q[(int)S[i]]++;
	}
	C[0][P[0][0]] = 0;
	FOR (i, 1, n)
	{
		C[0][P[0][i]] = C[0][P[0][i-1]];
		if (S[P[0][i]] != S[P[0][i-1]]) C[0][P[0][i]]++;
	}
	FOR (it, 1, LEN)
	{
		int* Ccur = C[it];
		int* Cprev = C[it-1];
		int* Pcur = P[it];
		int* Pprev = P[it-1];
		int len = (1<<(it - 1));
		if (len >= n)
		{
			FOR (i, 0, n)
			{
				Ccur[i] = Cprev[i];
				Pcur[i] = Pprev[i];
			}
			continue;
		}
		FOR (i, 0, n)
			CNT[i] = 0;
		FOR (i, 0, n)
			CNT[Cprev[i]]++;
		int sum = 0;
		FOR (i, 0, n)
		{
			Q[i] = sum;
			sum += CNT[i];
		}
		FOR (i, 0, n)
		{
			int cur = Pprev[i];
			int prev = cur - len;
			if (prev < 0) prev += n;
			Pcur[Q[Cprev[prev]]++] = prev;
		}
		Ccur[Pcur[0]] = 0;
		FOR (i, 1, n)
		{
			int cur = Pcur[i];
			int prev = Pcur[i-1];
			Ccur[cur] = Ccur[prev];
			if (Cprev[cur] != Cprev[prev])
			{
				Ccur[cur]++;
				continue;
			}
			int cc = cur;
			cur += len;
			if (cur >= n) cur -= n;
			prev += len;
			if (prev >= n) prev -= n;
			if (Cprev[cur] != Cprev[prev])
			{
				Ccur[cc]++;
				continue;
			}
		}
	}
}
