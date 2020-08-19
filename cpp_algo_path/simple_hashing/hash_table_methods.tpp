//Constructor 
//This will initialize the hash table with size `sz`. Default size is 53.
hash_table::hash_table(int sz = 53){ 
   count = 0;
   size = sz;
   // cout<<"Constructor of hash table : ";
   items = (ht_item **)calloc(size, (sizeof(ht_item *)));
   // cout<<"object created\n";
}
//Deconstructor to destroy the object of hash table
hash_table::~hash_table(){ 
   for(int i = 0; i < size; i++){
      ht_item * x = items[i];
      deleteItem(x);
   }
   free(items);
   // cout<<"Table deleted\n";
}

//Method to insert items
ht_item *  hash_table::insertItem(const char * k, const char * v){
   ht_item *i = (ht_item *)malloc(sizeof(ht_item));
   i->key = strdup(k);
   i-> value = strdup(v);
   return i;
}

//Method to delete an item with key 'k' or ht_item 'i'
void hash_table::deleteItem(ht_item * i){
   if(i == nullptr) {
      free(i);
      // cout<<"Deleting Null Item\n";
      return;
   }
   free(i->key);
   free(i->value);
   free(i);
   // cout<<"Item deleted\n";
}
