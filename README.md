# C++ System Monitor with Docker Support

A real-time Linux system monitor implemented in C++17 as part of the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). This project demonstrates object-oriented programming principles, modern C++ practices, and containerized development workflows.

![System Monitor](images/monitor.png)

## 🚀 My Contributions

This repository extends the original [Udacity starter code](https://github.com/udacity/CppND-System-Monitor-Project-Updated) with significant enhancements:

### ✨ Core Implementation (Complete)
- **Fully implemented `System` class** - Manages system-wide information and process collection
- **Complete `Process` class** - Handles individual process data with CPU usage, memory, and process details
- **Implemented `Processor` class** - Calculates real-time CPU utilization
- **Complete `LinuxParser` namespace** - Efficient parsing of Linux `/proc` filesystem for system and process information
- **Fully functional system monitor** - Working real-time display similar to `htop`
- **Tested and verified implementation** - All core functionality working correctly

### ✨ Docker & Development Environment
- **Complete Docker containerization** with Ubuntu 22.04 base image
- **VS Code Dev Container configuration** with automatic extension installation
- **Cross-platform development support** - works on Windows, Mac, and Linux
- **Docker Compose orchestration** for easy container management
- **Helper scripts** for streamlined Docker operations

### ✨ Modern Development Workflow
- **Automated build system** with CMake and Make integration
- **Code formatting** with clang-format configuration
- **Enhanced documentation** with comprehensive setup instructions
- **Git configuration** with proper .gitignore for C++ projects

### ✨ Project Structure Improvements
- Organized development environment with proper tooling
- Comprehensive README with multiple deployment options
- Production-ready containerization for consistent builds

## 📚 About This Project

**Source**: This project is based on the starter code from the [Udacity C++ System Monitor Project](https://github.com/udacity/CppND-System-Monitor-Project-Updated), which is part of the Object Oriented Programming course in the Udacity C++ Nanodegree Program.

**Status**: **✅ COMPLETED** - All core functionality has been implemented and tested. This is a fully functional system monitor.

**Implementation**: The `System`, `Process`, and `Processor` classes have been fully implemented, along with all functions within the `LinuxParser` namespace, creating a complete system monitor similar to `htop`.

**Educational Focus**: Demonstrates object-oriented design principles, modern C++ practices (C++17), Linux system programming, and real-world software development workflows including containerization and DevOps practices.

## 💻 Development Environment Options

### Original Udacity Approach
[Udacity](https://www.udacity.com/) provides a browser-based Linux [Workspace](https://engineering.udacity.com/creating-a-gpu-enhanced-virtual-desktop-for-udacity-497bdd91a505) for students in the C++ Nanodegree program. While this provides a convenient and consistent Linux development environment, this enhanced version offers modern alternatives with Docker containerization.

### Enhanced Docker-Based Development (Recommended)
This repository provides a superior development experience with Docker containers that work across all platforms, ensuring consistent builds and eliminating environment setup issues.

## 🎯 Project Implementation

This project implements a **fully functional** real-time system monitor with the following core components:

### ✅ Implemented Core Classes (Complete)
- **`System` class**: ✅ Manages overall system information and process collection
- **`Process` class**: ✅ Represents individual processes with CPU usage, memory, and process details
- **`Processor` class**: ✅ Handles CPU utilization calculations
- **`LinuxParser` namespace**: ✅ Parses `/proc` filesystem for system and process information

### 🚀 Working Features
- ✅ Real-time process monitoring with CPU and memory usage
- ✅ System information display (uptime, total processes, running processes)
- ✅ ncurses-based terminal interface similar to `htop`
- ✅ Efficient parsing of Linux `/proc` filesystem
- ✅ Sorted process list by CPU usage
- ✅ Memory usage tracking and display
- ✅ Process state monitoring

## 🛠️ Dependencies and Libraries

### ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library that facilitates text-based graphical output in the terminal. This project relies on ncurses for display output.

**Installation options:**
- **Docker (Recommended)**: Automatically installed in the container
- **Ubuntu/Debian**: `sudo apt install libncurses5-dev libncursesw5-dev`
- **macOS**: `brew install ncurses`

### Build System
This project uses [CMake](https://cmake.org/) and [Make](https://www.gnu.org/software/make/). The Makefile has four targets:
* `build` compiles the source code and generates an executable
* `format` applies [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) to style the source code
* `debug` compiles the source code and generates an executable, including debugging symbols
* `clean` deletes the `build/` directory, including all of the build artifacts

## 🚀 Getting Started

### Quick Start (Using Docker - Recommended)

1. **Clone this enhanced repository:**
   ```bash
   git clone https://github.com/amr-f-ramadan/cpp-system-monitor.git
   cd cpp-system-monitor
   ```

2. **Option A: VS Code Dev Container (Best Experience)**
   - Install [VS Code](https://code.visualstudio.com/) and [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
   - Open project in VS Code: `code .`
   - Click "Reopen in Container" when prompted
   - All dependencies and extensions are automatically installed!

3. **Option B: Docker Helper Script**
   ```bash
   ./docker-helper.sh build
   ./docker-helper.sh run
   ```

### Traditional Build (Local Environment)

1. **Install dependencies:**
   ```bash
   # Ubuntu/Debian
   sudo apt install build-essential cmake libncurses5-dev libncursesw5-dev
   
   # macOS
   brew install cmake ncurses
   ```

2. **Build and run:**
   ```bash
   make build
   ./build/monitor
   ```

![Starting System Monitor](images/starting_monitor.png)

### ✅ Project Status

**This project is COMPLETE and FULLY FUNCTIONAL!** 

All Udacity requirements have been successfully implemented:

1. ✅ **`System` class implemented** - Manages system-wide information
2. ✅ **`Process` class implemented** - Handles individual process data
3. ✅ **`Processor` class implemented** - Calculates CPU utilization
4. ✅ **`LinuxParser` namespace completed** - Parses system information from `/proc`

**Result**: A fully working system monitor that displays real-time system and process information.

**Original Udacity Instructions**: The base project structure and requirements come from the [official Udacity repository](https://github.com/udacity/CppND-System-Monitor-Project-Updated).

## Docker Support

This project includes Docker support for easy development and deployment across different environments.

### Prerequisites
- [Docker](https://docs.docker.com/get-docker/)
- [Docker Compose](https://docs.docker.com/compose/install/) (optional, for easier container management)
- [VS Code](https://code.visualstudio.com/) with [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) (for integrated development)

### Development Options

#### Option 1: VS Code Dev Containers (Recommended for Development)
The easiest way to develop with this project is using VS Code Dev Containers, which automatically installs all necessary extensions including CMake Tools:

1. Install the [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) in VS Code
2. Open the project folder in VS Code
3. Click "Reopen in Container" when prompted, or press `Ctrl+Shift+P` and select "Dev Containers: Reopen in Container"
4. VS Code will automatically:
   - Build the Docker container
   - Install C++ and CMake extensions
   - Configure the development environment
   - Build the project

**Included Extensions:**
- CMake Tools
- C/C++ Extension Pack
- Clang-Format
- Makefile Tools

#### Option 2: Using the Helper Script
The project includes a helper script that simplifies Docker operations:

```bash
# Build the Docker image
./docker-helper.sh build

# Run the system monitor interactively
./docker-helper.sh run

# Or start with docker-compose (runs in background)
./docker-helper.sh start

# Stop the container
./docker-helper.sh stop

# Clean up containers and images
./docker-helper.sh clean

# Show available commands
./docker-helper.sh help
```

#### Option 3: Manual Docker Commands

```bash
# Build the Docker image
docker build -t system-monitor .

# Run the container interactively
docker run -it --rm \
    --name cpp-system-monitor \
    -v /proc:/proc:ro \
    --privileged \
    -e TERM=xterm-256color \
    system-monitor
```

#### Option 4: Using Docker Compose

```bash
# Start the container
docker-compose up -d

# Access the container shell
docker exec -it cpp-system-monitor bash

# Stop the container
docker-compose down
```

### Docker Configuration Files

- `Dockerfile`: Defines the container image with all necessary dependencies
- `docker-compose.yml`: Defines services and container configuration
- `.dockerignore`: Specifies files to exclude from the Docker build context
- `docker-helper.sh`: Helper script for common Docker operations
- `.devcontainer/devcontainer.json`: VS Code Dev Container configuration with auto-installed extensions

### Notes

- The container requires privileged access to read system information from `/proc`
- The container mounts the host's `/proc` directory for system monitoring capabilities
- All necessary dependencies (CMake, ncurses, build tools) are pre-installed in the container

## 🎓 Learning Objectives & Skills Demonstrated

This **completed project** showcases several key competencies in modern C++ development:

### C++ & Object-Oriented Programming
- **C++17 features** and modern C++ best practices
- **Object-oriented design** with proper encapsulation and abstraction implemented
- **Memory management** and efficient resource usage in practice
- **STL containers and algorithms** for real-time data processing
- **Complete class implementations** solving real-world problems

### System Programming
- **Linux system calls** and `/proc` filesystem parsing (fully implemented)
- **Process monitoring** and system resource tracking (working implementation)
- **Real-time data processing** for continuous monitoring (functional)
- **Terminal-based UI** development with ncurses (complete interface)

### Software Engineering & DevOps
- **Containerization** with Docker for consistent development environments
- **Build automation** with CMake and Make
- **Code formatting** and style consistency
- **Documentation** and project organization
- **Version control** with Git and GitHub

### Development Workflows
- **Cross-platform development** using containers
- **IDE integration** with VS Code Dev Containers
- **Automated tooling** for development productivity
- **Modern C++ project structure** and best practices

## 📄 License & Acknowledgments

**Base Project**: This implementation is based on the starter code provided by [Udacity](https://www.udacity.com/) as part of the [C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

**Original Repository**: [CppND-System-Monitor-Project-Updated](https://github.com/udacity/CppND-System-Monitor-Project-Updated)

**Enhancements**: Docker containerization, development environment setup, and modern C++ tooling added by [Amr Ramadan](https://github.com/amr-f-ramadan).

---

**🎯 This project demonstrates proficiency in C++17, object-oriented programming, system programming, and modern development workflows suitable for software engineering roles.**