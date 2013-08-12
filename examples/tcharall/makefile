.PHONY : all clean

# flags
CC = gcc
CFLAGS += -Wall -I../../src
#LDFLAGS += -L../../lib
#LIBS += -lglib

# args
RELEASE =0
UNICODE =0
BITS =
EXFLAGS =

# [args] 生成模式. 0代表debug模式, 1代表release模式. make RELEASE=1.
ifeq ($(RELEASE),0)
	# debug
	CFLAGS += -g
else
	# release
	CFLAGS += -O3 -DNDEBUG
	//CFLAGS += -O3 -g -DNDEBUG
endif

# [args] UNICODE模式. 0代表ansi模式, 1代表unicode模式. make UNICODE=1.
ifeq ($(UNICODE),0)
	# ansi
	CFLAGS +=
else
	# unicode
	CFLAGS += -D_UNICODE -DUNICODE
endif

# [args] 程序位数. 32代表32位程序, 64代表64位程序, 其他默认. make BITS=32.
ifeq ($(BITS),32)
	CFLAGS += -m32
else
	ifeq ($(BITS),64)
		CFLAGS += -m64
	else
	endif
endif

# [args] 扩展参数. make EXFLAGS="-mavx".
CFLAGS += $(EXFLAGS)


# makefile path.
vpath %.h ../../src

# files
TARGETS = tcharall
OBJS = tcharall.o

all : $(TARGETS)

tcharall : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)


tcharall.o : tcharall.c auto_tchar.h auto_tmain.h prichar.h
	$(CC) -c $< $(CFLAGS)


clean :
	$(RM) $(OBJS) $(TARGETS) $(addsuffix .exe,$(TARGETS))
