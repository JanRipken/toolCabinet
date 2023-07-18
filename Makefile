CC=g++
CFLAGS=-c -Wall
TARGET=build/toolCabinet
LIBS = -Ljsoncpp/lib -Ijsoncpp/include -ljsoncpp

# Directory for test objects and binaries
TEST_DIR=build/tests

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

$(TEST_DIR)/cabinet_test.o: tests/cabinet_test.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include tests/cabinet_test.cpp -o $(TEST_DIR)/cabinet_test.o

$(TEST_DIR)/tool_test.o: tests/tool_test.cpp
	$(CC) $(CFLAGS) -Ijsoncpp/include tests/tool_test.cpp -o $(TEST_DIR)/tool_test.o

$(TEST_DIR)/cabinet_test: $(TEST_DIR)/cabinet_test.o build/cabinet.o build/tool.o
	$(CC) $(TEST_DIR)/cabinet_test.o build/cabinet.o build/tool.o -o $(TEST_DIR)/cabinet_test $(LIBS)

$(TEST_DIR)/tool_test: $(TEST_DIR)/tool_test.o build/tool.o
	$(CC) $(TEST_DIR)/tool_test.o build/tool.o -o $(TEST_DIR)/tool_test $(LIBS)

clean:
	rm -rf build/toolCabinet $(TEST_DIR)/*

run: $(TARGET)
	./$(TARGET)

test: $(TEST_DIR)/cabinet_test $(TEST_DIR)/tool_test
	./$(TEST_DIR)/cabinet_test
	./$(TEST_DIR)/tool_test

.PHONY: all clean run test

