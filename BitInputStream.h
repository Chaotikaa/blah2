// BitInputStream.h
// Author: Benjamin Llanes, A13138925
// Class: CSE100, MWF 9:00AM
// 
// A class that delegates to std::istream while
// adding bitwise input functionality.
// Implements outline provided in class, Lecture 15
#include <iostream>
#ifndef BITINPUTSTREAM_H
#define BITINPUTSTREAM_H

class BitInputStream {
private:
  char buf;
  int nbits;
  std::istream & in;
public:

  BitInputStream(std::istream & is) : in(is) {
    buf = 0;
    nbits = 8;
  }

  void fill();

  int readBit();

};

#endif