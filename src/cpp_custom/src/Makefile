CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Idemo

SRC = main1.cpp \
      demo/engine/Engine.cpp \
      demo/setup/Setup.cpp \
      demo/database/DataBase.cpp
      # demo/communication/ros_Service.cpp \
      # demo/communication/serial_UART.cpp \
      # demo/statemachine/StateMachine.cpp

OBJ = $(SRC:.cpp=.o)
TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
