#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    
    int ch;
    do{
        cout << "1. Add to task" << endl;
        cout << "2. view a task" << endl;
        cout << "3. Delete a task" << endl;
        cout << "4. Enter your choice" << endl;
        cin >> ch;
    }while(ch!=4);

    return 0;
}
