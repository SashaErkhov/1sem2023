#include <iostream>
#include <fstream>//Файловые потоки


int main()
{
    std::ifstream inFile("readme.txt");//Файлик на чтение 
    if (!inFile)
    {
        std::cout << "Xui";
        return 1;
    }
    std::ofstream outFile("output.txt", std::ios_base::binary | std::ios_base::app);//Файлик на запись
    //update( | std::ios_base::app ): Дописывание одновременно с binary
    if (!outFile)
    {
        std::cout << "Xui";
        inFile.close();
        return 2;
    }
    int ch;// Это лучше чем char ch;
    int count = 0;
    while ((ch = inFile.get()) != EOF)
    {
        outFile.put(ch);
        ++count;
    }
    std::cout << "Total: " << count << " bytes" << std::endl;
    inFile.close();
    outFile.close();
    return 0;
}