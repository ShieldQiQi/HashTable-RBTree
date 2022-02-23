/*
 * Hash table test demo using linear-probing method
 * Author: XiaoFang Qi
 * Date: 2022/2/22
 */

#include "main.h"

struct dataItem* hashArray[SIZE];

// search operation
struct dataItem* lp_searchNode(int key)
{
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->key == key)
        {
            // if the dataItem's key match, then return result
            return hashArray[hashIndex];
        }
        // wrap around the SIZE of hash table
        ++hashIndex;
        hashIndex %=SIZE;
        // if no dataItem matchs then return NULL
        if(hashIndex == hashCode(key))
        {
            return NULL;
        }
    }
    return NULL;
}

// insert operation
int lp_insertNode(struct dataItem* item)
{
    if(item == NULL)
        return false;

    int hashIndex = hashCode(item->key);
    do
    {
        if(hashArray[hashIndex] == NULL)
        {
            hashArray[hashIndex] = (struct dataItem*)malloc(sizeof(struct dataItem));
            hashArray[hashIndex]->value = item->value;
            hashArray[hashIndex]->key = item->key;
            return true;
        }
        hashIndex++;
        hashIndex %= SIZE;
    }while(hashIndex != hashCode(item->key));

    return false;
}

// delete operation
struct dataItem* lp_deleteNode(struct dataItem* item)
{
    if(item == NULL)
        return false;

    int hashIndex = hashCode(item->key);
    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->key == item->key)
        {
            struct dataItem* temp = hashArray[hashIndex];
            hashArray[hashIndex] = NULL;
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;
        if(hashIndex == hashCode(item->key))
        {
            return NULL;
        }
    }
}