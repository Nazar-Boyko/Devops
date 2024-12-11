FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=ninonteractive
# Install dependencies
RUN apt-get update -y && apt-get install -y \
    apt-get install -y \
    g++ \
    libboost-all-dev \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code
COPY . .

# Build HTTP server
RUN g++ -std=c++11 -o http_server http_server.cpp series.cpp -lboost_system -pthread

# Expose port
EXPOSE 8080

# Run server
CMD ["./http_server"]

