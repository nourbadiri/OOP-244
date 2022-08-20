
#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>
namespace sdds {
    class Streamable{
public:
    virtual std::ostream& write(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& istr) = 0;
    virtual bool conIO(const std::ios& io) const = 0;
    virtual operator bool()const = 0;
    virtual ~Streamable() {};
};
std::ostream& operator<<(std::ostream& os, const Streamable& st);
std::istream& operator>>(std::istream& istr, Streamable& st);
}
#endif