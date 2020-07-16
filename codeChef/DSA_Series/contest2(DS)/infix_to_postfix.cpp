#include<bits/stdc++.h>
using namespace std;

int precedence(char c){
  if( c =='+'|| c=='-') return  1 ;
  else if( c =='*'|| c=='/') return  2 ;
  else if( c=='^') return  3 ;
  else return -1;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--){
    int length;
    cin >> length;
    string str = "(", str1;
    cin >> str1;
    str += str1;
    str += ")";
    stack<char> stk;
    for( int i = 0; i < str.length(); i++ ){
      if( str[i]>=65 && str[i]<91 ) {
        // cout << "\nck - 1\tSP -- "<<stk.top()<<"\n";
        cout << str[i];
      }
      else if( str[i]=='(' ) {
        // cout << "\nck - 2\tSP -- "<<stk.top()<<"\n";
        stk.push(str[i]);
      } 
      else if( !stk.empty() && str[i] ==')' ) {
        
        // cout << "\nck - 3\tSP -- "<<stk.top()<<"\n";
        while(stk.top() !='(') {
          cout << stk.top();
          stk.pop();
        }
        stk.pop();
      }
      else{
        while( !stk.empty() && precedence(stk.top()) >= precedence(str[i]) ) {
          // cout << "\nck - 4\tSP -- "<<stk.top()<<"\n";
          cout << stk.top();
          stk.pop();
        }
        stk.push(str[i]);
      }
    }
    while(!stk.empty()) {
      
        // cout << "\nck - 5\tSP -- "<<stk.top()<<"\n";  
      cout << stk.top();
      stk.pop();
    }
    cout<<"\n";
  }
  return 0;
}