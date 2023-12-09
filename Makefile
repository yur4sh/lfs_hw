INCLUDEPATH=include
SRCPATH=src
BUILDDIR=build
LIBDIR=lib
BINDIR=bin
BIN=lfs_hw
BINPATH=$(BINDIR)/$(BIN)

SRCPATH_2=src_2
INCLUDEPATH_2=include_2
BUILDDIR_2=build_2

CALC_SRC=$(SRCPATH)/calc.c
CALC_OBJ=$(BUILDDIR)/calc.o
CALC_LIB=$(LIBDIR)/libcalc.a

CONV_SRC=$(SRCPATH_2)/upper.c $(SRCPATH_2)/lower.c
CONV_OBJ=$(BUILDDIR_2)/upper.o $(BUILDDIR_2)/lower.o
CONV_LIB=$(LIBDIR)/libconvert.so

CC=gcc
CFLAGS=-Wall -Werror -I$(INCLUDEPATH) -I$(INCLUDEPATH_2)

.PHONY: all clean

all: $(CALC_LIB) $(CONV_LIB) $(BINPATH)

# Task 1 (static library)
$(CALC_LIB): $(CALC_OBJ)
	@mkdir -p $(LIBDIR)
	ar rcs $(CALC_LIB) $(CALC_OBJ)

$(CALC_OBJ): $(CALC_SRC)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Task 2 (dynamic library)
$(CONV_LIB): $(CONV_OBJ)
	@mkdir -p $(LIBDIR)
	$(CC) $(CFLAGS) -shared $^ -o $@

$(BUILDDIR_2)/%.o: $(SRCPATH_2)/%.c
	@mkdir -p $(BUILDDIR_2)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(BUILDDIR)/%.o: $(SRCPATH)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINPATH): $(BUILDDIR)/main.o $(BUILDDIR)/ui.o
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -L$(LIBDIR) -lcalc -lconvert -Wl,-rpath,$(abspath $(LIBDIR)) -o $@

clean:
	rm -rf $(BUILDDIR) $(BUILDDIR_2) $(LIBDIR) $(BINDIR)