# Compilador
CXX = g++

# Nome do executável
TARGET = a.out

# Flags de compilação
CXXFLAGS = -std=c++20 \
           -O3 \
           -march=native \
           -flto \
           -funroll-loops \
           -ffast-math \
           -pipe \
           -Wall \
           -Wextra

# Arquivos fonte
SRC = RafaelRiederDiasT2.cpp PisoBar.cpp

# Objetos
OBJ = $(SRC:.cpp=.o)

# Regra principal
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compilação dos .cpp
%.o: %.cpp PisoBar.hpp
	$(CXX) $(CXXFLAGS) -c $<

# Limpeza
clean:
	rm -f $(OBJ) $(TARGET)