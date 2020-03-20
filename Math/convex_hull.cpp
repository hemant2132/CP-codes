#define coord int

struct Point
{
	coord x, y;
	int id;
};

bool comp(const Point &a, const Point &b)
{
    return mt(a.y, a.x, a.id) < mt(b.y, b.x, b.id);
}

coord cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool comp2(Point a, Point b)
{
    return mt(a.x, a.y) == mt(b.x, b.y);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	// Sort points lexicographically
	sort(P.begin(), P.end(), comp);

	P.resize(distance(P.begin(), unique(all(P), comp2)));

	int n = P.size(), k = 0;

	if(n == 1)
        return P;

	vector<Point> H(2*n);

	// Build lower hull
	for(int i = 0; i < n; ++i)
    {
		while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0)
            k--;

        H[k++] = P[i];
	}

	// Build upper hull
	for(int i = n-1, t = k+1; i > 0; --i)
    {
		while (k >= t && cross(H[k-2], H[k-1], P[i-1]) <= 0)
            k--;

		H[k++] = P[i-1];
	}

	H.resize(k-1);

	return H;
}
