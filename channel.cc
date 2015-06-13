// channel.cc
#include "channel.h"
void channel::receive_data()
{
    int i;
    packin = tpackin;
    cout << "Channel:Received packet seq no. = " << packin.seq << "\n";
    i = rand();
    packout = packin;
    cout << "Channel: Random number = " << i << endl;
    if ((i > 1000) && (i < 5000)) {
        packout.seq = 0;
    }   // Generating noise
    rpackout = packout;
}

void channel::send_ack()
{
    int i;
    ackin = rpackin;
    cout << "Channel:Received Ack for packet= " << ackin.seq << "\n";
    i = rand();
    ackout = ackin;
    if ((i > 10) && (i < 500)) {
        ackout.seq = 0;
    }
    tpackout = ackout;
}
