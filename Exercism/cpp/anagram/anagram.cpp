#include "anagram.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
namespace anagram {
    //Parameterized Constructor
    anagram::anagram(const std::string& x) : key{x} {}
    // Function for checking anagram of the key
    std::vector <std::string> anagram::matches(const std::vector <std::string>& list){
      std::map<char,int> keyCount;
      std::vector <std::string> ans;
      //Converting key to lowercase and storing in str2
      std::string str2 = "";
      for(auto c : key) str2 += std::tolower(c);
      
      //Store hashmap for key
      for(const auto &x : key) keyCount[std::tolower(x)]++;

      //Validationg anagram for each string in list
      for(const auto x : list){
        //Converting x->string to lowercase and storng in str
        std::string str = "";
        for(auto c : x) str += std::tolower(c);
        //Skipping checks if length of string does not match with key or string == key
        if(str.length() != key.length() || str == str2) continue;

        std::map <char,int> check = keyCount;
        //Check individual use of each character of string from list is equal to key's character or not
        for(const auto &c : str){
          if(check.find(std::tolower(c)) != check.end()){
            check[std::tolower(c)]--;
            if(check[std::tolower(c)] == 0) check.erase(std::tolower(c));
          }
          else{
            check[std::tolower(c)]++;
          }
          
        }
        // Add this string to ans if character use ids similar of string and key
        if(check.empty()) ans.push_back(x);
        check.clear();
      }
      // Return Ans
      return ans;
    }
}  // namespace anagram
