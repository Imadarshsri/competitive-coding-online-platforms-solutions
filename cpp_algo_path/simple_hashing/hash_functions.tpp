#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;
//Hash Fuction to find the index of a string s, p is a prime no. greater than 128
int hash_table::hash(const char * s, const int primeNo, const int numberOfBuckets){
   long hash = 0, len = strlen(s);
   for(int i = 0; i < len; i++){
      hash += (long)pow(primeNo, len - (i + 1)) * s[i] % numberOfBuckets;
      hash = hash % numberOfBuckets;
   }
   return (int)(hash % numberOfBuckets);
}

//Function to return hash value applying collision resolution techniques

// In case of collisions we will use 'open addressing' with 'doule hashing'.
// Double hashing makes use of two hash functions to calculate the index an item should be stored at after `i` collisions.
int hash_table::get_hash (const char* s, const int numOfBuckets, const int attempt){
   const int hashA = hash(s, HT_PRIME_1, numOfBuckets);
   const int hashB = hash(s, HT_PRIME_2, numOfBuckets);

   return (hashA + (attempt * (hashB + 1) % numOfBuckets)) % numOfBuckets;
}