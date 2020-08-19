#include <iostream> 
#include <string> 

#include "hash_table.h"
using namespace std;

int main(){
   hash_table *ht = new hash_table();
   string str1 = "adarsh", str2 = "ad", str3 = "adh";
   ht->insert(str1.c_str(), "25");
   ht->insert(str2.c_str(), "26");
   ht->insert(str3.c_str(), "28");

   cout<<"Elements in ht : " <<ht->count<<"\nElements inserted are : \n";
   cout<<str1<<" : "<<ht->search(str1.c_str())<<"\n";
   cout<<str2<<" : "<<ht->search(str2.c_str())<<"\n";
   cout<<str3<<" : "<<ht->search(str3.c_str())<<"\n";


   // This section is buggy

   // ht->deleteKeyValue(str1.c_str());
   // cout<<"Elements in ht : " <<ht->count<<"\n";
   // ht->deleteKeyValue(str2.c_str());

   // cout<<"Elements in ht : " <<ht->count<<"\n";
   // ht->deleteKeyValue(str3.c_str());

   // cout<<"Elements in ht : " <<ht->count<<"\n";

   delete ht;
}
