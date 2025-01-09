#include <fstream>
#include <iostream>
using namespace std;

void addTask() {}
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
