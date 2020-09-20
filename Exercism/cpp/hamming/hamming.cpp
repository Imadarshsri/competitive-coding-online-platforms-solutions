#include "hamming.h"
#include <iostream>
#include <string> 
using namespace std;
namespace hamming {
  int compute(const string strandA, const string strandB){
    int diff = 0;
    int n = strandA.length(), m = strandB.length();

    if(n != m){
       throw domain_error("DNA strands' length is not same!!");
       return -1;
    }

    for(int i = 0; i < n ; i++){
      if(strandA[i] != strandB[i]) diff++;
    }
    return diff;
  }

}  // namespace hamming
