#ifndef _IO_HPP_
#define _IO_HPP_

#include <exception>
#include <string>
#include <vector>

namespace advent
{

class ReaderException: public std::exception
{
public:
    ReaderException();
};

class Reader
{
public:
    Reader(std::string const & data_file);

    std::vector<int> get_input() const;

private:
    std::string data_file_;
};

}

#endif
