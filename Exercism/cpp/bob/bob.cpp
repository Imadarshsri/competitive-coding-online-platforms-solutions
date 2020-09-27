#include "bob.h"
#include <iostream>
#include <string>

namespace bob {

  std::string formatString(std::string msg, int __cdecl func(int)){
    std::string fMsg = "";
    for(auto c : msg)
      if(!func(c))
        fMsg += c;
    return fMsg;
  }
  std::string hey(const std::string& msg){
    std::string fMsg = formatString(msg, std::isspace);

    if(fMsg.empty())
      return "Fine. Be that way!";

    if(fMsg.back() == '?'){
      fMsg = fMsg.substr(0, fMsg.length()-1);

      //Check whether string contains only upppercase letters or not
      int flag = 1;
      for(auto c : fMsg) 
        if(!std::isupper(c)){ 
          flag = 0;
          break;
        }
      //Reply to question
      if(flag == 0)
        return "Sure.";
      else // Reply to question which was yelled
        return "Calm down, I know what I'm doing!";
    }
  
    // Remove unecessary characters and include only alphabets
    std::string newMsg = "";
    for(auto c : fMsg) 
      if(std::isalpha(c)) 
        newMsg += c;
    fMsg = newMsg;

    //Check whether string contains only upppercase letters or not
    int flag = 1;
    for(auto c : fMsg) 
      if(!std::isupper(c)){ 
        flag = 0;
        break;
      }
    //Reply to yell
    if(!fMsg.empty() && flag == 1)
      return "Whoa, chill out!";
    else //Reply to anything else
      return "Whatever.";
  }
}  // namespace bob
