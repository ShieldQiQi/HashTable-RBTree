/*
 * Hash table test demo main.c
 * Author: XiaoFang Qi
 * Date: 2022/2/23
 */

#include "main.h"
#include "hashTable_separate_chaining.h"
#include "hashTable_linear_probing.h"

// the Items to insert to hash table
struct dataItem Items[9] = {{1, 20}, {2, 70}, {42, 80}, {4, 25}, {12, 44}, {14, 32}, {17, 11}, {13, 78}, {37, 98}};

int main()
{
    printf("\n--------------------------------");
    printf("\nThis is a demo for hash table.");
    printf("\n--------------------------------\n\n");

    // insert Items
    for(int i=0; i<9; i++)
    {
        if(!sc_insertNode(&Items[i]))
        {
            printf("test insert function failed. return code -1.\n");
            return -1;
        }
    }

    // search one certain item
    if(sc_searchNode(17) == NULL || sc_searchNode(37)->value != 98)
    {
        printf("test search function failed. return code -2.\n");
        return -2;
    }

    // test delete one certain item
    sc_deleteNode(&Items[8]);
    if(sc_searchNode(Items[8].key) != NULL)
    {
        printf("test delete function failed. return code -3.\n");
        return -3;
    }

    printf("\n--------------------------------\n");
    printf("test finished successfully!");
    printf("\n--------------------------------\n");
    return 0;
}