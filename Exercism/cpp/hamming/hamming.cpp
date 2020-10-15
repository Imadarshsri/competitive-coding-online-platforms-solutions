#include "hamming.h"
#include <iostream>
#include <string> 
using namespace std;
namespace hamming {
  std::string::size_type compute(const std::string& strandA, const std::string& strandB){
    std::string::size_type diff = 0;
    std::string::size_type n = strandA.length(), m = strandB.length();

    if(n != m){
       throw domain_error("DNA strands' length do not match!!");
    }

    for(std::string::size_type i = 0; i < n ; i++){
      if(strandA[i] != strandB[i]) diff++;
    }
    return diff;
  }

}  // namespace hamming
