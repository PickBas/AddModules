#include "../include/CreationCModule.h"
#include "../include/CreationCppModule.h"

int main(){
    bool flag = true;
    while (flag == true){
        cout << "Enter 1 to create a C++ module;" << endl
             << "Enter 2 to create a C module;" << endl
             << "Enter exit to close the app:" << endl;
        char c[5] = {};
        try{
            cin >> c;
            if (c[0] != '1' && c[0] != '2' && strncmp(c, "exit", 4) != 0)
                throw 1;
        }
        catch (int x){
            if (x == 1)
                cout << "The wrong character has been entered!" << endl << endl;
        }

        if (c[0] == '1')
            CreationCppModule();
        if (c[0] == '2')
            CreationCModule();
        if (!strncmp(c, "exit", 4)){
            flag = false;
            cout << "OK!" << endl;
        }
    }
    cout << "Program's author is Kirill Sayed." << endl
         << "Good luck!" << endl;
    return 0;
}