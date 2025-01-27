#include <stdint.h>

typedef struct TcpHeader{
    short src_port;
    short dest_port;
    int seq_num;
} tcp_header_t;

typedef union PacketHeader{
    tcp_header_t tcp_header;
    unsigned char raw[8];
} packet_header_t;
