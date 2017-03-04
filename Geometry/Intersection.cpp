#include <bits/stdc++.h>

// Macros are just my personal preference
#define crossProduct(a, b, c) ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y))
#define isLeft(a, b, c) (crossProduct(a, b, c) > 0)
#define isRight(a, b, c) (crossProduct(a, b, c) < 0)
#define isColinear(a, b, c) (crossProduct(a, b, c) == 0)
#define sameSide(a, b, c, d) (crossProduct(a, b, c) * crossProduct(a, b, d) > 0)
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)
#define intersect(a, b, c, d) (!sameSide(a, b, c, d) && !sameSide(c, d, a, b) && (min(a.x, b.x) <= max(c.x, d.x)) && (min(c.x, d.x) <= max(a.x, b.x)) && (min(a.y, b.y) <= max(c.y, d.y)) && (min(c.y, d.y) <= max(a.y, b.y)))
#define dist(a, b) (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)))
#define distPointToLine(c, a, b) (abs(crossProduct(a, b, c)) / dist(a, b))

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y)
        : x(x)
        , y(y) {};
};

// Implementation using inline functions
/*inline double min(double a, double b) {
    return (a < b) ? a : b;
}

inline double max(double a, double b) {
    return (a > b) ? a : b;
}

inline double crossProduct(Point a, Point b, Point c) {
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

inline bool isLeft(Point a, Point b, Point c) {
    return crossProduct(a, b, c) > 0;
}

inline bool isRight(Point a, Point b, Point c) {
    return crossProduct(a, b, c) < 0;
}

inline bool isColinear(Point a, Point b, Point c) {
    return crossProduct(a, b, c) == 0;
}

inline bool sameSide(Point a, Point b, Point c, Point d) {
    return crossProduct(a, b, c) * crossProduct(a, b, d) > 0;
}

inline bool intersect(Point a, Point b, Point c, Point d) {
    return (!sameSide(a, b, c, d) &&
            !sameSide(c, d, a, b) &&
            min(a.x, b.x) <= max(c.x, d.x) &&
            min(c.x, d.x) <= max(a.x, b.x) &&
            min(a.y, b.y) <= max(c.y, d.y) &&
            min(c.y, d.y) <= max(a.y, b.y));
}

inline double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline double distPointToLine(Point c, Point a, Point b) {
    return abs(crossProduct(a, b, c)) / dist(a, b);
}*/

int main()
{
    Point a(0, 1), b(2, 1), c(2, 0), d(2, 1);
    printf("Da li se prave |ab| i |cd| seku? %s.\n", intersect(a, b, c, d) ? "Da" : "Ne");
    printf("|ab| = %.2f\n|cd| = %.2f\n", dist(a, b), dist(c, d));
    printf("Udaljenost c od prave ab = %.2f", distPointToLine(c, a, b));
    return 0;
}
