#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <vector>
namespace anagram {
  class anagram{
    const std::string key;
    public :
      //Parameterized Constructor
      anagram(const std::string& x);
      // Function for checking anagram of the key
      std::vector <std::string> matches(const std::vector <std::string>& list);
  };
}  // namespace anagram

#endif // ANAGRAM_H