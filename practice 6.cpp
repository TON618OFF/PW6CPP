#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student 
{
    public:
        string name;
        string group;
        string lesson;
        int done_works;
        int fail_works;

        Student(string name, string group, string lesson, int done_works, int fail_works) :
            group(group),
            lesson(lesson),
            done_works(done_works),
            fail_works(fail_works) 
        {

        }
};

class Teacher 
{
    public:
        string name;
        string group;
        string lesson;

        Teacher(string name, string group, string lesson) :
            name(name),
            group(group),
            lesson(lesson) 
        {

        }
};

class MPT 
{
    
};


int main()
{
    std::cout << "Hello World!\n";
}

