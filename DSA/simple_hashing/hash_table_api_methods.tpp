//INSERT
//Inserts the key-value pair in the hash table
//IT Also allows to update the key see(https://github.com/Imadarshsri/write-a-hash-table/blob/master/05-methods/README.md#update)
void hash_table::insert(const char * key, const char * value){
   ht_item *i = createNewHashTableItem(key, value);
   int attempts = 0;
   int index = get_hash(i->key, size, attempts);
   ht_item * currItem = items[index];
   while(currItem != nullptr){
      if(currItem != &HT_DELETED_ITEM){
         deleteHashTableItem(currItem);
         items[index] = i;
         return;
      }
      index = get_hash(i->key, size, attempts);
      currItem = items[index];
      attempts++;
   }
   if(index < size){
      items[index] = i;
      count++;
   }
   else{
      cout<<"key-Value :"<<i->key<<" "<<i->value<<" not inserted !! Hash Table Full\n";
   }
}
//SEARCH
//Returns the value of the key and NULL if it does not exist
char * hash_table::search(const char * key){
   int attempts = 1;
   int index = get_hash(key, size, 0);
   ht_item *currItem = items[index];
   while(currItem != nullptr){
      if(currItem != &HT_DELETED_ITEM){
         if(strcmp(currItem->key, key) == 0){
            return currItem->value;
         }
         index = get_hash(key, size, attempts);
         currItem = items[index];
         attempts++;  
      }
   }
   return NULL;
}

//DELETE 
//Delete the corresponding key-value pair from the hash table with given key
void hash_table::deleteKeyValue(const char * key){
   int attempts = 1;
   int index = get_hash(key, size, 0);
   ht_item *currItem = items[index];

   while(currItem != nullptr){
      if(strcmp(currItem->key, key) == 0){
         deleteHashTableItem(currItem);
         items[index] = &HT_DELETED_ITEM; //Creating bug
         count--;
         cout<<key<<" deleted from hash table\n";
      }
      index = get_hash(key, size, attempts);
      currItem = items[index];
      attempts++;
   }
}