#include <iostream>  //std::cout
#include <sstream>  //std::ostringstream
#include <algorithm>  //std::sort
#include <unordered_map>  //std::unordered_map
#include <vector>  //std::vector
#include <iomanip>  //std::setiosflags, std::setprecision
using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
int comparePoints(const Point &a, const Point &b) {
    return a.x - b.x;
}
double getApproximateDouble(double x, int digits) {  //error 0: a good way to hold "digits " digits after the decimal point
    ostringstream ostr;  //error 1: forget to include <sstream>
    ostr << setiosflags(ios::fixed) << setprecision(digits) << x;
    string s = ostr.str();
    return stod(s);
}
double getSlope(const Point &a, const Point &b) {
    if(b.x == a.x) {  //error 3: handle the case where multiple points in same location
        if(b.y == a.y)
            return numeric_limits<double>::min();  //represent the same location
        else
            return numeric_limits<double>::max();
    }
    double res = 1.0 * (b.y - a.y) / (b.x - a.x);
    return getApproximateDouble(res, 6);
}
int maxPoints(vector<Point> &points) {
    if(points.size() == 0) return 0;  //error 2: if without this, sort will in dead loop when vector is empty
    auto comp = bool (Point &a, Point &b) {return a.x < b.x; };  //this line is interesting, need to understand it furthermore.
    sort(points.begin(), points.end(), comp);
    int max_point = 1;
    for(int i=0; i < points.size()-1; ++i) {
        unordered_map<double, int> hash;
        int addition = 0;  //error 3: deal with the case where multiple points in same place  error 4: mistakenly put the initial of addition into the for loop
        for(int j=i+1; j < points.size(); ++j) {
            double slope = getSlope(points[i], points[j]);
            if(hash.find(slope) == hash.end()) {
                hash[slope] = 2 + addition;
            }
            else {
                hash[slope] ++;
            }
            if(max_point < hash[slope])  //error 5: mistakenly put the update of max_point int above else block
                max_point = hash[slope];
            if(slope == numeric_limits<double>::min()) {
                addition++;
            }
        }
    }
    return max_point;
}

int main() {
    vector<Point> vec;
    Point p = Point(1, 1);
    vec.push_back(p);
    p = Point(2,2);
    vec.push_back(p);
    p = Point(5,5);
    vec.push_back(p);
    p = Point(5, 6);
    vec.push_back(p);
    p = Point(7, 8);
    vec.push_back(p);
//    vec.clear();
    cout << "Max Points Number: " << maxPoints(vec) << endl;
}
