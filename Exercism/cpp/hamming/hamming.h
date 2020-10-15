#if !defined(HAMMING_H)
#define HAMMING_H
#include <string>
namespace hamming {
  std::string::size_type compute(const std::string& strandA,const std::string& strandB);
}  // namespace hamming

#endif // HAMMING_H