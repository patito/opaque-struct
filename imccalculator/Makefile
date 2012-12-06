CC 		:= gcc
CFLAGS 	:= -W -Wall -Werror -ggdb
LDFLAGS :=#
RM 		:= rm -f
LIBS	:=#
INCLUDE_DIRS :=#-I include

SOURCE_DIR 	:= src
OBJECT_DIR	:= bin
SOURCES		:= $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS		:= $(patsubst $(SOURCE_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SOURCES))

TARGET	:= imccalc


all: validate $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE_DIRS) $(LIBS) -o $(TARGET)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(LIBS) -c $^ -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)

validate:
	@test -d $(OBJECT_DIR) || mkdir -p $(OBJECT_DIR)
