#include <iostream>
#include <vector>
#include <math.h>

class backjoon_2166
{
public:

    struct Point
    {
    public:
        int x;
        int y;
    };

    std::vector<Point> dots;
    int count;

    // 2차원 평면공간서 두 점의 거리를 구합니다.
    double getDistanceBetweenPoints(Point d1, Point d2)
    {
        return std::sqrt(std::pow((d2.x - d1.x), 2) +
            std::pow(d2.y - d1.y, 2));
    }

    // 삼각형 3 변의 길이를 토대로 넓이를 리턴합니다.
    double getHeronsFormula(double a, double b, double c)
    {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }


    double getPolygonArea()
    {
        double area = 0;

        for (int i = 1; i < count - 1; ++i)
        {
            double distance1 = getDistanceBetweenPoints(dots[0], dots[i]);
            double distance2 = getDistanceBetweenPoints(dots[i], dots[i + 1]);
            double distance3 = getDistanceBetweenPoints(dots[i + 1], dots[0]);

            area += getHeronsFormula(distance1, distance2, distance3);
        }

        return area;
    }

    void run()
    {
        std::cin >> count;

        Point temp;
        for (int i = 0; i < count; ++i)
        {
            std::cin >> temp.x >> temp.y;
            dots.push_back(temp);
        }

        std::cout << getPolygonArea() << std::endl;
    }
};