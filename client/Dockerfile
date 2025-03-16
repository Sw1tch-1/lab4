FROM ubuntu:latest
RUN apt update && apt install -y g++ cmake libboost-all-dev libssl-dev
WORKDIR /app
COPY . .
RUN cmake . && make
CMD ["./client"]
