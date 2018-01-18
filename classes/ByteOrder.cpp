//
// Created by danter on 2018-01-18.
//


#include <iostream>
#include <netinet/in.h>

void encode(char* buf, short val) {
    uint16_t a = htons(uint16_t(val));

    auto *ptr = reinterpret_cast<char*>(&a);
    for (int i = 0; i <sizeof(short);i++ ) buf[i] = *ptr++;
}

short decode(const char* buf) {
    return ntohs(*reinterpret_cast<const uint16_t*>(buf));
}

short decode_little_endian(const char* buf) {
    return (buf[0]<<8 | buf[1]);
}

int
main (int argc , char** argv)
{
    union Order {
        short val;
        char  arr[sizeof(short)];
    };

    Order o = { 0x1234 }; // 4660 [18, 52]

    if (o.arr[0] == 0x12 && o.arr[1] == 0x34)
        std::cout << "Big Endian!" << std::endl;
    else
        std::cout << "Little Endian!" << std::endl;

    int arr[3] = {1,2,3};
    std::cout << "val:" << o.val << std::endl;

    uint16_t a = htons(0x1234);
    std::cout << "htons(0x1234):" << a << std::endl; // 13330 0x3412

    char buf[3] = {0};
    encode(buf, 0x1234); // 4660

    short de = decode_little_endian(buf);
    std::cout << "de:" << de << std::endl; // 13330 0x3412


    return 0;
}