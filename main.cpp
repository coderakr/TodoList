#include <fstream>
#include <iostream>
using namespace std;

ofstream file;

void addTask() {

    file.open("todo.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error : Unable to open the file" << endl;
        return;
    }

    string str;
    cout << "Enter the task : " << endl;
    cin.ignore();
    getline(cin, str);
    file << str << "\n";
    file.close();
    cout << endl;
}


void viewTask() {

    ifstream file("todo.txt");
    if (!file.is_open()) {
        cerr << "Error : Unable to open the file" << endl;
        return;
    }

    int taskcount = 0;
    string str;
    while (getline(file, str)) {
        taskcount++;
        cout << "Task " << taskcount << ": " << str;
        cout << endl;
    }
    file.close();
    cout << endl;
}


void deleteTask() {

    ofstream temp;
    ifstream file("todo.txt");
    temp.open("temp.txt");
    if (!(temp.is_open() && file.is_open())) {
        cerr << "Error : Unable to open the file" << endl;
        return;
    }

    cout << "Enter the task number that you want to remove : ";
    int done;
    cin >> done;

    // creating a new file without the done taks
    string str;
    int count=0;
    while(getline(file,str)){
        count++;
        if(count!=done){
            temp << str << "\n";
        }
    }

    file.close();
    temp.close();
    // deleting the old file and renaming the new file
    const char *filename = "todo.txt";
    remove(filename);
    rename("temp.txt", "todo.txt");
    cout << endl;
}


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

        // will be adding more feature soon
        // -> No of Tasks
        // -> Tasks history
        // -> Prioritize Tasks

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
            case 4:
                cout << "Thanks for using this program" << endl;
                break;
            default:
                cout << "Invalid input! Try again" << endl;
        }
    } while (ch != 4);

    return 0;
}
