# flags
CC = gcc
CFS = -Wall

# args
RELEASE =0
UNICODE =0
BITS =
CFLAGS =

# [args] 生成模式. 0代表debug模式, 1代表release模式. make RELEASE=1.
ifeq ($(RELEASE),0)
	# debug
	CFS += -g
else
	# release
	CFS += -O3 -DNDEBUG
	//CFS += -O3 -g -DNDEBUG
endif

# [args] UNICODE模式. 0代表ansi模式, 1代表unicode模式. make UNICODE=1.
ifeq ($(UNICODE),0)
	# ansi
	CFS +=
else
	# unicode
	CFS += -D_UNICODE -DUNICODE
endif

# [args] 程序位数. 32代表32位程序, 64代表64位程序, 其他默认. make BITS=32.
ifeq ($(BITS),32)
	CFS += -m32
else
	ifeq ($(BITS),64)
		CFS += -m64
	else
	endif
endif

# [args] 使用 CFLAGS 添加新的参数. make CFLAGS="-mavx".
CFS += $(CFLAGS)


.PHONY : all clean

# files
TARGETS = tcharall
OBJS = tcharall.o

all : $(TARGETS)

tcharall : $(OBJS)
	$(CC) -o $@ $^ $(CFS)


tcharall.o : tcharall.c
	$(CC) -c $< $(CFS)


clean :
	rm -f $(OBJS) $(TARGETS) $(addsuffix .exe,$(TARGETS))
