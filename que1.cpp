#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Student {
private:
    T1 id;
    T2 name;

public:

    Student(T1 student_id , T2 student_name) 
    {
        id = student_id;
        name = student_name;
    }

    void displayDetails() 
    {
        cout<<"Student ID: "<<id<<", Name: "<<name<< endl;
    }
};

int main() {
    Student<int, string> student1(101, "Yatri");
    student1.displayDetails();

    Student<int, string> student2(102, "Trupti");
    student2.displayDetails();

    Student<int, string> student3(103, "Vibhuti");
    student3.displayDetails();

    Student<int, string> student4(104, "Venisha");
    student4.displayDetails();

    Student<int, string> student5(105, "Akshita");
    student5.displayDetails();

    return 0;
}
