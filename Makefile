TARGET = main
CXX = g++
CXXFLAGS = -Wall -I include  #mostra erros e procura .h na pasta include

all: $(TARGET)

$(TARGET): build/Hospede.o build/Quartos.o build/Reserva.o build/Sistema.o build/main.o
	$(CXX) $^ -o $(TARGET)

build/Hospede.o: src/Hospede.cpp include/Hospede.h 
	$(CXX) $(CXXFLAGS) -c src/Hospede.cpp -o build/Hospede.o

build/Quartos.o: src/Quartos.cpp include/Quartos.h 
	$(CXX) $(CXXFLAGS) -c src/Quartos.cpp -o build/Quartos.o

build/Reserva.o: src/Reserva.cpp include/Reserva.h 
	$(CXX) $(CXXFLAGS) -c src/Reserva.cpp -o build/Reserva.o

build/Sistema.o: src/Sistema.cpp include/Sistema.h 
	$(CXX) $(CXXFLAGS) -c src/Sistema.cpp -o build/Sistema.o

build/main.o: main.cpp include/Hospede.h include/Quartos.h include/Reserva.h include/Sistema.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

clean:
	rm -f build/*.o build/main.o $(TARGET)

run: all
	./$(TARGET)