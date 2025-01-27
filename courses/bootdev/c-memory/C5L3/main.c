#include "exercise.h"
#include <stdio.h>

int main() {
    packet_header_t header;
    header.tcp_header.src_port = 0x1234;
    header.tcp_header.dest_port = 0x5678;
    header.tcp_header.seq_num = 0x9ABCDEF0;

    if (header.tcp_header.src_port == 0x1234 && header.tcp_header.dest_port == 0x5678 && header.tcp_header.seq_num == 0x9ABCDEF0) {
        printf("Correct struct values\n");
    } else {
        printf("Incorrect struct values\n");
    }

    if (header.raw[0] == 0x34 && header.raw[3] == 0x56 && header.raw[6] == 0xBC) {
        printf("Correct raw values\n");
    } else {
        printf("Incorrect raw values\n");
    }
}
