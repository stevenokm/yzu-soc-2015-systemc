// packet.h file
// Update User Defined Types to version 2.3.1
#ifndef PACKETINC
#define PACKETINC
#include <systemc.h>
class packet_type {
    public:
        long info;
        int seq;
        int retry;
    public:

        // constructor
        packet_type (long info_ = 0, int seq_ = 0, int retry_ = 0) {
            info = info_;
            seq = seq_;
            retry = retry_;
        }

        inline bool operator == (const packet_type & rhs) const {
            return (rhs.info == info && rhs.seq == seq && rhs.retry == retry);
        }

        inline packet_type& operator = (const packet_type& rhs) {
            info = rhs.info;
            seq = rhs.seq;
            retry = rhs.retry;
            return *this;
        }

        inline friend void sc_trace(sc_trace_file *tf, const packet_type & v,
                const std::string & NAME ) {
            sc_trace(tf,v.info, NAME + ".info");
            sc_trace(tf,v.seq, NAME + ".seq");
            sc_trace(tf,v.retry, NAME + ".retry");
        }

        inline friend ostream& operator << ( ostream& os,  packet_type const & v ) {
            os << "(" << v.info << "," << v.seq << "," << v.retry << ")";
            return os;
        }

};
#endif
