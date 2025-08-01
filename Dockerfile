# Use Ubuntu 22.04 as base image
FROM ubuntu:22.04

# Set environment variables to avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC

# Update package list and install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clang-format \
    libncurses5-dev \
    libncursesw5-dev \
    git \
    make \
    gcc \
    g++ \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /app

# Copy the project files to the container
COPY . .

# Create build directory
RUN mkdir -p build

# Build the project
RUN cd build && \
    cmake .. && \
    make

# Expose any ports if needed (not required for this application)
# EXPOSE 8080

# Set the default command to run the system monitor
CMD ["./build/monitor"]
