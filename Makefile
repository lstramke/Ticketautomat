CXX := clang++
CXXFLAGS := -Weverything -std=c++17 -Wno-c++98-compat -Iheader
SRC_DIR := code
TEST_DIR := Tests

TARGET := Ticketautomat
TEST_TARGET := $(TEST_DIR)/TestRunner

SRC_FILES := einlesen.cpp geld.cpp geldliste.cpp main.cpp menue.cpp straßenbahn.cpp straßenbahnliste.cpp ticket.cpp
TEST_FILE := tests.cpp

OBJECTS := $(addprefix $(SRC_DIR)/, $(SRC_FILES:.cpp=.o))

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(SRC_DIR)/$(TEST_FILE) | $(TEST_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/$(TEST_FILE) -o $(TEST_TARGET)

$(TEST_DIR):
	mkdir -p $(TEST_DIR)

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET) $(TEST_TARGET)
