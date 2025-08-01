# CppND-System-Monitor

Starter code for System Monitor Project in the Object Oriented Programming Course of the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). 

Follow along with the classroom lesson to complete the project!

![System Monitor](images/monitor.png)

## Udacity Linux Workspace
[Udacity](https://www.udacity.com/) provides a browser-based Linux [Workspace](https://engineering.udacity.com/creating-a-gpu-enhanced-virtual-desktop-for-udacity-497bdd91a505) for students. 

You are welcome to develop this project on your local machine, and you are not required to use the Udacity Workspace. However, the Workspace provides a convenient and consistent Linux development environment we encourage you to try.

## ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library that facilitates text-based graphical output in the terminal. This project relies on ncurses for display output.

Within the Udacity Workspace, `.student_bashrc` automatically installs ncurses every time you launch the Workspace.

If you are not using the Workspace, install ncurses within your own Linux environment: `sudo apt install libncurses5-dev libncursesw5-dev`

## Make
This project uses [Make](https://www.gnu.org/software/make/). The Makefile has four targets:
* `build` compiles the source code and generates an executable
* `format` applies [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) to style the source code
* `debug` compiles the source code and generates an executable, including debugging symbols
* `clean` deletes the `build/` directory, including all of the build artifacts

## Instructions

1. Clone the project repository: `git clone https://github.com/udacity/CppND-System-Monitor-Project-Updated.git`

2. Build the project: `make build`

3. Run the resulting executable: `./build/monitor`
![Starting System Monitor](images/starting_monitor.png)

4. Follow along with the lesson.

5. Implement the `System`, `Process`, and `Processor` classes, as well as functions within the `LinuxParser` namespace.

6. Submit!

## Docker Support

This project includes Docker support for easy development and deployment across different environments.

### Prerequisites
- [Docker](https://docs.docker.com/get-docker/)
- [Docker Compose](https://docs.docker.com/compose/install/) (optional, for easier container management)

### Quick Start with Docker

#### Option 1: Using the Helper Script (Recommended)
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

#### Option 2: Manual Docker Commands

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

#### Option 3: Using Docker Compose

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

### Notes

- The container requires privileged access to read system information from `/proc`
- The container mounts the host's `/proc` directory for system monitoring capabilities
- All necessary dependencies (CMake, ncurses, build tools) are pre-installed in the container