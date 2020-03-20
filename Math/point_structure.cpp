struct point
{
	int x,y;

	point(){}
	point(int _x,int _y):x(_x),y(_y){}

	point operator - (const point &p)const      // vector
	{
		return point(x-p.x,y-p.y);
	}

	int operator * (const point &p)const        // cross product
	{
		return x*p.y-y*p.x;
	}

	int operator ^ (const point &p)const        // dot product
	{
		return x*p.x+y*p.y;
	}

	int dis(const point &p)const                // distance
	{
		return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);
	}
};

bool cw(point &a, point &b, point &c)           // clockwise orientation
{
	int area=a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	return area<0;
}

bool ccw(point &a, point &b, point &c)          // counter-clockwise orientation
{
	int area=a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	return area>0;
}
