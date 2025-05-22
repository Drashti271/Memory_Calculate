#include<iostream>
#include<vector>

using namespace std;

class Student {
public:
    int id;
    string name;

    Student(int id, string name) : id(id), name(name) {}

    void display() const 
    {
        cout<<"ID: "<<id<<", Name: "<<name<<endl;
    }
};

class StudentManager {
private:
    vector<Student> students;  

public:
    void addStudent(int id, string name) 
    {
        students.push_back(Student(id, name));
    }

    void displayStudents() const 
    {
        if (students.empty()) 
        {
            cout<<"No students to display."<<endl;
            return;
        }
        cout<< "Student Information: "<<endl;
        for (const auto& student : students) 
        {
            student.display(); 
        }
    }

    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) 
        {
            if (it->id == id) 
            {
                students.erase(it); 
                cout<<"Student with ID "<<id<<" has been deleted."<< endl;
                return;  
            }
        }
        cout<<"Student with ID "<<id<<" not found."<<endl;
    }

    void searchStudent(int id) const 
    {
        for (const auto& student : students) 
        {
            if (student.id == id) 
            {
                cout << "Student found: "<<endl;
                student.display(); 
                return;  
            }
        }
        cout<<"Student with ID "<<id<<" not found."<<endl;
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        int id;
        string name;

        cout<<"1. Add Student"<<endl;
        cout<<"2. Display Students"<<endl;
        cout<<"3. Delete Student"<<endl;
        cout<<"4. Search Student"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) 
        {
        case 1:
            cout<<"Enter Student ID: ";
            cin>> id;
            cout<<"Enter Student Name: ";
            cin>>name;
            manager.addStudent(id, name);
            break;

        case 2:
            manager.displayStudents();
            break;

        case 3:
            cout<<"Enter Student ID to delete: ";
            cin>>id;
            manager.deleteStudent(id);
            break;

        case 4:
            cout<<"Enter Student ID to search: ";
            cin>>id;
            manager.searchStudent(id);
            break;

        case 0:
            cout<<"Exiting..."<<endl;
            break;

        default:
            cout<<"Invalid choice, please try again."<<endl;
        }

    } while (choice != 0);

    return 0;
}
