# File Hosting Server

This is my first server / client project in C

The program will allow you to send files from Client to a Server


## Features

- Send a file to a server
- Get a direct download link of your file
- Can support multiple client connections


## Installation

Server side: Download 'Server' files

```bash
    make
```

Client side: Download 'Client' files

```bash
    make
```
## Deployment

To deploy Server move the ./server application to your var/www/html directory then

```bash
  install screen on your server (Debian : apt install screen) (Centos : yum install screen)
  run 'screen ./server'
```
## Usage/Examples

```javascript
To run client make sure server is running first then
./client filename (exemple: ./client sample.jpg)
```

