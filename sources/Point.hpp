#pragma once

#include <string>
#include <cmath>
#include <stdexcept>

namespace ariel
{
    class Point
    {
        private:
            double x_cor;
            double y_cor;

        public:
            
            Point(double pt_x, double pt_y);
            Point();
            double getX() const;
            double getY() const;
            double distance(Point other) const;
            std::string print() const;
            static Point moveTowards(const Point &curr, const Point &other, double dist);
    };
}
