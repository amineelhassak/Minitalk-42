# 🚀 Minitalk - Unix Signal Communication

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Unix](https://img.shields.io/badge/Unix-000000?style=for-the-badge&logo=unix&logoColor=white)
![Signal](https://img.shields.io/badge/Signals-FF6B6B?style=for-the-badge&logo=linux&logoColor=white)

**A client-server communication system using Unix signals**

[![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![License](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge)](LICENSE)

</div>

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [How It Works](#-how-it-works)
- [Installation](#-installation)
- [Usage](#-usage)
- [Project Structure](#-project-structure)
- [Technical Details](#-technical-details)
- [Bonus Features](#-bonus-features)
- [Contributing](#-contributing)
- [License](#-license)

---

## 🎯 Overview

**Minitalk** is a Unix signal-based communication system that allows two processes to exchange messages using only signals (SIGUSR1 and SIGUSR2). This project demonstrates advanced Unix system programming concepts including signal handling, process communication, and bit manipulation.

The project consists of two main components:
- **Server**: Receives and displays messages from clients
- **Client**: Sends messages to a server using its PID

---

## ✨ Features

### Core Features
- 🔄 **Signal-based Communication**: Uses SIGUSR1 and SIGUSR2 for data transmission
- 📡 **Real-time Message Transfer**: Bit-by-bit transmission with acknowledgment
- 🛡️ **Error Handling**: Comprehensive error checking and validation
- 🎨 **Colored Output**: Beautiful terminal interface with colored messages
- 🔢 **PID Validation**: Ensures valid process IDs before communication

### Bonus Features
- ✅ **Message Confirmation**: Server acknowledges successful message reception
- 🌍 **Unicode Support**: Handles multi-byte characters and Unicode
- 🔄 **Multiple Client Support**: Server can handle multiple clients simultaneously
- 📊 **Connection Status**: Real-time connection status display

---

## 🔧 How It Works

### Signal Communication Protocol
1. **Bit Transmission**: Each character is transmitted bit by bit
   - `SIGUSR1` = Bit value 1
   - `SIGUSR2` = Bit value 0

2. **Character Assembly**: Server reconstructs characters from received bits

3. **Message Flow**:
   ```
   Client → Server: Send character bits
   Server → Client: Acknowledge reception (bonus)
   ```

### Bit Manipulation
```c
// Client sends bit
if ((c >> count_shift) & 1)
    kill(pid, SIGUSR1);  // Send 1
else
    kill(pid, SIGUSR2);  // Send 0

// Server receives bit
if (signal == SIGUSR1)
    i |= 0x01 << count;  // Set bit to 1
```

---

## 🚀 Installation

### Prerequisites
- Unix-like operating system (Linux, macOS)
- GCC compiler
- Make utility

### Build Instructions

1. **Clone the repository**
   ```bash
   git clone <your-repo-url>
   cd Minitalk-42
   ```

2. **Build the project**
   ```bash
   # Build mandatory version
   make
   
   # Build with bonus features
   make bonus
   ```

3. **Clean build files**
   ```bash
   make clean      # Remove executables
   make fclean     # Remove all build files
   make re         # Rebuild everything
   ```

---

## 📖 Usage

### Basic Usage

1. **Start the server**
   ```bash
   ./serveur
   ```
   The server will display its PID and wait for connections.

2. **Send a message from client**
   ```bash
   ./client <server_pid> "Your message here"
   ```

### Example Session

```bash
# Terminal 1 - Start server
$ ./serveur
          Connection Established 

  Server's PID IS :      ❤====> 12345   <=====❤

>>

# Terminal 2 - Send message
$ ./client 12345 "Hello, World!"
       Client's PID IS :❤====>   67890   <=====❤

# Terminal 1 - Server receives message
>> Hello, World!
```

### Error Handling

The program handles various error conditions:
- ❌ Invalid PID format
- ❌ Non-existent server process
- ❌ Wrong number of arguments
- ❌ Signal transmission failures

---

## 📁 Project Structure

```
Minitalk-42/
├── 📄 serveur.c              # Server implementation
├── 📄 client.c               # Client implementation
├── 📄 serveur_bonus.c        # Server with bonus features
├── 📄 client_bonus.c         # Client with bonus features
├── 📄 minitalk.h             # Main header file
├── 📄 minitalk_bonus.h       # Bonus header file
├── 📄 msg.h                  # Message definitions
├── 📄 Makefile               # Build configuration
├── 📁 ft_printf/             # Custom printf implementation
│   ├── ft_printf.c
│   ├── ft_printf.h
│   └── Makefile
└── 📁 mylibft/               # Custom library functions
    ├── libft.h
    ├── ft_*.c files
    └── Makefile
```

---

## 🔬 Technical Details

### Signal Handling
- Uses `sigaction()` for reliable signal handling
- Implements `SA_SIGINFO` flag for additional signal information
- Handles signal interruption gracefully

### Unicode Support
```c
// Multi-byte character handling
if (c >= 192 && c <= 223) nbrbyte = 2;  // 2-byte UTF-8
else if (c >= 224 && c <= 239) nbrbyte = 3;  // 3-byte UTF-8
else if (c >= 240) nbrbyte = 4;  // 4-byte UTF-8
```

### Memory Management
- Static variables for maintaining state across signal calls
- Proper memory cleanup and initialization
- No memory leaks or undefined behavior

### Performance Optimizations
- Minimal delay between signal transmissions (200μs)
- Efficient bit manipulation using bitwise operations
- Optimized character reconstruction

---

## 🎁 Bonus Features

### Enhanced Client-Server Communication
- **Message Acknowledgment**: Server confirms message reception
- **Connection Status**: Real-time connection feedback
- **Multiple Client Support**: Handle multiple clients simultaneously

### Improved User Experience
- **Colored Output**: Enhanced visual feedback
- **Better Error Messages**: More descriptive error handling
- **Unicode Support**: Full UTF-8 character support

### Advanced Signal Handling
- **Signal Queuing**: Proper signal ordering
- **Interruption Recovery**: Graceful handling of signal interruptions
- **Process Validation**: Enhanced PID verification

---

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

### Development Guidelines
1. Follow the existing code style
2. Add appropriate error handling
3. Include comments for complex logic
4. Test thoroughly before submitting

---

## 📄 License

This project is part of the 42 School curriculum and follows the 42 coding standards. The code is provided for educational purposes.

---

## 👨‍💻 Author

**Amel Has** - [42 School](https://42.fr)

---

<div align="center">

**Made with ❤️ for Unix system programming**

[⬆ Back to top](#-minitalk---unix-signal-communication)

</div>