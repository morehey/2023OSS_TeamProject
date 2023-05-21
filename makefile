# Makefile for easier compile - Junghwan

CC = gcc
INCDIR = 2023OSS_TeamProject
CCFLAGS = -std=c11 -Wall -g 

SRC1 = Hyunjun_whyb.c Junghwan_whyb.c main.c Mode3_whyb.c whyb.c
OBJ1 = $(SRC1:.c=.o)
EXE1 = whyb

# rule for link
all: $(EXE1)  
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^ 

# rule for compilation
%.o: %.c
	$(CC) $(CCFLAGS) -c -I$(INCDIR) $<

.PHONY: all clean install
clean:
	rm -f *.o $(OBJ1) $(EXE1) 

TARGET_PATH = 2023OSS_TeamProject
