#include <simpleIP4.h>


SimpleIP4::SimpleIP4(unsigned short b1,unsigned short b2,unsigned short b3,unsigned short b4)
{
    if (b1 > 255) {
          throw std::logic_error("Byte 1 value is invalid: " + std::to_string(b1));
        }
    byte1 = b1;
    if (b2 > 255) {
          throw std::logic_error("Byte 2 value is invalid: " + std::to_string(b2));
        }
    byte2 = b2;
    if (b3 > 255) {
          throw std::logic_error("Byte 3 value is invalid: " + std::to_string(b3));
        }
    byte3 = b3;
    if (b4 > 255) {
          throw std::logic_error("Byte 4 value is invalid: " + std::to_string(b4));
        }
    byte4 = b4;
}
unsigned short SimpleIP4::GetByte1() const {return byte1;}
unsigned short SimpleIP4::GetByte2() const {return byte2;}
unsigned short SimpleIP4::GetByte3() const {return byte3;}
unsigned short SimpleIP4::GetByte4() const {return byte4;}

unsigned long int SimpleIP4::Get10() const
{
    return byte4 + 256 * byte3 + 256 * 256 * byte2 + 256 * 256 * 256 * byte1;
}
bool operator<(const SimpleIP4& lhs, const SimpleIP4& rhs)
{
    return lhs.Get10() < rhs.Get10();
}

std::ostream& operator<<(std::ostream& stream, const SimpleIP4& ip)
{
 stream << ip.GetByte1() << "." << ip.GetByte2() << "." << ip.GetByte3() << "." << ip.GetByte4() ;
  return stream;
}
SimpleIP4 ParseIP4(const std::string& ipstr)
{
  std::istringstream date_stream(ipstr);
  bool ok = true;

  unsigned short b1;
  ok = ok && (date_stream >> b1);
  ok = ok && (date_stream.peek() == '.');
  date_stream.ignore(1);
  unsigned short b2;
  ok = ok && (date_stream >> b2);
  ok = ok && (date_stream.peek() == '.');
  date_stream.ignore(1);
  unsigned short b3;
  ok = ok && (date_stream >> b3);
  ok = ok && (date_stream.peek() == '.');
  date_stream.ignore(1);
  unsigned short b4;
  ok = ok && (date_stream >> b4);
  //???
 // по условиям задачи не ясно что делать если IP считали а дальнейшая строка не соответствует требуемому формату
//  ok = ok && date_stream.eof();

  if (!ok) {
    throw std::logic_error("Wrong IP format: " + ipstr);
  }
  return SimpleIP4(b1,b2,b3,b4);
}
