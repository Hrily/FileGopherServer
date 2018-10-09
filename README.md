# FileGopherServer

FileGopherServer is a Gopher server which serves the file listing.

I've tried as much as possible to align the implementation with the Gopher [RFC 1436](https://www.ietf.org/rfc/rfc1436.txt).
This server is non-gopher+, but supports gateway for gopher+ clients as a forward compatibility.

## About Gopher

Gopher is a pre-HTTP protocol for browsing the internet. It is easy to use and light-weight, even for implementation. To know more about Gopher visit wiki page [Wiki](https://en.wikipedia.org/wiki/Gopher_\(protocol\) "Gopher protocol - Wikipedia").

## Dependencies

FileGopherServer depends upon boost library. Install boost library and then compile FileGopherServer.

## Compilation

```
$ g++ -o server server.cpp FileGopherServer.cpp -std=gnu++11 -lboost_program_options
```

## Usage

```
$ ./server -d <directory-to-serve>
```

For example, to serve current directory:

```
$ ./server -d .
```

## Gopher clients

In order to see server contents, you will need a Gopher client.

Ubuntu has it in it's repository. To install it, type:
```
$ sudo apt-get install gopher
```

See [Overbite Project](http://gopher.floodgap.com/overbite/ "Overbite Project") for clients for major platforms.

[DiggieDog](https://play.google.com/store/apps/details?id=com.afewroosloose.gopher) is a nice client for Android.

## TODO

- [ ] Implement efficient method to check a file is text or binary.
- [x] Add option to list hidden files.

## Documentation

You can find the docs [here](https://hrily.github.io/FileGopherServer).