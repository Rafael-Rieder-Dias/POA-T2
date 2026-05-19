# Compilador
CXX = g++

# Nome do executável
TARGET = multi_testes.out

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
SRC = MultiTestes.cpp PisoBar.cpp Funcoes.cpp

# Objetos
OBJ = $(SRC:.cpp=.o)

# Regra principal
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compilação dos .cpp
%.o: %.cpp PisoBar.hpp Funcoes.hpp
	$(CXX) $(CXXFLAGS) -c $<

# Limpeza
clean:
	rm -f $(OBJ) $(TARGET)