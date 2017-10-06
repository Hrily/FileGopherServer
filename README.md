# FileGopherServer

FileGopherServer is a Gopher server which serves the file listing.

I've tried as much as possible to align the implementation with the Gopher [RFC 1436](https://www.ietf.org/rfc/rfc1436.txt).
This server is non-gopher+, but supports gateway for gopher+ clients as a forward compatibility.

## About Gopher

Gopher is a pre-HTTP protocol for browsing the internet. It is easy to use and light-weight, even for implementation. To know more about Gopher visit wiki page [Wiki](https://en.wikipedia.org/wiki/Gopher_\(protocol\) "Gopher protocol - Wikipedia").

## Compilation

```
$ g++ -o server server.cpp -std=gnu++11
```

## Usage

```
$ ./server <directory-to-serve>
```

For example, to serve current directory:

```
$ ./server .
```

## TODO

- [ ] Implement efficient method to check a file is text or binary.
- [ ] Implement efficient method to send file to client.
- [ ] Add option to list hiddens files.

## Documentation

You can find the docs [here](https://hrily.github.io/FileGopherServer).