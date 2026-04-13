# Stage 1: Build
FROM heroku/heroku:24-build AS build
USER root
RUN apt-get update && apt-get install -y \
    cmake g++ libssl-dev zlib1g-dev libopus-dev libsodium-dev wget
RUN wget https://github.com/brainboxdotcc/DPP/releases/download/v10.0.35/libdpp-10.0.35-linux-x64.deb \
    && dpkg -i libdpp-10.0.35-linux-x64.deb
COPY . /app
WORKDIR /app
RUN cmake . && make

# Stage 2: Runner (The "Clean Room")
FROM heroku/heroku:24
USER root
WORKDIR /app

# --- IMPORTANT: We need these libraries here too! ---
RUN apt-get update && apt-get install -y \
    libopus0 libsodium23 libssl3 wget \
    && wget https://github.com/brainboxdotcc/DPP/releases/download/v10.0.35/libdpp-10.0.35-linux-x64.deb \
    && dpkg -i libdpp-10.0.35-linux-x64.deb \
    && rm libdpp-10.0.35-linux-x64.deb

# Copy the binary from the build stage
COPY --from=build /app/salt_bot .

# Start the bot
CMD ["./salt_bot"]
