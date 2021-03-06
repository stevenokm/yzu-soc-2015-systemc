#include "packet.h"     // receiver.h
SC_MODULE(receiver)
{
    sc_in < packet_type > rpackin;      // input port
    sc_out < packet_type > rpackout;    // output port
    sc_out < long >dout;                // output port
    sc_in < bool > rclk;
    int framenum;
    packet_type packin, packold;
    packet_type s;
    int retry;
    void receive_data();
    // Constructor
    SC_CTOR(receiver) {
        SC_METHOD(receive_data);    // Method Process

        // Update API to version 2.3.1
        sensitive << rclk.pos();

        framenum = 1;
        retry = 1;
    }
};
