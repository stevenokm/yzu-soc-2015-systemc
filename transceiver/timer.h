// timer.h
#include <systemc.h>
SC_MODULE(timer)
{
    //sc_inout < bool > start;    // input port
    sc_in < bool > start;       // input port // bug fix

    sc_out < bool > timeout;    // output port
    sc_in < bool > clock;       // input port
    int count;
    void runtimer();
    // Constructor
    SC_CTOR(timer) {
        SC_THREAD(runtimer);
        // Thread process

        // Update API to version 2.3.1
        sensitive << clock.pos();

        sensitive << start;
        count = 0;
    }
};
