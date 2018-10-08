#ifndef FileGopherServer_H
#define FileGopherServer_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <netdb.h>
#include <string> // for string class

using namespace std;

//! Buffer Length.
#define BUFFER_LEN 10240
//! Carraige Return charachter.
#define CR ((char)13)
//! Line Feed charachter.
#define LF ((char)10)
//! CRLF String.
#define CRLF string(1, CR) + string(1, LF)
#define TAB "\t"
//! End of Content.
#define EOC "." + CRLF
#define MY_HOST "0.0.0.0"
#define MY_PORT 7070
/**
 * Class for FileGopherServer.
 */

class FileGopherServer
{
  //! Socket File descriptoe and the port.
  int socket_fd, socket_port;
  char buffer[BUFFER_LEN];
  //! Map to hold routes.
  unordered_map<string, string> routes;
  struct sockaddr_in server_addr, client_addr;
  string root;
  string socket_host;
  bool show_hidden_files;
  static void error(const char *msg);
  static bool is_regular_file(const char *path);
  static bool is_text_file(const char *file);
  static char get_file_type(const char *file);
  void send_file_contents(int client_fd, const char *file);
  int get_contents(char buffer[], int size,bool show_hidden_files);

public:
  static string create_line(char type, string user_setting,
                            string path = "", string host = "error.host", int port = 1);
  FileGopherServer(string root, int port,bool show_hidden_files);
  FileGopherServer();
  void start(int n_connections = 5);
  void add_route(string route, string content);
};

#endif