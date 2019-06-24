int mrand()
{
	return abs((rand() << 16) ^ rand());
}
struct node
{
	int l, r;	// children
	int y;		// priority (should be random and different)
	int cnt;	// size of subtree
	int par;	// parent of the vertex
	int val;	// value of the vertex
	int rev;	// reverse push
	int mn;		// minimum of subtree
	
	void init(int val) // init with value
	{
		l = r = -1;
		y = mrand();
		cnt = 1;
		par = -1;
		this->val = val;
		mn = val;
		rev = 0;
	}
};
// Minimum on subtree + reverse
struct Treap
{
	node A[MAX];
	int sz;
	int getCnt(int x)
	{
		if (x == -1) return 0;
		return A[x].cnt;
	}
	int getMn(int x)
	{
		if (x == -1) return INF;
		return A[x].mn;
	}
	int newNode(int val)
	{
		A[sz].init(val);
		sz++;
		return sz - 1;
	}
	int PB(int root, int val)
	{
		return merge(root, newNode(val));
	}
	void upd(int x)
	{
		if (x == -1) return;
		A[x].cnt = getCnt(A[x].l) + getCnt(A[x].r) + 1;
		A[x].mn = min(A[x].val, min(getMn(A[x].l), getMn(A[x].r)));
	}
	void reverse(int x)
	{
		if (x == -1) return;
		swap(A[x].l, A[x].r);
		A[x].rev ^= 1;
	}
	void push(int x)
	{
		if (x == -1 || A[x].rev == 0) return;
		reverse(A[x].l);
		reverse(A[x].r);
		A[x].rev = 0;
	}
	PII split(int x, int cnt)
	{
		if (x == -1) return MP(-1, -1);
		if (cnt == 0) return MP(-1, x);
		push(x);
		int left = getCnt(A[x].l);
		PII res;
		if (left >= cnt)
		{
			if (A[x].l != -1) A[A[x].l].par = -1;
			res = split(A[x].l, cnt);
			A[x].l = res.second;
			if (res.second != -1) A[res.second].par = x;
			res.second = x;
		}
		else
		{
			if (A[x].r != -1) A[A[x].r].par = -1;
			res = split(A[x].r, cnt - left - 1);
			A[x].r = res.first;
			if (res.first != -1) A[res.first].par = x;
			res.first = x;
		}
		upd(x);
		return res;
	}
	int merge(int x, int y)
	{
		if (x == -1) return y;
		if (y == -1) return x;
		int res;
		//if (mrand() % (getCnt(x) + getCnt(y)) < getCnt(x))
		if (A[x].y > A[y].y)
		{
			push(x);
			if (A[x].r != -1) A[A[x].r].par = -1;
			res = merge(A[x].r, y);
			A[x].r = res;
			if (res != -1) A[res].par = x;
			res = x;
		}
		else
		{
			push(y);
			if (A[y].l != -1) A[A[y].l].par = -1;
			res = merge(x, A[y].l);
			A[y].l = res;
			if (res != -1) A[res].par = y;
			res = y;
		}
		upd(res);
		return res;
	}
} T;


