# Variáveis
CXX = g++
CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = .
OBJ_DIR = obj

# Lista de arquivos-fonte
SRC = $(wildcard $(SRC_DIR)/*.cpp) \
      $(wildcard $(SRC_DIR)/Estados/*.cpp) \
      $(wildcard $(SRC_DIR)/Fases/*.cpp) \
      $(wildcard $(SRC_DIR)/Entidades/*.cpp) \
      $(wildcard $(SRC_DIR)/Entidades/Personagem/*.cpp) \
      $(wildcard $(SRC_DIR)/Entidades/Obstaculos/*.cpp) \
      $(wildcard $(SRC_DIR)/Observadores/*.cpp) \
      $(wildcard $(SRC_DIR)/Gerenciadores/*.cpp) \
      $(wildcard $(SRC_DIR)/Listas/*.cpp) 

# Lista de arquivos-objeto
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Regra padrão
all: $(OBJ_DIRS) jogo

# Diretórios de objetos
OBJ_DIRS = $(OBJ_DIR) $(OBJ_DIR)/Estados $(OBJ_DIR)/Fases $(OBJ_DIR)/Entidades/Personagem $(OBJ_DIR)/Entidades/Obstaculos $(OBJ_DIR)/Observadores $(OBJ_DIR)/Gerenciadores $(OBJ_DIR)/Listas 

# Regra para criar o diretório de objetos
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIRS)

# Regra para compilar o executável
jogo: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Regra para compilar arquivos-objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c -o $@ $<

# Limpeza
clean:
	rm -rf $(OBJ_DIR) jogo

.PHONY: all clean
