#include <iostream>
#include <cstring>

using namespace std;

//Hash Table Item
typedef struct{
   char* key;
   char* value;
} ht_item;

static ht_item HT_DELETED_ITEM = (ht_item){NULL, NULL};

//Hash Table
class hash_table {
   public:
      //Attributes

      //Size of hash Table
      int size;
      //No. of elements in hash table
      int count;
      //hash table with key-value pairs
      ht_item ** items;
      
      //Identifier for marking deleted bucket item
      //Constructor 
      //This will initialize the hash table with size `sz`. Default size is 53.
      hash_table(int sz);

      //Deconstructor to destroy the object of hash table
      ~hash_table();

      //Function to return hash value applying collision resolution techniques
      // In case of collisions we will use 'open addressing' with 'doule hashing'.
      // Double hashing makes use of two hash functions to calculate the index an item should be stored at after `i` collisions.
      int get_hash(const char* s, const int numBuckets, const int attempt);
      
      //API Methods
      void insert(const char * key, const char * value);
      char* search(const char* key);
      void deleteKeyValue(const char* key);
   private:
      //Prime Number to be used in hash function
      int HT_PRIME_1;
      //Prime Number to be used in case of collisions
      int HT_PRIME_2;

      //Method to insert items with key `k` and value `v`
      ht_item *createNewHashTableItem(const char * k, const char * v);

      //Method to delete a ht_item 'i'
      void deleteHashTableItem(ht_item * i);

      //Hash Fuction to find the index of a string s, p is a prime no. greater than 128
      int hash(const char * s, const int primeNo, const int numberOfBuckets);
};

//File containing constructor, deconstructor and methods for inserting and deleting items
#include "hash_table_methods.tpp"

//File containing hash table api methods
#include "hash_table_api_methods.tpp"

//File containing hash function and collision avoiding function
#include "hash_functions.tpp"