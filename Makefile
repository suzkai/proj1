CXX = g++
CXXFLAGS = -std=c++17 -I ./include/
PATHS = -isystem /user/src/googletest/googletest/include -pthread /usr/lib/x86_64-linux-gnu/libgtest.a /usr/lib/x86_64-linux-gnu/libgtest_main.a

SRC_DIR = src
TEST_DIR = testsrc
OBJ_DIR = obj
BIN_DIR = bin

# -lgtest -lgtest_main
# -I ./include/

# SRC = $(SRC_DIR)/StringUtils.cpp include/StringUtils.h $(TEST_DIR)/StringUtilsTest.cpp
OBJ = $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/StringUtilsTest.o

EXEC = $(BIN_DIR)/teststrutils

all: dir $(EXEC) run

dir:
	mkdir -p obj
	mkdir -p bin

$(OBJ_DIR)/StringUtils.o: $(SRC_DIR)/StringUtils.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/StringUtils.cpp -o $(OBJ_DIR)/StringUtils.o

$(OBJ_DIR)/StringUtilsTest.o: $(TEST_DIR)/StringUtilsTest.cpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/StringUtilsTest.cpp -o $(OBJ_DIR)/StringUtilsTest.o

$(EXEC): bin $(OBJ)
	$(CXX) -std=c++17 -lgtest -lgtest_main -lpthread $(PATHS) -o $(EXEC) $(OBJ)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf obj bin

