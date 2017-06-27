// HCTree.h
// Author: Benjamin Llanes, A13138925
// Class: CSE100, MWF 9:00AM
//
// An implmentation of the Huffman Tree used in the
// Huffman compression algorithm. Defines functionality
// for creating a tree, encoding and compressing
// messages, and decompressing and decoding messages.

#ifndef HCTREE_H
#define HCTREE_H

#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "HCNode.h"
#include "BitInputStream.h"
#include "BitOutputStream.h"

#define NONEXIST ""

using namespace std;

/** A 'function class' for use as the Compare class in a
 *  priority_queue<HCNode*>.
 *  For this to work, operator< must be defined to
 *  do the right thing on HCNodes.
 */
class HCNodePtrComp {
public:
    bool operator()(HCNode*& lhs, HCNode*& rhs) const {
        return *lhs < *rhs;
    }
};

/** A Huffman Code Tree class.
 *  Not very generic:  Use only if alphabet consists
 *  of unsigned chars.
 */
class HCTree {
private:
    HCNode* root;
    vector<HCNode*> leaves;
    vector<std::string> repr;
    int weight;

    HCNode * get_node(char c, int);

    void delete_all (HCNode * root);

    void writeNode(HCNode * root, BitOutputStream& out);

    

public:
    // explicit keyword is used to avoid accidental implicit conversions
    explicit HCTree() : root(0) {
        leaves = vector<HCNode*>(256, (HCNode*) 0);
        repr = vector<string>(256, NONEXIST); 
        repr[0] = "";
    }

    ~HCTree();

    /** Use the Huffman algorithm to build a Huffman coding trie.
     *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is
     *  the frequency of occurrence of byte i in the message.
     *  POSTCONDITION:  root points to the root of the trie,
     *  and leaves[i] points to the leaf node containing byte i.
     */
    void build(const vector<int>& freqs);

    /** Write to the given BitOutputStream
     *  the sequence of bits coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    void encode(byte symbol, BitOutputStream& out);

    /** Write to the given ofstream
     *  the sequence of bits (as ASCII) coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT
     *  BE USED IN THE FINAL SUBMISSION.
     */
    void encode(byte symbol, ofstream& out);


    /** Return symbol coded in the next sequence of bits from the stream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    int decode(BitInputStream& in) const;

    /** Return the symbol coded in the next sequence of bits (represented as
     *  ASCII text) from the ifstream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT BE USED
     *  IN THE FINAL SUBMISSION.
     */
    int decode(ifstream& in) const;

    void write(BitOutputStream& out);

    std::string toBinary(byte b);

    int decodeBinary(std::string);

    void readTree(BitInputStream& in);

    void getFromNode(BitInputStream & in, std::string rep);

    


};

#endif // HCTREE_H
