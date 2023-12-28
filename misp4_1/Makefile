CXX = g++
CXXFLAGS = -std=c++11 -Wall -O3
LDFLAGS = -lcryptopp

TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)