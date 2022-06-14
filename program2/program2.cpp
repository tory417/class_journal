#include <iostream>
#include "Journal.h"
using namespace std;
void addStudent(Journal*& group, Journal& st, int& sizeGroup) {
    Journal* buf = new Journal[sizeGroup + 1];
    for (int i = 0; i < sizeGroup; i++) {
        buf[i] = group[i];
    }
    buf[sizeGroup] = st;
    delete[]group;
    group = buf;
    sizeGroup++;
}
void deleteStudent(Journal*& group, int& sizeGroup, int index) {
    Journal* buf = new Journal[sizeGroup - 1];
    for (int i = 0; i < index; i++) {
        buf[i] = group[i];
    }
    for (int i = index; i < sizeGroup - 1; i++) {
        buf[i] = group[i + 1];
    }
    delete[]group;
    group = buf;
    sizeGroup--;
}
void getDebtors(Journal*& group, int& sizeGroup) {
    for (int i = 0; i < sizeGroup; i++) {
        if (group[i].getSrmath() < 3 || group[i].getSrrus() < 3 || group[i].getSrphys() < 3) cout << group[i].getName() << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    int sizeGroup = 0;
    Journal st1("Darya Ivanova",3.5,4,5);
    Journal st2("Viktor Krylov", 2.6, 3, 4);
    Journal st3("Ivan Sokolov", 2, 3.1, 2.9);
    Journal st4("Lev Fedorov", 4, 5, 4.2);
    Journal st5("Anna Morozova", 2.7, 3.8, 4);
    Journal* group = new Journal[sizeGroup];
    addStudent(group, st1, sizeGroup);
    addStudent(group, st2, sizeGroup);
    addStudent(group, st3, sizeGroup);
    addStudent(group, st4, sizeGroup);
    addStudent(group, st5, sizeGroup);
    for (int i = 0; i < sizeGroup; i++) {
        group[i].showInfo();
    }
    cout << endl;
    deleteStudent(group, sizeGroup,1);
    for (int i = 0; i < sizeGroup; i++) {
        group[i].showInfo();
    }
    cout << endl;
    Journal st6("Mariya Antonova", 5, 5, 3);
    addStudent(group, st6, sizeGroup);
    for (int i = 0; i < sizeGroup; i++) {
        group[i].showInfo();
    }
    cout << endl;
    cout << "Должники:" << endl;
    getDebtors(group, sizeGroup);
}

