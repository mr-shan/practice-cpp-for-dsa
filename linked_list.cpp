#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    private:
    Node *head;
    Node *tail;
    int count;
    
    public:
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->count = 0;
    }
    
    LinkedList(int *arr, int length)
    {
        this->head = NULL;
        this->tail = NULL;
        this->count = 0;
        for(int i = 0; i < length; ++i)
            this->push(arr[i]);
    }
    
    Node * getHead()
    {
        return this->head;
    }
    
    int getCount()
    {
        return this->count;
    }
    
    Node *getTail()
    {
        return this->tail;
    }
    
    void push(int data)
    {
        Node *n = new Node;
        n->data = data;
        n->next = NULL;
        
        if (this->count == 0)
        {
            this->head = n;
            this->tail = n;
            this->count = 1;
        }
        else
        {
            this->tail->next = n;
            this->tail = n;
            this->count++;
        }
    }
    
    int pop()
    {
        if (this->count == 0)
            return -1;

        int temp;
        if (this->count == 1)
        {
            temp = this->head->data;
            free(this->head);
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            Node *nodeToRemove = this->head->next;
            Node *newTail = this->head;
            
            while(nodeToRemove->next != NULL)
            {
                newTail = nodeToRemove;
                nodeToRemove = nodeToRemove->next;
            }
            
            temp = this->tail->data;
            free(this->tail);
            newTail->next = NULL;
            this->tail = newTail;
        }
        this->count--;
        return temp;
    }
    
    int pop2()
    {
        if (this->count == 0)
            return -1;

        int temp;
        if (this->count == 1)
        {
            temp = this->head->data;
            free(this->head);
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            Node *newTail = this->head;
            int ctr = 0;
            
            while(++ctr < this->count - 1)
                newTail = newTail->next;
            
            temp = this->tail->data;
            free(this->tail);
            newTail->next = NULL;
            this->tail = newTail;
        }
        this->count--;
        return temp;
    }
    
    int insert(int data, int position)
    {
        if (position < 1 || position > this->count + 1) return -1;

        Node *ptr = this->head;
        Node *prevPtr = NULL;
        
        for(int i = 1; i < position; ++i)
        {
            prevPtr = ptr;
            ptr = ptr->next;
        }
        
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = ptr;
        
        if(prevPtr == NULL)
            this->head = newNode;
        else
            prevPtr->next = newNode;
            
        if (ptr == NULL)
            this->tail = newNode;
        
        this->count++;
        return data;
    }
    
    int sortedInsert(int data)
    {
        int position = 1;
        Node *ptr = this->head;
        Node *prevPtr = NULL;
        
        while (ptr && data > ptr->data && position <= this->count)
        {
            prevPtr = ptr;
            ptr = ptr->next;
            position++;
        }
        
        return this->insert(data, position);
    }
    
    void print()
    {
        Node *ctr = this->head;
        while (ctr != NULL)
        {
            std::cout << ctr->data << " ";
            ctr = ctr->next;
        }
        std::cout << std::endl << std::endl;
    }
    
    // reverse the linked list using changing the links
    // this uses three pointers.
    // these pointers are moved ahead by swapping links
    void reverse()
    {
        Node *p = this->head, *q = NULL, *r = NULL;
        
        this->tail = p;
        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        this->head = q;
    }
    
    // reverse the linked using recursion
    // traverse the list until the end
    // reverse links at returning time
    // maintain two pointers for changing links
    void recursiveReverse(Node *p, Node *q = NULL)
    {
        if (p)
        {
            this->recursiveReverse(p->next, p);
            p->next = q;
        }
        else
        {
            this->head = q;
        }
        this->tail = p;
    }
    
    // append another linked list to this one.
    void append(LinkedList list2)
    {
        Node *head2 = list2.getHead();
        Node *tail2 = list2.getTail();
        int count = list2.getCount();
        
        this->tail->next = head2;
        this->tail = tail2;
        this->count += count;
    }
    
    // merge two linked lists, sorted merge
    void merge(LinkedList list1, LinkedList list2)
    {
        if (this->count != 0) return;
        
        Node *head1 = list1.getHead();
        Node *head2 = list2.getHead();
        
        
    }
    
//    ~LinkedList()
//    {
//        Node *ctr = this->head;
//        while (ctr != NULL)
//        {
//            Node *temp = ctr;
//            ctr = ctr->next;
//            free(temp);
//        }
//    }
};

int main() {
    int arr1[] = { 10, 2, 4 };
    int arr2[] = { 9, 1, 16 };
    LinkedList list1(arr1, 3);
    LinkedList list2(arr2, 3);
    
    list1.print();
    list2.print();
    
    list1.append(list2);
    
    list1.print();
    
    return 0;
}
