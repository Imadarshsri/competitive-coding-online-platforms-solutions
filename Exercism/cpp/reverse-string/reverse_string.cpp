#include "reverse_string.h"
#include <iostream>
#include <string>

namespace reverse_string {
  std::string reverse_string(std::string str){
    return std::string(str.rbegin(), str.rend());
  //   int len = str.length();
  //   for(int i = 0; i < (len + 1)/2; i++){
  //     char a = str[i];
  //     str[i] = str[len - i - 1];
  //     str[len - i - 1] = a;
  //   }
  //   return str;
  }
}  // namespace reverse_string
