CC ?= pcc
ifeq ($(CC), pcc)
	CFLAGS := -std=c99 -O3 -Wc,-Werror=implicit-function-declaration,-Werror=missing-prototypes,-Werror=pointer-sign,-Werror=sign-compare,-Werror=strict-prototypes,-Werror=shadow

else ifeq ($(CC), gcc)
	CFLAGS := -std=c99 -O3 -Wall -Wextra -Wpedantic -Wstrict-aliasing -Wcast-align -Wconversion -Wsign-conversion -Wshadow -Wswitch-enum
else
	$(error unsupported compiler : $(CC))
endif
SRC_DIR := source
INC_DIR := include
BIN_DIR := binary

SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/logging/*.c)
HDR_FILES := $(wildcard $(INC_DIR)/*.h) $(wildcard $(INC_DIR)/logging/*.h)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC_FILES))

INCLUDE_FLAGS := -I$(INC_DIR)
STUMAN := stuman.bin

POINTER_SYM := "\e[91m->\e[0m"

$(STUMAN) : $(BIN_DIR) $(OBJ_FILES) $(HDR_FILES)
	@/usr/bin/echo -e $(POINTER_SYM) "\e[96mlinking modules into" $@ "\e[0m"
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LIBCRC)
	@/usr/bin/echo -e $(POINTER_SYM) "\e[93mstrip" $@ "\e[0m"

$(BIN_DIR) :
	@mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/%.h
	@/usr/bin/echo -e $(POINTER_SYM) "\e[93mcompiling module" $< "\e[0m"
	$(CC) -c $(CFLAGS) $(INCLUDE_FLAGS) -o $@ $<

clean :
	rm $(wildcard $(BIN_DIR)/*.o) $(wildcard $(STUMAN))

clear : clean
