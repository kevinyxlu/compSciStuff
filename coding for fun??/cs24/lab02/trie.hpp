#ifndef TRIE_HPP_
#define TRIE_HPP_

#include <array>
#include <vector>
#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26

struct Trie{
    //VARS
    bool end_of_word = false;
    array<Trie*,ALPHABET_SIZE> roots;

    Trie();
    Trie(Trie const& other);
    //The copy constructor that copies ‘other’ into ‘this’;
    ~Trie();

    Trie& operator=(Trie const& other);

    void insert(char const* const str);
    bool check(char const* const str) const;
    char* firstWithPrefix(char const* const str, unsigned depth=0) const;
};

Trie load_trie(std::istream& is);
Trie load_trie(std::string filename);

#endif //TRIE_HPP_
