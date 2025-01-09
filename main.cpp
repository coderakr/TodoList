#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ofstream file;

void addTask() {
    file.open("todo.txt",ios::app);

    if(!file.is_open()){
        cerr << "Error : Unable to open the file" << endl;
        return ;
    }

    string str;
    cout << "Enter the task : " << endl;
    cin.ignore();
    getline(cin,str);
    file << str;
    file.close();
}

void viewTask() {}
void deleteTask() {}

int main(int argc, char *argv[]) {
    int ch;
    do {
        cout << "1. Add to task" << endl;
        cout << "2. view a task" << endl;
        cout << "3. Delete a task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        cout << endl;

        switch (ch) {
            case 1:
                addTask();
                break;
            case 2:
                viewTask();
                break;
            case 3:
                deleteTask();
                break;
            default:
                cout << "Thanks for using this program" << endl;
                break;
        }
    } while (ch != 4);

    return 0;
}
