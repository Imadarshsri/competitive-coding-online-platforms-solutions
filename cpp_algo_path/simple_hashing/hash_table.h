#include <iostream>
#include <cstring>

using namespace std;

//Hash Table Item
typedef struct{
   char* key;
   char* value;
} ht_item;

//Hash Table
class hash_table {
   public:
      int size;
      int count;
      ht_item ** items;
      //Constructor
      hash_table(int sz);
      ~hash_table();

   private:
      //Method to insert items
      ht_item *insertItem(const char * k, const char * v);
      void deleteItem(ht_item * i);
      //iF NEEDED TRY TO INITIALIZE DECONSTRUCTOR
};
#include "hash_table_methods.tpp"
#include "hash_functions.tpp"