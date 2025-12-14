# Define variables
CC = gcc
CFLAGS =  -Wall -g -std=c11 
TARGET =  pwm 
SOURCES = pwm.c 
OBJECTS = $(SOURCES:.c=.o) # Automatically creates a list of .o files

all: $(TARGET) 

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) -lX11

# Rule to create object files from C source files using built-in rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

modex: $(TARGET) 
	chmod +x $(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
