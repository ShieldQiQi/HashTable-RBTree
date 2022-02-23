#ifndef HASHTABLE_SEPARATE_CHAINING_H_
#define HASHTABLE_SEPARATE_CHAINING_H_

// search operation
struct dataItem* sc_searchNode(int key);

// insert operation
int sc_insertNode(struct dataItem* item);

// delete operation
struct dataItem* sc_deleteNode(struct dataItem* item);

#endif /* HASHTABLE_SEPARATE_CHAINING_H_ */