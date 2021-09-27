#include "function_chores.h"



string trim(const string &str){

size_t first =str.find_first_not_of(' ');
if(string::npos==first){
    return str;
}
size_t last =str.find_last_not_of(' ');
return str.substr(first,(last-first+1));
}

//constructor of function_chores class


function_Chores::function_Chores()
{

    promptInput ="chores> ";
    isInitialized = false;
}

void function_Chores::prompt(){

    while (true) {

    cout<< promptInput;
    //replace empty string "command" to be splited
    command="";
    getline(cin,command);
    trim(command);

    //clear the input buffer for taking next input
    cin.clear();

    //get the first word after prompt
    operation = command.substr(0,command.find(" "));

    // store argument from command
    args="";
    number=0;
    numberFound=false;
    argsFound=false;

    processCommand();

    if (operation=="init"){
        init();
    }else if (operation=="add") {
        add();
    }else if (operation=="print") {
        print();
    }else if (operation=="erase") {
        erase();
    }else if (operation=="quit")
        break;
    else if (operation.size()>1) {
        cout << "Error: no such command." << endl;
             operation.clear();
    }

    }

}

void function_Chores::processCommand(){

    //find if there are multiple arguments

    if(command.find(" ")!=string::npos){
        args = command.substr(command.find(" ")+1,command.length());
        argsFound = true;

        char *end;
        // get number if valid
        string num=args.substr(0,args.find(" "));
        number = strtol(num.c_str(), &end, 10);

        if(end !=num.c_str()){

            numberFound=true;
            // find if there is argument after number
            if(args.find(" ")== string::npos){
                args.clear();
                argsFound=false;

            }else {
                args=args.substr(args.find(" ")+1, args.length());
                argsFound=true;
            }

        }


    }



}


void function_Chores::init(){
    if(numberFound){
        if(number<0)
            cout << "Error: it is not possible to create a priority list with 0 or less levels." << endl;
    else{
            cout << "New priority list with levels 1-" << number << " isInitialized." << endl;
            priorityQueue.clear();
            priorityQueue.setMaxPriority(number);
            isInitialized=true;
        }


    }else{
        if (!argsFound)
                    cout << "Error: the number of priority levels is missing." << endl;
                else
                    cout << "Error: the number of priority levels must be an integer larger than 0." << endl;


    }
    operation.clear();

}





void function_Chores::add(){

if(!isInitialized){

    cout << "Error: initialize priority list first." << endl;
} else if (numberFound) {
    if(number<=0 or number>priorityQueue.getMaxPriority())
    cout << "Error: priority level must be an integer between 1-" << priorityQueue.getMaxPriority() << "." << endl;
    else {

        if(argsFound){

            priorityQueue.push(number,args);
            cout<<"New chore added to priority level"<<number<<"."<<endl;
        } else {
            cout<<"Error: chore description is missing."<<endl;
        }
    }

} else if (argsFound) {
    cout<<"Error: priority level must be an integer between 1-"<<priorityQueue.getMaxPriority()<<"."<<endl;
} else {
    cout<<"Error: priority level and chore description are missing."<<endl;
}
operation.clear();


}

void function_Chores::print(){
if(!isInitialized){
cout<<"Error: initialize priority list first."<< endl;

}
else if (argsFound or numberFound) {
    cout<<"Error: extra text after print command."<<endl;
}
else
    cout<<priorityQueue;

operation.clear();


}

void function_Chores::erase(){


    if (!isInitialized) {
        cout << "Error: initialize priority list first." << endl;
    } else if (numberFound) {

        //check current number before eraseing
        if (number <= 0)
            cout << "Error: the running number must be larger than 0." << endl;
        // Otherwise allow erasing
        else {
            if (!priorityQueue.erase(number))
                cout << "Error: there is no such chore." << endl;
        }
    }
    //check current number before eraseing
    else {
        if (!argsFound)
            cout << "Error: the running number is missing." << endl;
        else
            cout << "Error: the running number must be larger than 0." << endl;
    }

    operation.clear();

}


void function_Chores::next()
{
    // Do not erase anything from the task if not initialized
    if (!isInitialized) {
        cout << "Error: initialize priority list first." << endl;
    } else if (argsFound or numberFound) {
        cout << "Error: extra text after next command." << endl;
    } else {
        // If list is empty, show that there is no chores left
        if (priorityQueue.top() == NULL) {
            cout << "--- no chores left ---" << endl;
        }
        // If list is initialized, show the top most chore name
        else {
            cout << priorityQueue.top()->data << endl;
            priorityQueue.pop();
        }
    }

    operation.clear();
}


