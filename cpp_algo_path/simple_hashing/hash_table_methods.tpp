//Constructor 
//This will initialize the hash table with size `sz`. Default size is 53.
hash_table::hash_table(int sz = 53){ 
   count = 0;
   size = sz;
   HT_PRIME_1 = 151;
   HT_PRIME_2 = 163;

   // cout<<"Constructor of hash table : ";
   items = (ht_item **)calloc(size, (sizeof(ht_item *)));
   // cout<<"object created\n";
}
//Deconstructor to destroy the object of hash table
hash_table::~hash_table(){ 
   cout<<"Deleting Table\n";
   for(int i = 0; i < size; i++){
      ht_item * x = items[i];
      cout<<"Deleting item called\n";
      deleteHashTableItem(x);
   }
   // free(items);
   cout<<"Table deleted\n";
}

//Method to insert items with key `k` and value `v`
ht_item *  hash_table::createNewHashTableItem(const char * k, const char * v){
   ht_item *i = (ht_item *)malloc(sizeof(ht_item));
   i->key = strdup(k);
   i-> value = strdup(v);
   return i;
}

//Method to delete a ht_item 'i'
void hash_table::deleteHashTableItem(ht_item * i){
   if(i == nullptr || i == NULL || i == &HT_DELETED_ITEM) {
      free(i);
      cout<<"Deleting Null Item\n";
      return;
   }
   cout<<"Deleting item "<<i->key<<"\n";
   free(i->key);
   free(i->value);
   free(i);
   cout<<"Item deleted\n";
}

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