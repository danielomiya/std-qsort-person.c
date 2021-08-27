TARGET_BIN ?= ./app
SRC_DIR ?= ./src
DIST_DIR ?= ./build

C ?= gcc

SRCS := $(shell find $(SRC_DIR) -name *.c)
OBJS := $(SRCS:%=$(DIST_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIR := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIR))

CFLAGS ?= $(INC_FLAGS) -g -Wall -Wshadow -pedantic -ansi -MMD -MP

RM = rm -r
MKDIR_P = mkdir -p

all: $(DIST_DIR)/$(TARGET_BIN)

$(DIST_DIR)/$(TARGET_BIN): $(OBJS)
	$(MKDIR_P) $(dir $@)
	$(C) $(OBJS) -o $@

# C source
$(DIST_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(C) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(DIST_DIR)

-include $(DEPS)
