// timer.cc
#include "timer.h"
void timer::runtimer()
{
    while (true) {
        if (start) {
            cout << "Timer: timer start detected" << endl;
            count = 5;      // need to make this a constant
            timeout = false;

            //start = false; // bug fix

        } else {
            if (count > 0) {
                count--;
                timeout = false;
            } else {
                timeout = true;
            }
        }
        wait();
    }
}
