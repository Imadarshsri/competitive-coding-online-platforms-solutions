#include <iostream> 
#include "hash_table.h"
using namespace std;

int main(){
   hash_table *ht = new hash_table(20);
   delete ht;
}
