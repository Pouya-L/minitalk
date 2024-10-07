# push_swap

## Project Overview
The minitalk project involves creating an a server/client system that uses UNIX signals for communication. The server displays its PID and receives decrypted signals as characters, while the client encrypts messages and sends true/false signals using SIGUSR1 or SIGUSR2 to the server's PID.

## Bonus
• The server acknowledges every message received by sending back a signal to the
client.
• Unicode characters must be supported.

## Getting Started

### Compiling
Run the following commands:

#### To compile
```
make
```
#### To remove objects
```
make clean
```
#### To remove objects and the binary file (program)
```
make fclean
```
#### To re-compile
```
make re
```
#### Usage
First you need to run the server which will show you its PID.
```
./server
```
<img width="422" alt="minitalk" src="https://github.com/user-attachments/assets/5a051474-59f3-4b52-b76a-af0ed544a617">

Then you can run the client followed by the pid of the server
```
./client 450 "PUT YOUR TEXT HERE"
```


[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)
