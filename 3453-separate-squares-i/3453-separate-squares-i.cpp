class Solution {
public:
    const double dx = 1e-5;
    double getSurface(vector<vector<int>>& squares, double h) {
        double s = 0;
        for (auto& x : squares) {
            if ((x[1] + x[2]) <= h) {
                s += (1.0 * x[2] * x[2]);
            } else if (h > x[1]) {
                double c = h - x[1];
                s += (1.0 * (h - x[1]) * x[2]);
            }
        }

        return s;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double surface = 0;
        for (auto& x : squares) {
            surface += (1.0 * x[2] * x[2]);
        }
        double halfSurface = (double)surface / 2;
        double l = 0;
        double r = 2e9;
        while (l < r) {
            double m = (double)(r + l) / 2;
            double surface = getSurface(squares, m);
            if (abs(surface - halfSurface) < dx) {
                r = m - dx;
                continue;
            }
            if (surface > halfSurface) {
                r = m - dx;
            } else {
                l = m + dx;
            }
        }
        return l;
    }
};