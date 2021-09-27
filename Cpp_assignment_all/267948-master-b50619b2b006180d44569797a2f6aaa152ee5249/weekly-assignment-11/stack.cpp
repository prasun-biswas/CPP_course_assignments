#include "stack.hh"
#include <iostream>

using namespace std;


Stack::Stack(): first_ptr_(nullptr) {
}

Stack::~Stack() {
    while ( not empty() ) {
        Cell* delete_ptr = first_ptr_;
        first_ptr_ = first_ptr_->next_ptr;
        delete delete_ptr;
    }
}

bool Stack::empty() const {
    return first_ptr_ == nullptr;
}

void Stack::push_front(int new_value) {
    Cell* new_ptr = new Cell;

    new_ptr->data = new_value;



    new_ptr->next_ptr = first_ptr_;
    first_ptr_ = new_ptr;
}

bool Stack::pop_front(int& removed_value) {
    if ( empty() ) {
        return false;
    }

    removed_value = first_ptr_->data;

    Cell* delete_ptr = first_ptr_;
    first_ptr_ = first_ptr_->next_ptr;
    delete delete_ptr;

    return true;
}

void Stack::print() const {
    Cell* print_ptr = first_ptr_;

    cout << "{ ";
    while ( print_ptr != nullptr ) {
        cout << print_ptr->data << " ";
        print_ptr = print_ptr->next_ptr;
    }

    cout << "}" << endl;
}

void Stack::reverse() {
    Cell* top_of_the_reversed_stack_ptr = nullptr;

    while ( not empty() ) {
        // The first element is separated from the list.
        Cell* moved_element_ptr = first_ptr_;
        first_ptr_ = first_ptr_->next_ptr;


        moved_element_ptr->next_ptr = top_of_the_reversed_stack_ptr;
        top_of_the_reversed_stack_ptr = moved_element_ptr;
    }


    first_ptr_ = top_of_the_reversed_stack_ptr;
}
