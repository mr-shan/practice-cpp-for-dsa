// Online C++ compiler to run C++ program online
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
        this->count - 0;
    }
    
    LinkedList(int *arr, int length)
    {
        this->head = NULL;
        this->tail = NULL;
        this->count - 0;
        for(int i = 0; i < length; ++i)
            this->push(arr[i]);
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
    
    ~LinkedList()
    {
        Node *ctr = this->head;
        while (ctr != NULL)
        {
            Node *temp = ctr;
            ctr = ctr->next;
            free(temp);
        }
    }
};

int main() {
    LinkedList list2;
    
    list2.push(11);
    list2.push(14);
    list2.push(18);
    list2.push(23);
    
    list2.print();

    // list2.insert(15, 3);

    list2.sortedInsert(21);
    list2.print();
    list2.sortedInsert(0);
    list2.print();
    list2.sortedInsert(100);
    list2.print();
    list2.sortedInsert(-20);
    list2.print();
    
    list2.sortedInsert(221);
    list2.print();
    
    return 0;
}
