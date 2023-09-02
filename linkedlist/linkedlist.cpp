#include <iostream>

using namespace std;

class methods {
    virtual void append(int) = 0;
    virtual void insert(int, int) = 0;
    virtual void del(int) = 0;
    virtual int length() = 0;
    virtual int get(int) = 0;
};

class node {
public:
    int data;
    node* next;
    node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

class linkedlist:methods {
private:
    node *head, *temp, *new_node;
    int lenght;

public:
    linkedlist() {
        head = NULL;
        lenght = 0;
    }
    void append(int data) {
        new_node = new node(data);

        if(head == NULL)
            head = new_node;

        else {
            temp = head;
            while(temp -> next != NULL)
                temp = temp -> next;
            temp -> next = new_node;
        }
        lenght++;
    }
    void insert(int data, int index) { 
        new_node = new node(data);

        if(head == NULL)
            head = new node(data);

        else if(index == 0) {
            new_node -> next = head;
            head = new_node;
        }

        else {
            temp = head;
            for(int i = 0; i < index - 1; i++)
                temp = temp -> next;
            new_node -> next = temp -> next;
            temp = new_node;
        }
        lenght++;
    }
    void del(int index) {
        if(index == 0) {
            new_node = head;
            head = head -> next;
            delete(new_node);
        }
        else {
            temp = head;
            for(int i = 0; i < index - 1; i++)
                temp = temp -> next;

            new_node = temp -> next;
            temp -> next = (temp -> next) -> next;
            delete(new_node);
        }
        lenght--;
    }
    int length() {
        return lenght;
    }
    int get(int index) {
        temp = head;
        for(int i = 0; i < index; i++)
            temp = temp -> next;
        return temp -> data;
    }
};
