#include "transmit.h"
int transmit::get_data_fromApp()
{
    int result;
    result = rand();
    cout << "Generate:Sending Data Value =" << result << "\n";
    return result;
}

void transmit::send_data()
{
    if (timeout) {
        s.info = buffer;
        s.seq = framenum;
        s.retry = retry;
        retry++;
        tpackout = s;
        start_timer = true;
        cout << "Transmit:Sending packet no." << s.seq << "\n";
    } else {
        packin = tpackin;
        if (!(packin == tpackold)) {
            if (packin.seq == framenum) {
                buffer = get_data_fromApp();
                framenum++;
                retry = 0;
            }
            tpackold = tpackin;
            s.info = buffer;
            s.seq = framenum;
            s.retry = retry;
            retry++;
            tpackout = s;
            start_timer = true;
            cout << "Transmit:Sending packet no. " << s.seq << "\n";

        // bug fix
        } else {
            start_timer = false;

        }
    }
}
