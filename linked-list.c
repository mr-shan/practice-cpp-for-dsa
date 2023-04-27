#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// creata a new node 
struct Node* createNode(int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// append a new node with given data into existing list
void addNewNode(struct Node *list, int data)
{
    struct Node *tail = list;
    
    while (tail->next != NULL)
        tail = tail->next;
    
    tail->next = createNode(data);
}

// print the linked list
void printList(struct Node *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
}

// get number of nodes present in linked list
int count(struct Node *list)
{
    int counter = 0;
    while (list != NULL)
    {
        counter++;
        list = list->next;
    }
    return counter;
}

// sum of all elements in a list
int sum(struct Node *list)
{
    int sum = 0;
    while (list != NULL)
    {
        sum += list->data;
        list = list->next;
    }
    return sum;
}

int max(struct Node *list)
{
    int max = list == NULL ? 0 : list->data;
    
    while(list != NULL)
    {
        max = list->data > max ? list->data : max;
        list = list->next;
    }
    return max;
}

int min(struct Node *list)
{
    int min = list == NULL ? 0 : list->data;
    
    while(list != NULL)
    {
        min = list->data < min ? list->data : min;
        list = list->next;
    }
    return min;
}

struct Node * search(struct Node *list, int key)
{
    while (list != NULL)
    {
        if (list->data == key) return list;
        list = list->next;
    }
    return NULL;
}

// recursive version of normal functions
void rPrintList(struct Node *list)
{
    if (list == NULL) return;
    printf("%d, ", list->data);
    rPrintList(list->next);
}

int rCount(struct Node *list)
{
    if (list == NULL) return 0;
    return rCount(list->next) + 1;
}

int rSum(struct Node *list)
{
    if (list == NULL) return 0;
    return rSum(list -> next) + list -> data;
}

struct Node* rSearch(struct Node *list, int key)
{
    if (list == NULL) return NULL;
    
    if (list->data == key) return list;
    return rSearch(list->next, key);
}

int main()
{
    struct Node *list = createNode(1);
    addNewNode(list, 2);
    addNewNode(list, 3);
    addNewNode(list, 4);
    addNewNode(list, 5);
    addNewNode(list, 6);

    printList(list);
    
    addNewNode(list, 7);
    addNewNode(list, 8);
    addNewNode(list, 9);
    printf("\n\n");
    rPrintList(list);
    
    printf("\n\n");
    
    printf("Total elements in list: %d\n", rCount(list));
    printf("Sum of all elements in list: %d\n", sum(list));
    printf("Max of all elements in list: %d\n", max(list));
    printf("Min of all elements in list: %d\n", min(list));
    
    int elementToSearch = 11;
    struct Node *searchResult = rSearch(list, elementToSearch);
    if (searchResult)
        printf("%d found.\n", elementToSearch);
    else
        printf("No %d found.\n", elementToSearch);
    
    free(list);
    return 0;
}
