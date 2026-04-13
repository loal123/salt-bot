# Stage 1: The Build Environment
FROM heroku/heroku:24-build AS build

# Install build tools
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    libssl-dev \
    zlib1g-dev \
    wget

# Install D++ (using the exact link from your Aptfile)
RUN wget https://github.com/brainboxdotcc/DPP/releases/download/v10.0.35/libdpp-10.0.35-linux-x64.deb \
    && dpkg -i libdpp-10.0.35-linux-x64.deb

# Copy your source code into the container
COPY . /app
WORKDIR /app

# Compile your code (this runs 'cmake .' and 'make')
RUN cmake . && make

# Stage 2: The Final Runner (keeps the image small)
FROM heroku/heroku:24
WORKDIR /app

# COPY THE BINARY: 
# Replace 'YOUR_BINARY_NAME' with the name from your CMakeLists.txt
COPY --from=build /app/salt_bot .

# Start the bot
CMD ["./salt_bot"]
