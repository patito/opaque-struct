CC 		:= gcc
CFLAGS 	:= -W -Wall -Werror -ggdb
LDFLAGS :=
RM 		:= rm -f

INCLUDE_DIRS := #-Isrc/

#adaptacao alterar
SOURCE_DIR 	:= src
SOURCES		:= $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS		:= $(patsubst %.c, %.o, $(SOURCES))

TARGET	:= lista


all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE_DIRS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $^ -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)


