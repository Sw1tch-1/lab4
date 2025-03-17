FROM osx-cross:latest
RUN brew install cmake boost
WORKDIR /app
COPY . .
RUN cmake . && make
CMD ["./server"]
