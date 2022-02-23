#ifndef HASHTABLE_LINEAR_PROBING_H_
#define HASHTABLE_LINEAR_PROBING_H_


// search operation
struct dataItem* lp_searchNode(int key);

// insert operation
int lp_insertNode(struct dataItem* item);

// delete operation
struct dataItem* lp_deleteNode(struct dataItem* item);

#endif /* HASHTABLE_LINEAR_PROBING_H_ */