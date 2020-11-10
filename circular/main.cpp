#include "cdll.h"
#include <iostream>
#include <string>


using namespace std;


// helper function to handle user input 
void getInput(CDLL list){    
    // setup loop for user input
    bool run = true;
    int i = 0;

    cout<<"> = next"<<endl<<"< = previous"<<endl<<"A = append"<<endl<<"P = prepend"
        <<endl<< "I = all items"<<endl<<"S = print size"<<endl<< "R = remove"<< endl << "Q = quit" << endl; 
    while(run == true){
        cout<<"Please enter a command: ";   
        string binding;
        getline(cin, binding);

        if(binding == ">")
        {
            list.next();
        }
        else if(binding == "<")
        {
            list.previous();
        }
        else if(binding == "A")
        {
            cout<< "enter a item to append: ";
            int num;
            cin >> num;
            list.append(num);
            cout<<"item added to the back";
        }
        else if(binding == "P")
        {
            cout<< "enter a item to prepend: ";
            int num;
            cin >> num;
            list.prepend(num);
            cout<< "item added to the front ";
        }
        else if(binding == "I")
        {
            list.printAll();
        }
        else if(binding == "Q")
        {
            exit(0);
        }
        else if(binding == "S")
        {
            list.printSize();
        }
        else if(binding == "R")
        {
            list.removeLast();
            cout<< "Item Removed from list";
        }
        else
        {
            cout<< "please enter a valid command";
        }
        cout<<endl;
        i++;
    }
}



int main(int argc, const char * argv[]){
    // define our CDLL list 
    CDLL list;
    
    // loop and append items to the list
    for(int i = 0; i < 5; i++){
        list.append(i);
    }


    getInput(list);
   

    return 0;
}
