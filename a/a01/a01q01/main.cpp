#include <iostream>

#include <iostream>
int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 1;
    std::cin >> a >> b >> c >> d >> e >> f >> g;

    // Declare your temporary variables below.
    // For instance if you need three temporary variables below you
    // should have "int t0, t1, t2;" below this line.
    int t0 = 0;
    // REPLACE WITH YOUR WORK for
    // a = a + b - c * d + e * f / g;
    a = + b;
    t0 = c * d;
    a = a - t0;
    t0 = e * f;
    t0 = t0 / g;
    a = a + t0;

    // Number of temporary variables: ___
 
    std::cout << a << ' ' << b << ' ' << c << ' '
              << d << ' ' << e << ' ' << f << ' '
              << g << std::endl;
    
    // The original values of b, c, d, e, f, g are preserved.
    
    return 0;
}