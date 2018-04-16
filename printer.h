//
// Created by nick on 15/4/2018.
//

#ifndef NETWORK_INTRO_2_PRINTER_H
#define NETWORK_INTRO_2_PRINTER_H

#include "global.h"

class Printer {
private:
asio::deadline_timer timer_;
int count_;
public:
    Printer(asio::io_service &io);
    ~Printer();

    void print();

};


#endif //NETWORK_INTRO_2_PRINTER_H
