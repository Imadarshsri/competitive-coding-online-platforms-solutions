#include "leap.h"

namespace leap {
  bool is_leap_year(const int year){
    if(year % 100 == 0 && year % 400 == 0) return true;
    else if(year % 100 != 0 && year % 4 == 0) return true;
    else return false;
  }
}  // namespace leap
