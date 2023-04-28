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
    
    void print()
    {
        Node *ctr = this->head;
        while (ctr != NULL)
        {
            std::cout << ctr->data << " ";
            ctr = ctr->next;
        }
        std::cout << std::endl;
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
    // Write C++ code here
    LinkedList list;
    list.push(1);
    list.push(2);
    list.print();
    
    std::cout << std::endl;
    
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList list2(arr, 5);
    list2.print();
    
    std::cout << list2.pop() << std::endl;
    std::cout << list2.pop() << std::endl;
    std::cout << list2.pop() << std::endl;
    std::cout << list2.pop() << std::endl;
    std::cout << list2.pop() << std::endl;
    list2.print();
    
    list2.push(11);
    list2.push(12);
    list2.print();
    
    return 0;
}
