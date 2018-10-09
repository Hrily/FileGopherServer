#include "FileGopherServer.h"
#include "boost/program_options.hpp"

using namespace std;
namespace po = boost::program_options;

// Driver function.
int main(int argc, char *argv[])
{
    // variables needed to be captured from command line options

    string directory = "."; // defaults to cwd
    int port = 70;          // default port value of 70
    bool show_hidden_files = false;

    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
    ("directory,d", po::value<string>(), "The directory to serve")
    ("port,p", po::value<int>(), "The port to serve on (default : 70)")
    ("hidden,h", "Show hidden files if specified")
    ("help", "Show help");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        cout << desc << "\n";
        return 1;
    }
    if (vm.count("directory"))
    {
        directory = vm["directory"].as<string>();
    }
    if (vm.count("port"))
    {
        port = vm["port"].as<int>();
    }
    if (vm.count("hidden"))
    {
        show_hidden_files = true;
    }

    // Check if given directory can be opened.
    if (opendir(directory.c_str()) == NULL)
    {
        cout << "Error(" << errno << ") opening " << directory << endl;
        return 0;
    }
    // Creat and start FileGopherServer.
    FileGopherServer fileGopherServer(directory, port, show_hidden_files);
    fileGopherServer.start();
    return 0;
}