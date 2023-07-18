CC=g++
CFLAGS=-c -Wall
TARGET=build/toolSorting
LIBS = -Ljsoncpp/lib -Ijsoncpp/include -ljsoncpp

all: $(TARGET)

$(TARGET): build/toolSorting.o build/tool.o build/cabinet.o
	$(CC) build/toolSorting.o build/tool.o build/cabinet.o -o $(TARGET) $(LIBS)

build/toolSorting.o: src/app.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include src/app.cpp -o build/toolSorting.o

build/tool.o: src/tool.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include src/tool.cpp -o build/tool.o

build/cabinet.o: src/cabinet.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include src/cabinet.cpp -o build/cabinet.o

clean:
	rm -rf build toolSorting

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run






