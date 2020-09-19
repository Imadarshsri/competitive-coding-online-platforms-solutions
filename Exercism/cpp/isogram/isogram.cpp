#include "isogram.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

namespace isogram {
  bool is_isogram(string str){
    if(str == "") return true;
    map <char, int> charCount;
    for(auto c : str){
      if(c >= 'A' && c <= 'Z') c = 'a' + (c - 'A');
      if(charCount.find(c) == charCount.end()) charCount[c]++;
      else if(isalpha(c) != 0 && charCount[c] == 1) return false;
    }
    return true;
  }
}  // namespace isogram
