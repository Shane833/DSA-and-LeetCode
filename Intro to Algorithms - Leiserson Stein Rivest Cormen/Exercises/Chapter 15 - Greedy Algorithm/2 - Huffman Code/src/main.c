#include <stdio.h>
#include <stdlib.h>
#include <dbg.h>
#include <PQueue.h>
#include <hashmap.h>
#include <hashmap_algos.h>
#include <string.h>
#include <bstrlib.h>

typedef struct HuffmanNode HuffmanNode;

typedef struct HuffmanNode{
    size_t freq;
    unsigned char c;
    HuffmanNode *left;
    HuffmanNode *right;
}HuffmanNode;

// Destroy Callback
typedef void (*HuffmanNode_destroy_cb) (HuffmanNode *node);

HuffmanNode *createHuffmanNode(char c, size_t freq){
    HuffmanNode *temp = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    check(temp != NULL, "Failed to create HuffmanNode!");

    temp->c = c;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
error:
    return NULL;
}

// Compare function for PQueue
int keyCompare(const HuffmanNode *a, const HuffmanNode *b){
    return a->freq - b->freq;
}

PQueue *createMinHeapFromString(const char *msg){
    int map[UCHAR_MAX] = { 0 };
    for(int i = 0;i < strlen(msg);i++){
        map[msg[i]]++; // counter
    } 
    // Getting the count of unique chars
    size_t count = 0;
    for(int i = 0;i < UCHAR_MAX;i++){
        if(map[i] != 0){
            count++;
        }
    }
    // Create a new PQueue
    PQueue *q = PQueue_Create(count, (PQueue_Compare)keyCompare);
    check(q != NULL, "Failed to create PQueue!"); 
    
    // Creating a min heap from these nodes
    for(int i = 0;i < UCHAR_MAX;i++){
        if(map[i] != 0){
            HuffmanNode *node = createHuffmanNode(i, map[i]);
            check(node != NULL, "Failed to create HuffmanNode!");
            
            PQueue_Enqueue(q, node);
        }
    }

    return q;
error:
    return NULL;
}

void freeNode(HuffmanNode *node){
    if(node){
        free(node);
    }
}

// I can destroy the nodes in post order
// so that the child are freed first and then
// their parents
void Huffman_Destroy(HuffmanNode *node, HuffmanNode_destroy_cb destroy){
    if(!node) return;

    Huffman_Destroy(node->left, destroy);
    Huffman_Destroy(node->right, destroy);
    
    destroy(node);
}

HuffmanNode *Huffman(PQueue *q){
    size_t n = PQueue_Size(q);
    // for n items we need n - 1 merge operations 
    for(int i = 0;i < n - 1;i++){
        HuffmanNode *node = createHuffmanNode('\0', 0);
        check(node != NULL, "Failed to create HuffmanNode!");

        HuffmanNode *a = (HuffmanNode *)PQueue_Dequeue(q);
        HuffmanNode *b = (HuffmanNode *)PQueue_Dequeue(q);

        node->left = a;
        node->right = b;

        node->freq = a->freq + b->freq;

        PQueue_Enqueue(q, node); // Merging two smallest nodes at a time
                                 // and inserting them back into the min heap
    }

    return (HuffmanNode *)PQueue_Dequeue(q); // in the end only the root remains
error:
    return NULL;
}

void preOrder(HuffmanNode *node, bstring code){
    if(node == NULL) return;

    if(!node->left && !node->right){ // Stopping at the leaves
        struct tagbstring test = bsStatic(""); // allocating on the stack
        if(bstrcmp(code, &test) == 0){
            bconchar(code, '0');
        } 
        printf("%s: %c\n", bdata(code), node->c);
    }
    
    bstring code_l = bstrcpy(code);
    bconchar(code_l, '0'); // concatenating 0 for every left branch

    preOrder(node->left, code_l);
    
    bdestroy(code_l);
    code_l = NULL;

    bstring code_r = bstrcpy(code);
    bconchar(code_r, '1'); // concatenating 1 for every right branch
    
    preOrder(node->right, code_r);

    bdestroy(code_r);
    code_r = NULL;
}



int main(){
    // Create the initial min heap of huffman nodes
    PQueue *q = createMinHeapFromString("aabbbcdeee");
    check(q != NULL, "Failed to create Min Heap from given String!");

    // Generating the huffman tree
    HuffmanNode *root = Huffman(q);
    check(root != NULL, "Failed to create Huffman Tree!");

    // Displaying codes for each character
    bstring code = bfromcstr("");
    check(code != NULL, "Failed to create our initial code string!");
    preOrder(root, code);
    
    // Cleanup
    bdestroy(code);
    code = NULL;
    
    PQueue_ClearDestroy(q);
    q = NULL;

    Huffman_Destroy(root, (HuffmanNode_destroy_cb)freeNode);
    root = NULL;

    return 0;
error:
    return EXIT_FAILURE;
}
