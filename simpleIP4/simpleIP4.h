#pragma once
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

void hello_world();
class SimpleIP4
{
  public:
    SimpleIP4(unsigned short b1,unsigned short b2,unsigned short b3,unsigned short b4);
    unsigned long int Get10() const;
    unsigned short GetByte1() const;
    unsigned short GetByte2() const;
    unsigned short GetByte3() const;
    unsigned short GetByte4() const;
  private:
    unsigned short byte1;
    unsigned short byte2;
    unsigned short byte3;
    unsigned short byte4;
};
bool operator<(const SimpleIP4& lhs, const SimpleIP4& rhs);
std::ostream& operator<<(std::ostream& stream, const SimpleIP4& ip);
SimpleIP4 ParseIP4(const std::string& ipstr);
