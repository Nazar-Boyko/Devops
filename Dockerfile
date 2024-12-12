# Step 1: Use a temporary image for building the application
FROM ubuntu:20.04 as builder

# Set non-interactive frontend for apt
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies needed to build the software
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    libboost-all-dev \
    git \
    && rm -rf /var/lib/apt/lists/*

# Clone the GitHub repo (replace with actual URL of your public repo)
RUN git clone https://github.com/Nazar-Boyko/Devops.git /app

# Set the working directory to where the application code is located
WORKDIR /app

# Build the application
RUN g++ -std=c++11 -o http_server http_server.cpp series.cpp -lboost_system -pthread

# Step 2: Copy the compiled executable into an Alpine-based image
FROM alpine:latest

# Install runtime dependencies
RUN apk add --no-cache libstdc++ libgcc libboost-system

# Copy the built executable from the builder image
COPY --from=builder /app/http_server /usr/local/bin/http_server

# Expose the port the server will run on
EXPOSE 8080

# Run the server
CMD ["http_server"]

