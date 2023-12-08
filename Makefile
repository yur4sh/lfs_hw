# IDIR =../include
# CC=gcc
# CFLAGS=-I$(IDIR)

# ODIR=obj
# LDIR =../lib

# LIBS=-lm

# _DEPS = hellomake.h
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJ = hellomake.o hellofunc.o
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


# $(ODIR)/%.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# hellomake: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

INCLUDEPATH=include
SRCPATH=src
BUILDDIR=build
LIBDIR=lib
BINDIR=bin
BIN=lfs_hw
BINPATH=$(BINDIR)/$(BIN)

CALC_SRC=$(SRCPATH)/calc.c
CALC_OBJ=$(BUILDDIR)/calc.o
CALC_LIB=$(LIBDIR)/libcalc.a

CC=gcc
CFLAGS=-Wall -Werror -I$(INCLUDEPATH)

.PHONY: all clean

all: $(CALC_LIB) $(BINPATH)

$(CALC_LIB): $(CALC_OBJ)
	@mkdir -p $(LIBDIR)
	ar rcs $(CALC_LIB) $(CALC_OBJ)

$(CALC_OBJ): $(CALC_SRC)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCPATH)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINPATH): $(BUILDDIR)/main.o $(BUILDDIR)/ui.o
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -L$(LIBDIR) -lcalc -o $@

clean:
	rm -rf $(BUILDDIR) $(LIBDIR) $(BINDIR)