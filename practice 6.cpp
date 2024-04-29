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

        bool student_found = false;
        for (Student& student_in_list : students) {
            if (student_in_list.name == student.name) {
                student_found = true;
                break;
            }
        }

        bool group_found = false;
        for (Student& student_in_group : students) {
            if (student_in_group.group == group) {
                group_found = true;
                break;
            }
        }

        if (student_found && group_found) {
            for (Student& student_in_group : students) {
                if (student_in_group.group == group) {
                    student_in_group = student;
                    return;
                }
            }
        }
        else {
            cout << "Ошибка: студент или группа не найдены" << endl;
        }

        for (Student& student_in_group : students) {
            if (student_in_group.group == group) {
                student_in_group = student;
                return;
            }
        }
        students.push_back(student);
    }

    void add_lesson_to_teacher(Teacher teacher, string lesson) {

        bool teacher_found = false;
        for (Teacher& teacher_in_list : teachers) {
            if (teacher_in_list.name == teacher.name) {
                teacher_found = true;
                break;
            }
        }

        for (Teacher& teacher_in_list : teachers) {
            if (teacher_in_list.name == teacher.name) {
                teacher_in_list.add_lesson_to_teacher(lesson);
                return;
            }
        }
    }

    void add_group_to_teacher(Teacher teacher, string group) {

        bool teacher_found = false;
        for (Teacher& teacher_in_list : teachers) {
            if (teacher_in_list.name == teacher.name) {
                teacher_found = true;
                break;
            }
        }

        if (teacher_found) {
            teacher.groups.push_back(group);
        }
        else {
            cout << "Ошибка: преподаватель не найден" << endl;
        }

        for (Teacher& teacher_in_list : teachers) {
            if (teacher_in_list.name == teacher.name) {
                teacher_in_list.add_group_to_teacher(group);
                return;
            }
        }
    }

    void print_attendance(int num_present, int num_total) {

        if (num_present < 0) {
            cout << "Количество присутствующих студентов не может быть отрицательным" << endl;
            return;
        }
        if (num_present > num_total) {
            cout << "Количество присутствующих студентов не может быть больше общего количества студентов в группе" << endl;
            return;
        }

    }

    void remove_student_from_group(Student student, string group) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].name == student.name) {
                students.erase(students.begin() + i);
                return;
            }
        }
        cout << "Студент не найден" << endl;
    }

    void check_students(vector<Student>& students) {
        for (Student& student : students) {
            if (student.fail_works > 5) {
                cout << "У студента больше 5 задолженностей! Он был удалён из группы!" << endl;
                remove_student_from_group(student, student.group);
            }
        }
    }


};




int main() {
    setlocale(LC_ALL, "RU");
    MPT college;

    Student student1("Иванов Иван", "П50-4-22", { "ОАиП", "ОСиС" }, 10, 2);
    Student student2("Сидоров Сидр", "П50-5-22", { "C++", "HTML" }, 8, 1);

    if (student1.done_works < 0 || student1.fail_works < 0) {
        cout << "Неверные значения! Перепроверьте данные студента!";
        return -1;
    }

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

    
    college.check_students(college.students);

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

    int num_present;
    int num_total;
    cout << "\n\n\nВведите количество присутствующих студентов: " << endl;
    cin >> num_present;
    cout << "Введите общее количество студентов в группе: " << endl;
    cin >> num_total;

    cout << "Информация о присутствующих на паре: " << endl;
    college.print_attendance(num_present, num_total);

    return 0;
}


