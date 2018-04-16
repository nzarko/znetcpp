//
// Created by nick on 15/4/2018.
//

#include "printer.h"

Printer::~Printer() {
    std::cout << "Final count is " << count_ << std::endl;
}

Printer::Printer(asio::io_service &io) :
    timer_(io, boost::posix_time::seconds(1)),
    count_(0)
{
    std::cout << "Entering Printer Ctor" << std::endl;
    timer_.async_wait(boost::bind(&Printer::print,this));
}

void Printer::print() {
    if (count_ < 5)
    {
        std::cout << count_ << std::endl;
        ++count_;

        timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
        timer_.async_wait(boost::bind(&Printer::print, this));
    }
}
