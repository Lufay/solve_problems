/**
 * @file 149.max_points_on_a_line.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.20
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路：计算所有斜率，找到共线（共点同斜率）最多的那条直线上的点
 * 注意：1.单点情形；2.斜率为无穷大——vertical值（这算是一种特殊斜率）；3.重合点——dup值（附加到普通斜率和特殊斜率对应的记点数）；4.每个两点的斜率只计算一次——因为如果最多点在那条直线上，之前就能够求得最大点数；如果不在那条直线，求此次斜率是多余的
 */
 /**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Cmp {
public:
    bool operator() (const double a, const double b) const { 
        return b-a > 0.0000001;
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unsigned int n = points.size();
        if ( n < 3 ) 
            return n;
        int max_points = 2;
        for ( unsigned int i=0; i<n; ++i ) { 
            map<double, int, Cmp> point_slotes; //使用默认的less<Key>也能通过
            int vertical = 0;
            int dup = 1;    //初始化为1，代表 i 点
            for ( unsigned int j=i+1; j<n; ++j ) { 
                if ( points.at(i).x == points.at(j).x ) {
                    if ( points.at(i).y == points.at(j).y )
                        dup++;  
                    else    
                        vertical++;
                }       
                else {  
                    double slote = (double(points.at(i).y - points.at(j).y))
                        / (points.at(i).x - points.at(j).x);
                    point_slotes[slote]++;  //不存在的值被初始化为0
                }       
            }       
            for ( map<double, int>::iterator iter=point_slotes.begin();
                iter != point_slotes.end(); ++iter ) {
                if ( iter->second + dup > max_points )
                    max_points = iter->second + dup;
            }       
            if ( vertical + dup > max_points )
                max_points = vertical + dup;
        }       
        return max_points;
    }
};

