struct Point {
    int x, y;

    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}

    Point operator-(const Point &p) const { // vector
        return Point(x - p.x, y - p.y);
    }

    int operator*(const Point &p) const { // cross product
        return x * p.y - y * p.x;
    }

    int operator^(const Point &p) const { // dot product
        return x * p.x + y * p.y;
    }

    int dis(const Point &p) const { // distance
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};

bool cw(Point &a, Point &b, Point &c) { // clockwise orientation
    int area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return area < 0;
}

bool ccw(Point &a, Point &b, Point &c) { // counter-clockwise orientation
    int area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return area > 0;
}
