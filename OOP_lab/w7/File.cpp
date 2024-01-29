#include "File.h"

void openFile(const string &filePath)
{

    if (filePath != "valid_path.txt")
    {
        throw FileNotFoundException(filePath);
    }

    cout << "File opened successfully." << endl;
}
