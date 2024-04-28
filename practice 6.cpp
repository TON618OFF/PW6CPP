#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    string group;
    vector<string> lessons; 
    int done_works;
    int fail_works;

    Student(string name, string group, vector<string> lessons, int done_works, int fail_works) :
        name(name),
        group(group),
        lessons(lessons), 
        done_works(done_works),
        fail_works(fail_works) {}
};


class Teacher {
    public:
        string name;
        vector<string> groups;
        vector<string> lessons;

        Teacher(string name, vector<string> groups, vector<string> lessons) :
            name(name),
            groups(groups),
            lessons(lessons) {}

        void add_lesson_to_teacher(string lesson) {
            lessons.push_back(lesson);
        }

        void add_group_to_teacher(string group) {
            groups.push_back(group);
        }
};

class MPT {
public:
    vector<Student> students;
    vector<Teacher> teachers;

    void add_student_to_group(Student student, string group) {
        for (Student& student_in_group : students) {
            if (student_in_group.group == group) {
                student_in_group = student;
                return;
            }
        }
        students.push_back(student);
    }

    void add_lesson_to_teacher(Teacher teacher, string lesson) {
        for (Teacher& teacher_in_list : teachers) {
            if (teacher_in_list.name == teacher.name) {
                teacher_in_list.add_lesson_to_teacher(lesson);
                return;
            }
        }
    }

    void add_group_to_teacher(Teacher teacher, string group) {
        for (Teacher& teacher_in_list : teachers) {
            if (teacher_in_list.name == teacher.name) {
                teacher_in_list.add_group_to_teacher(group);
                return;
            }
        }
    }


};



int main() {
    setlocale(LC_ALL, "RU");
    MPT college;

    Student student1("Иванов Иван", "П50-4-22", { "ОАиП", "ОСиС" }, 10, 2);
    Student student2("Сидоров Сидр", "П50-5-22", { "C++", "HTML" }, 8, 1);

    college.add_student_to_group(student1, "П50-6-22");
    college.add_student_to_group(student2, "П50-1-22");

    cout << "Студенты:" << endl;
    for (Student student : college.students) {
        cout << "Имя: " << student.name << endl;
        cout << "Группа: " << student.group << endl;
        cout << "Дисциплины: ";
        for (string lesson : student.lessons) {
            cout << lesson << " ";
        }
        cout << endl;
        cout << "Количество выполненных работ: " << student.done_works << endl;
        cout << "Количество задолженностей: " << student.fail_works << endl;
        cout << endl;
    }

    Teacher teacher1("Хабиб Нурмагомедов", { "П50-1-22", "П50-2-22" }, { "ОАиП", "ОСиС" });

    college.add_lesson_to_teacher(teacher1, "Информатика");
    college.add_group_to_teacher(teacher1, "П50-3-22");

    cout << "\n\n\nПреподаватели:" << endl;
    cout << "Имя: " << teacher1.name << endl;
    cout << "Дисциплины: ";
    for (string lesson : teacher1.lessons) {
        cout << lesson << " ";
    }
    cout << endl;
    cout << "Группы: ";
    for (string group : teacher1.groups) {
        cout << group << " ";
    }
    cout << endl;

    return 0;
}


