CC=g++
CFLAGS=-c -Wall
TARGET=build/toolCabinet
LIBS = -Ljsoncpp/lib -Ijsoncpp/include -ljsoncpp

all: $(TARGET)

$(TARGET): build/toolCabinet.o build/tool.o build/cabinet.o
	$(CC) build/toolCabinet.o build/tool.o build/cabinet.o -o $(TARGET) $(LIBS)

build/toolCabinet.o: src/app.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include src/app.cpp -o build/toolCabinet.o

build/helper.o: src/helper.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include src/helper.cpp -o build/helper.o

build/tool.o: src/tool.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include src/tool.cpp -o build/tool.o

build/cabinet.o: src/cabinet.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include src/cabinet.cpp -o build/cabinet.o

clean:
	rm -rf build toolCabinet

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run






