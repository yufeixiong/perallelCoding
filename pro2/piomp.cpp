#include <iostream>
#include <stdlib.h>
#include <omp.h>
using namespace std;
const long long int cyl = 100000000;

int main(int argc, char const *argv[])
{
    double x, y, dis;
    long long int incly = 0;
	#pragma omp parallel for private(x, y, dis) reduction(+:incly)

    for (long long int i = 0; i < cyl; ++i)
    {
        unsigned int seed = 1234 + 17*omp_get_thread_num();
        x = (double)rand_r(&seed)/(double)RAND_MAX;
        y = (double)rand_r(&seed)/(double)RAND_MAX;
        dis = x * x + y * y ;
        // cout << x << endl;
        if(dis < 1.0)
            incly++;
    }
    double pi = (double)incly / cyl * 4.0;
    cout << pi << endl;
    return 0;
}
