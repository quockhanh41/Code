#include <iostream>
#include <exception>
#include <string>
#include <cstring>
using namespace std;

class FileNotFoundException : public exception
{
private:
    string filePath;

public:
    FileNotFoundException(const string &path) : filePath(path) {}

    const char *what() const throw()
    {
        return "Exception: File not found ";
    }
};
void openFile(const string &filePath);