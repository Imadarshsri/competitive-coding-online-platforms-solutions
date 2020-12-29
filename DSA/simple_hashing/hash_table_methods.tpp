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
