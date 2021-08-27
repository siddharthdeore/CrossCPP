#include <boost/chrono.hpp>
#include <iostream>

using namespace boost::chrono;

using namespace std;
typedef std::chrono::high_resolution_clock Clock;

int main()
{
    std::cout << system_clock::now() << '\n';
    int iIdx = 0;
    bool bRun = true;

    auto aTimeStart = Clock::now();

    while (bRun){
        iIdx++;
        if (iIdx >= 500) bRun = false;

        //Sleep(1);
        this_thread::sleep_for(chrono::microseconds(10));
    }

    printf("Duration: %i ms\n", chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - aTimeStart).count());

    cin.get();

    return 0;
}