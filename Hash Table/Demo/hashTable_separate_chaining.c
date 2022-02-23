/*
 * Hash table test demo using separate chaining method
 * Author: XiaoFang Qi
 * Date: 2022/2/23
 */

#include "main.h"

extern struct dataItem* hashArray[SIZE];

// search Item by key
struct dataItem* sc_searchNode(int key)
{
    int hashIndex = hashCode(key);
    struct dataItem* temp = hashArray[hashIndex];
    while(temp != NULL)
    {
        if(temp->key == key)
        {
            return temp;
        } else {
            if(temp->next != NULL)
            {
                temp = temp->next;
            }else {
                return NULL;
            }
        }
    }
    return NULL;
}

// insert Item operation
int sc_insertNode(struct dataItem* item)
{
    if(item == NULL)
        return false;

    int hashIndex = hashCode(item->key);
    struct dataItem* temp = hashArray[hashIndex];
    struct dataItem* preTemp = temp;
    while(temp != NULL)
    {
        preTemp = temp;
        temp = temp->next;
    }
    if(preTemp == NULL)
    {
        hashArray[hashIndex] = (struct dataItem*)malloc(sizeof(struct dataItem));
        hashArray[hashIndex]->key = item->key;
        hashArray[hashIndex]->value = item->value;
        hashArray[hashIndex]->next = NULL;
        return true;
    }
    preTemp->next = (struct dataItem*)malloc(sizeof(struct dataItem));
    preTemp->next->key = item->key;
    preTemp->next->value = item->value;
    preTemp->next->next = NULL;
    return true;
}

// delete Item operation
struct dataItem* sc_deleteNode(struct dataItem* item)
{
    int hashIndex = hashCode(item->key);
    struct dataItem* temp = hashArray[hashIndex];
    struct dataItem* preTemp = temp;
    while(temp->key != item->key)
    {
        if(temp->next != NULL){
            preTemp = temp;
            temp = temp->next;
        }else {
            return false;
        }
    }
    // delete the linked node
    if(temp->next != NULL)
    {
        if(preTemp != temp)
        {
            preTemp->next = temp->next;
        } else {
            hashArray[hashIndex] = temp->next;
        }
    } else {
        preTemp->next = NULL;
    }
    
    return temp;
}