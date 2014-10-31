CC=/usr/bin/g++
FLAGS=-g -fno-rtti -std=c++11 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

BIN=./bin
SRC=../src
EXDIR=../example
OBJS=$(BIN)/objs
EXOBJ=$(OBJS)/example
LIBS=$(BIN)/libs

# install dirs
INCDIR=/usr/local/include/typesystems
LIBDIR=/usr/local/lib

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

# Rewriter examples
RW_EXSRC=$(wildcard $(EXDIR)/rewriter/*.cpp)
RW_EXOBJS=$(patsubst %, $(EXOBJ)/rewriter/%, $(notdir $(RW_EXSRC:%.cpp=%.o)))
RW_EXAMPLES=$(patsubst %, $(BIN)/rewriter/%, $(notdir $(RW_EXSRC:%.cpp=%)))

# Typesystem example
TY_EXSRC=$(wildcard $(EXDIR)/typesystem/*.cpp)
TY_EXOBJS=$(patsubst %, $(EXOBJ)/typesystem/%, $(notdir $(TY_EXSRC:%.cpp=%.o)))
TY_EXAMPLES=$(patsubst %, $(BIN)/typesystem/%, $(notdir $(TY_EXSRC:%.cpp=%)))

MAJOR=0
MINOR=0
LIB=libtypesystems.so
DLIB=$(LIBS)/libtypesystems.so.$(MAJOR).$(MINOR)
SLIB=$(LIBS)/libtypesystems.a.$(MAJOR).$(MINOR)

.PHONY: clean all dirs lib example

$(OBJS)/%.o: $(SRC)/%.cpp
	$(CC) -o $@ -c $< -fPIC $(FLAGS) 2> object.log

# Explicit Type Id
$(EXOBJ)/explicit_typeid/%.o: $(EXDIR)/explicit_typeid/%.cpp
	$(CC) -c $< -o $@ $(FLAGS) 2> example_object.log

$(BIN)/explicit_typeid/%: $(EXOBJ)/explicit_typeid/%.o
	$(CC) $< -o $@ $(FLAGS) $(SLIB) 2> example.log

# Typebuffer
$(EXOBJ)/typebuffer/%.o: $(EXDIR)/typebuffer/%.cpp
	$(CC) -c $< -o $@ $(FLAGS) 2> example_object.log

$(BIN)/typebuffer/%: $(EXOBJ)/typebuffer/%.o
	$(CC) $< -o $@ $(FLAGS) $(SLIB) 2> example.log

# Rewriter
$(EXOBJ)/rewriter/%.o: $(EXDIR)/rewriter/%.cpp
	$(CC) -c $< -o $@ $(FLAGS) 2> example_object.log

$(BIN)/rewriter/%: $(EXOBJ)/rewriter/%.o
	$(CC) $< -o $@ $(FLAGS) $(SLIB) 2> example.log

# Typesystem
$(EXOBJ)/typesystem/%.o: $(EXDIR)/typesystem/%.cpp
	$(CC) -c $< -o $@ $(FLAGS) 2> example_object.log

$(BIN)/typesystem/%: $(EXOBJ)/typesystem/%.o
	$(CC) $< -o $@ $(FLAGS) $(SLIB) 2> example.log

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

# Rewriter
$(RW_EXAMPLES): $(RW_EXOBJS)

$(RW_EXOBJS): $(RW_EXSRC)

# Typesystem
$(TY_EXAMPLES): $(TY_EXOBJS)

$(TY_EXOBJS): $(TY_EXSRC)

clean:
	rm -rf $(BIN)
	rm ./*.log

dirs:
	mkdir -p $(BIN)
	mkdir -p $(BIN)/explicit_typeid
	mkdir -p $(BIN)/typebuffer
	mkdir -p $(BIN)/rewriter
	mkdir -p $(BIN)/typesystem
	mkdir -p $(OBJS)
	mkdir -p $(LIBS)
	mkdir -p $(EXOBJ)
	mkdir -p $(EXOBJ)/explicit_typeid
	mkdir -p $(EXOBJ)/typebuffer
	mkdir -p $(EXOBJ)/typesystem
	mkdir -p $(EXOBJ)/rewriter

lib: $(SLIB) $(DLIB)

install: $(DLIB)
	mkdir -p -m  655 $(INCDIR)
	install -c  $(DLIB) $(LIBDIR)
	ldconfig -v -n $(LIBDIR)
	ln -sf $(LIBDIR)/$(LIB).$(MAJOR).$(MINOR) $(LIBDIR)/$(LIB).$(MAJOR)
	ln -sf $(LIBDIR)/$(LIB).$(MAJOR) $(LIBDIR)/$(LIB)
	cp -r ../include/* $(INCDIR)

remove: $(LIBDIR)/$(LIB) $(INCDIR)
	rm -r $(INCDIR)
	rm $(LIBDIR)/$(LIB)*
