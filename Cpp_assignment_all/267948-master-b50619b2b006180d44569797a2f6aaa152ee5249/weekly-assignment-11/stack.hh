#ifndef STACK_HH
#define STACK_HH

class Stack {
  public:
    Stack();
    ~Stack();


    bool empty() const;


    void push_front(int new_value);



    bool pop_front(int& removed_value);


    void print() const;

    void reverse();  // Problem 1

  private:
    struct Cell {
        int data;
        Cell* next_ptr;
    };

    Cell* first_ptr_;
};

#endif // STACK_HH
