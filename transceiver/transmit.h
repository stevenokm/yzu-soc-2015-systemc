//Transmit.h
#include "packet.h"
SC_MODULE(transmit)
{
    sc_in < packet_type > tpackin;      // input port
    sc_in < bool > timeout;             // input port
    sc_out < packet_type > tpackout;    // output port

    //sc_inout < bool > start_timer;      // output port
    sc_out < bool > start_timer;        // output port // bug fix

    sc_in < bool > clock;
    int buffer;
    int framenum;
    packet_type packin, tpackold;
    packet_type s;
    int retry;
    bool start;
    void send_data();
    int get_data_fromApp();
    // Constructor
    SC_CTOR(transmit) {
        SC_METHOD(send_data);
        // Method Process
        sensitive << timeout;

        // Update API to version 2.3.1
        sensitive << clock.pos();

        // initializing variables
        framenum = 1;
        retry = 0;
        start = false;
        buffer = get_data_fromApp();
    }
};
