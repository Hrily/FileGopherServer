#include "FileGopherServer.h"

using namespace std;

// Driver function.
int main(int argc, char *argv[])
{
    // Print Usage.
    if (argc != 2)
    {
        printf("USAGE: \n\tserver <directory-to-serve>\n\n");
        printf("Where <directory-to-serve> root directory of server.\n");
        return 0;
    }
    // Check if given directory can be opened.
    if (opendir(argv[1]) == NULL)
    {
        cout << "Error(" << errno << ") opening " << argv[1] << endl;
        return 0;
    }
    // Creat and start FileGopherServer.
    FileGopherServer fileGopherServer(argv[1], 7070);
    fileGopherServer.start();
    return 0;
}