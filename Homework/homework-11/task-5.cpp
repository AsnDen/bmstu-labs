#include <iostream>
#include <fstream>

struct Student
{
    int id;
    char name[50];
    int age;
    double average_grade;
};

int main()
{
    Student students[] = {
        {1, "Ivan Ivanov", 20, 4.5},
        {2, "Mary Sidorova", 19, 4.8},
        {3, "Alex Ivanov", 21, 4.2}};

    std::string file_name{"students.dat"};

    std::ofstream out(file_name, std::ios::binary);

    for (Student student : students)
    {
        out.write(reinterpret_cast<char *>(&student), sizeof(Student));
    }
    out.close();

    std::ifstream in(file_name, std::ios::binary);
    in.seekg(0, std::ios::end);
    size_t file_size = static_cast<size_t>(in.tellg());
    in.seekg(0, std::ios::beg);

    size_t count = static_cast<size_t>(file_size / sizeof(Student));
    Student *read_students = new Student[count];

    for (size_t i{}; i < count; i++)
    {
        in.read(reinterpret_cast<char *>(&read_students[i]), sizeof(Student));
    }
    in.close();

    double max_grade = 0;
    size_t best_student = 0;

    for (size_t i{}; i < count; i++)
    {
        std::cout << read_students[i].id << " "
                  << read_students[i].name << " "
                  << read_students[i].age << " "
                  << read_students[i].average_grade << std::endl;

        if (read_students[i].average_grade > max_grade)
        {
            max_grade = read_students[i].average_grade;
            best_student = i;
        }
    }

    std::cout << "Num of students: " << count << '\n';
    std::cout << "Best student: " << read_students[best_student].name
              << " with score of" << max_grade << '\n';

    delete[] read_students;
    read_students = nullptr;

    return 0;
}
