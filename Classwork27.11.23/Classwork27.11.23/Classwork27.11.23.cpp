#include <iostream>
#include "stdatabase.h"
#include "utils.h"

int menu()
{
    for (int i = 0; i < 40; ++i)std::cout.put('*');
    std::cout << std::endl;
    std::cout << "1. Open database\n";
    std::cout << "2. Save database\n";
    std::cout << "3. Export database\n";
    std::cout << "4. Print\n";
    std::cout << "5. Add student\n";
    std::cout << "6. Set marks\n";
    std::cout << "7. Sort students\n";
    std::cout << "8. Delete student\n";
    std::cout << "0. Exit\n";
    return getInt();
}

int main()
{
    DataBase DB = { 0,0,nullptr };
    const char dbfilename[] = "student.db";
    int action;
    do {
        action = menu();
        switch (action)
        {
        case 1:openDB(DB, dbfilename); break;
        case 2:saveDB(DB, dbfilename); break;
        case 3:exportDB(DB, "students.txt"); break;
        case 4:printDB(DB); break;
        case 5:addRecord(DB); break;
        case 6:setMarks(DB); break;
        case 7:sort(DB); break;
        case 8:deleteRecord(DB); break;
        }
    } while (action != 0);

    deleteDB(DB);

    return 0;
}