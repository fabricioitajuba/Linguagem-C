Nome = Ex08
# Variáveis para o compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Nome do executável final
TARGET = $(Nome)

# Regra padrão (executada ao digitar apenas 'make')
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(Nome).c
	$(CC) $(CFLAGS) $(Nome).c -o $(TARGET)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)
