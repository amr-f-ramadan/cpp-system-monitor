#!/bin/bash

# Docker Helper Script for C++ System Monitor

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PROJECT_NAME="cpp-system-monitor"
IMAGE_NAME="system-monitor"

print_usage() {
    echo "Usage: $0 [COMMAND]"
    echo ""
    echo "Commands:"
    echo "  build       Build the Docker image"
    echo "  run         Run the container interactively"
    echo "  start       Start container using docker-compose"
    echo "  stop        Stop container using docker-compose"
    echo "  clean       Remove container and image"
    echo "  logs        Show container logs"
    echo "  shell       Open shell in running container"
    echo "  help        Show this help message"
}

build_image() {
    echo -e "${GREEN}Building Docker image...${NC}"
    docker build -t $IMAGE_NAME .
    echo -e "${GREEN}Image built successfully!${NC}"
}

run_container() {
    echo -e "${GREEN}Running container interactively...${NC}"
    docker run -it --rm \
        --name $PROJECT_NAME \
        -v /proc:/proc:ro \
        --privileged \
        -e TERM=xterm-256color \
        $IMAGE_NAME
}

start_compose() {
    echo -e "${GREEN}Starting container with docker-compose...${NC}"
    docker-compose up -d
    echo -e "${GREEN}Container started! Use 'docker exec -it $PROJECT_NAME bash' to access shell${NC}"
}

stop_compose() {
    echo -e "${YELLOW}Stopping container...${NC}"
    docker-compose down
    echo -e "${GREEN}Container stopped!${NC}"
}

clean_all() {
    echo -e "${YELLOW}Cleaning up containers and images...${NC}"
    
    # Stop and remove container if running
    if docker ps -a --format 'table {{.Names}}' | grep -q $PROJECT_NAME; then
        docker stop $PROJECT_NAME 2>/dev/null || true
        docker rm $PROJECT_NAME 2>/dev/null || true
    fi
    
    # Remove docker-compose containers
    docker-compose down 2>/dev/null || true
    
    # Remove image
    if docker images --format 'table {{.Repository}}' | grep -q $IMAGE_NAME; then
        docker rmi $IMAGE_NAME
    fi
    
    echo -e "${GREEN}Cleanup completed!${NC}"
}

show_logs() {
    echo -e "${GREEN}Showing container logs...${NC}"
    docker-compose logs -f
}

open_shell() {
    echo -e "${GREEN}Opening shell in container...${NC}"
    docker exec -it $PROJECT_NAME bash
}

case "$1" in
    build)
        build_image
        ;;
    run)
        run_container
        ;;
    start)
        start_compose
        ;;
    stop)
        stop_compose
        ;;
    clean)
        clean_all
        ;;
    logs)
        show_logs
        ;;
    shell)
        open_shell
        ;;
    help|--help|-h)
        print_usage
        ;;
    "")
        echo -e "${RED}Error: No command specified${NC}"
        echo ""
        print_usage
        exit 1
        ;;
    *)
        echo -e "${RED}Error: Unknown command '$1'${NC}"
        echo ""
        print_usage
        exit 1
        ;;
esac
