CC=/usr/bin/g++
FLAGS=-g -fno-rtti -std=c++11 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

BIN=./bin
SRC=../src
EXDIR=../example
OBJS=$(BIN)/objs
EXOBJ=$(OBJS)/example
LIBS=$(BIN)/libs

SOURCES=$(wildcard $(SRC)/*.cpp)
OBJECTS=$(patsubst %, $(OBJS)/%, $(notdir $(SOURCES:%.cpp=%.o)))

# Explcit Type Id examples
ID_EXSRC=$(wildcard $(EXDIR)/explicit_typeid/*.cpp)
ID_EXOBJS=$(patsubst %, $(EXOBJ)/explicit_typeid/%,$(notdir $(ID_EXSRC:%.cpp=%.o)))
ID_EXAMPLES=$(patsubst %, $(BIN)/explicit_typeid/%, $(notdir $(ID_EXSRC:%.cpp=%)))

# Typebuffer examples
BU_EXSRC=$(wildcard $(EXDIR)/typebuffer/*.cpp)
BU_EXOBJS=$(patsubst %, $(EXOBJ)/typebuffer/%, $(notdir $(BU_EXSRC:%.cpp=%.o)))
BU_EXAMPLES=$(patsubst %, $(BIN)/typebuffer/%, $(notdir $(BU_EXSRC:%.cpp=%)))

# Typesystem example

DLIB=$(LIBS)/lib.so
SLIB=$(LIBS)/lib.a

.PHONY: clean all dirs lib example

$(OBJS)/%.o: $(SRC)/%.cpp
	$(CC) -o $@ -c $< -fPIC $(FLAGS) 2> object.log

# Explicit Type Id
$(EXOBJ)/explicit_typeid/%.o: $(EXDIR)/explicit_typeid/%.cpp
	$(CC) -c $< -o $@ $(FLAGS) 2> example_object.log

$(BIN)/explicit_typeid/%: $(EXOBJ)/explicit_typeid/%.o
	$(CC) $< -o $@ $(SLIB) 2> example.log

# Typebuffer
$(EXOBJ)/typebuffer/%.o: $(EXDIR)/typebuffer/%.cpp
	$(CC) -c $< -o $@ $(FLAGS) 2> example_object.log

$(BIN)/typebuffer/%: $(EXOBJ)/typebuffer/%.o
	$(CC) $< -o $@ $(SLIB) 2> example.log

define cc-lib_dynamic
$(CC) $^ -shared $(FLAGS) -o $@ 2> dyncamiclib.log
endef

define cc-lib_static
ar rvs $@ $^ 2> staticlib.log
endef

all: dirs $(SLIB) $(DLIB) $(ID_EXAMPLES) $(BU_EXAMPLES)

$(SLIB): $(OBJECTS)
	$(cc-lib_static)

$(DLIB): $(OBJECTS)
	$(cc-lib_dynamic)

$(OBJECTS): $(SOURCES)

# Explicit Type Id
$(ID_EXAMPLES): $(ID_EXOBJS)

$(ID_EXOBJS): $(ID_EXSRC)

# Typebuffer
$(BU_EXAMPLES): $(BU_EXOBJS)

$(BU_EXOBJS): $(BU_EXSRC)

clean:
	rm -rf $(BIN)
	rm ./*.log

dirs:
	mkdir -p $(BIN)
	mkdir -p $(BIN)/explicit_typeid
	mkdir -p $(BIN)/typebuffer
	mkdir -p $(OBJS)
	mkdir -p $(LIBS)
	mkdir -p $(EXOBJ)
	mkdir -p $(EXOBJ)/explicit_typeid
	mkdir -p $(EXOBJ)/typebuffer

lib: $(SLIB) $(DLIB)
