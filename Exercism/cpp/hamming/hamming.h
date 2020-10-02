#if !defined(HAMMING_H)
#define HAMMING_H
#include <string>
namespace hamming {
  std::string::size_type compute(std::string strandA,std::string strandB);
}  // namespace hamming

#endif // HAMMING_H