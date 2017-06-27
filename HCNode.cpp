// HCNode.cpp
// Author: Benjamin Llanes, A13138925
// Class: CSE100, MWF 9:00AM
//
// A container class to represent a character and its
// frequency in the construction of a Huffman tree,
// according to the Huffman Compression algorithm.
#include "HCNode.h"

bool HCNode::operator<(const HCNode& other) {
  if (count != other.count) return count > other.count;

  return symbol < other.symbol;
}
