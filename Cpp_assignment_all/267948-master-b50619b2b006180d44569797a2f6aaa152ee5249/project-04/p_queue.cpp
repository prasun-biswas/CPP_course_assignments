#include "p_queue.h"

p_Queue::p_Queue(int maximumPriority)
{
head=NULL;
maxPriority=maximumPriority;
}

p_Queue::~p_Queue(){
    clear();
}
Node *p_Queue::top(){

    return head;
}



//returns the max_priority variable
int p_Queue::getMaxPriority()
{
    return maxPriority;
}

//sets the max priority variable
void p_Queue::setMaxPriority(int value)
{
    maxPriority = value;
}






bool p_Queue::push(const int priority, const string data){

    if (priority > this->maxPriority) {
        cout << "Error: priority level must be an integer between 1-" << this->maxPriority << endl;
        return false;
    }
    // If the head is null, put the item on top
    else if (head == NULL) {
        // Allocare item using new keyword
        Node *item = new Node;
        item->priority = priority;
        item->data = data;
        item->next = NULL;
        head = item;
        return true;
    }
    // put it on task on top according to priority
    else if (top()->priority < priority) {
        // Allocare item using new keyword
        Node *item = new Node;
        item->priority = priority;
        item->data = data;
        item->next = head;
        head = item;
        return true;
    }
    // For items with lower or equal priority
    else {
        // Allocare item using new keyword
        Node *item = new Node;
        item->priority = priority;
        item->data = data;
        item->next = NULL;

        Node *current = head;
        Node *previous = NULL;

        // Iterate through next items
        while (current != NULL) {
            // When an item with lower priority is found
            if (item->priority > current->priority) {
                // Insert the new item in the middle of them
                item->next = current;
                previous->next = item;
                return true;
            }

            // Else keep moving forward
            previous = current;
            current = current->next;
        }

        previous->next = item;

        return true;
    }

}

bool p_Queue::pop(){


    if (head == NULL) {
            return false;
        } else {
            // Allocate item using new keyword
            Node *item = head->next;
            // Clear node
            delete head;
            // Update head
            head = item;
            return true;
        }



}

bool p_Queue::erase(const int number){

    Node *current = head;
        Node *previous = NULL;
        int runningNumber = 0;

        // Loop through next items
        while (current != NULL) {
            // Increment running number
            runningNumber++;

            // When an item with matching running number is found
            if (runningNumber == number) {
                // If the item is on top
                if (previous == NULL) {
                    Node *item = NULL;
                    item = current->next;
                    delete current; // NOTE: MEMORY FREED
                    head = item;
                }
                // If the item is in the middle of the list
                else {
                    Node *item = NULL;
                    item = current->next;
                    delete current; // NOTE: MEMORY FREED
                    previous->next = item;
                }
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;


}


// Clear all items from the queue
void p_Queue::clear()
{

    if (head != NULL) {
        // Start from head
        Node *current = head;
        Node *next;

        // until NULL sequentially Iterate through next node
        while (current != NULL) {
            next = current->next;
            delete current; // NOTE: MEMORY FREED
            current = next;
        }

        head = NULL;
    }
}

ostream &operator << (ostream &out, const p_Queue &pq)
{
    if (pq.head == NULL) {
        return out;
    } else {
        Node *current = pq.head;

        int inuse = INT_MAX;
        int runningNumber = 1;

        // Loop through next items
        while (current != NULL) {
            // Print level of priority only once
            if (inuse != current->priority) {
                inuse = current->priority;
                cout << "Priority level " << inuse << ":" << endl;
            }

            // Print the running number, chore description and new line
            out << "  " << runningNumber
                << ". " << current->data
                << endl;

            current = current->next;
            runningNumber++;
        }

        return out;
    }
}
