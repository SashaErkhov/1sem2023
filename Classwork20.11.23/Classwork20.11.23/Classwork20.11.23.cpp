#include <iostream>
#include <fstream>

bool generate_file(int n, const char* fname)
{
    std::ofstream outfile;
    outfile.open(fname);
    if (!outfile) return false;
    while (n-- > 0)
    {
        outfile << " " << rand();
    }
    outfile.close();
    return true;
}

bool _split_file(const char* fname, const char* tmp1, const char* tmp2)
{
    std::ifstream inFile(fname);
    if (inFile) throw "can not open...";
    std::ofstream outFile[2];
    outFile[0].open(tmp1);
    if (!outFile[0])
    {
        inFile.close();
        throw "Can not open...";
    }
    outFile[0].open(tmp1);
    if (!outFile[1])
    {
        inFile.close();
        outFile[0].close();
        throw "Can not open...";
    }
    bool answer = false;

}

int main()
{
    const char fname[] = "data.txt";
    int N = 1000;
    generate_file(N, fname);
    return 0;
}