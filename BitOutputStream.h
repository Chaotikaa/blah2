// BitOutputStream.h
// Author: Benjamin Llanes, A13138925
// Class: CSE100, MWF 9:00AM
//
// A class that delegates to std::ostream while
// adding bitwise output functionality.
// Implements outline provided in class, Lecture 15
#include <iostream>

#ifndef BITOUTPUTSTREAM_H
#define BITOUTPUTSTREAM_H

#define FULL_BUFFER 8

class BitOutputStream {
private: 
  char buf;
  int nbits;
  std::ostream & out;

public:

  BitOutputStream(std::ostream & os) : out(os), buf(0), nbits(0) {
    buf = nbits = 0;
  }

  void flush();

  void writeBit(int);

};

#endif
