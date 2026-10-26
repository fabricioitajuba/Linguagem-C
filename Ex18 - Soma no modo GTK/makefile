# Nome do executável final
TARGET = Ex18

# Variáveis do compilador e flags
CC = gcc
CFLAGS = $(shell pkg-config --cflags gtk4)
LIBS = $(shell pkg-config --libs gtk4)

# Regra padrão (executada ao rodar apenas 'make')
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(TARGET).c
	$(CC) $(TARGET).c -o $(TARGET) $(CFLAGS) $(LIBS)

# Regra para limpar o executável gerado
clean:
	rm -f $(TARGET)
