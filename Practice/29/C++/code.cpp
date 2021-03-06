#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include "bozo.hpp"
struct Student
{
    std::map<std::string, int> exams;
    std::string sName;
    int sgroup;
    Student(std::string Name, int group, int math, int phys, int hist, int prog)
    {
        exams = {{"math", math}, {"phys", phys}, {"hist", hist}, {"prog", prog}};
        sName = Name;
        sgroup = group;
    }
    friend std::ostream &operator<<(std::ostream &print, const Student &student)
    {
        auto namelen = std::max(int(student.sName.length()), 4);
        auto del = std::string(namelen, '-');
        print << "+-" << del << "-+-------+------+------+------+------+\n"
              << "| Name" << std::string(namelen - 4, ' ')
              << " | Group | Math | Phys | Hist | Prog |\n"
              << "+-" << del << "-+-------+------+------+------+------+\n"
              << "| " << student.sName << " |   " << student.sgroup
              << "   |  " << student.exams.at("math")
              << "   |  " << student.exams.at("phys")
              << "   |  " << student.exams.at("hist")
              << "   |  " << student.exams.at("prog") << "   |\n"
              << "+-" << del << "-+-------+------+------+------+------+\n";
        return print;
    }
    bool operator>(const Student &Deb)
    {
        return sName > Deb.sName;
    }
    bool operator<(const Student &Deb)
    {
        return sName < Deb.sName;
    }
};
std::ostream &operator<<(std::ostream &print, const std::vector<Student> &loxi)
{
    auto namelen = loxi.at(0).sName.length();
    for (auto lox = loxi.begin() + 1; lox != loxi.end(); lox++)
    {
        if (lox->sName.length() > namelen)
        {
            namelen = lox->sName.length();
        }
    }
    auto del = std::string(namelen, '-');
    print << "+-" << del << "-+-------+------+------+------+------+\n"
          << "| Name" << std::string(namelen - 4, ' ')
          << " | Group | Math | Phys | Hist | Prog |\n"
          << "+-" << del << "-+-------+------+------+------+------+\n";
    for (auto student : loxi)
    {
        print << "| " << student.sName << std::string(namelen - student.sName.length(), ' ') << " |   " << student.sgroup
              << "   |  " << student.exams.at("math")
              << "   |  " << student.exams.at("phys")
              << "   |  " << student.exams.at("hist")
              << "   |  " << student.exams.at("prog")
              << "   |\n"
              << "+-" << del << "-+-------+------+------+------+------+\n";
    }
    return print;
}
int main()
{
    std::srand(std::time(0));
    std::vector<Student> students = {
        Student("WhosJoe", 1, 5, 4, 4, 3),
        Student("Mathue", 7, 4, 4, 3, 4),
        Student("JoJo", 3, 5, 5, 2, 5),
        Student("Damedane", 3, 1, 3, 2, 1),
        Student("Oama", 3, 3, 3, 3, 2),
        Student("Dameyo", 0, 4, 5, 2, 3),
        Student("BTSgay", 6, 3, 4, 2, 5),
        Student("Dame", 0, 3, 3, 2, 3),
        Student("UWUUWU", 5, 4, 3, 2, 1),
        Student("Dameyu", 4, 5, 2, 3, 3)};
    std::vector<Student> dvoeshniki;
    int kolvo = 0;
    for (auto lox : students)
    {
        for (auto exam : lox.exams)
        {
            if (exam.second == 2)
            {
                dvoeshniki.push_back(lox);
                kolvo += 1;
                break;
            }
        }
    }
    if (kolvo)
    {
        int ktoto = std::rand() % kolvo;
        std::cout << Bozosort(dvoeshniki);
        std::cout << "Explusion\n";
        std::cout << dvoeshniki[ktoto];
    }
    else
    {
        cout << "Not found\n";
    }
}