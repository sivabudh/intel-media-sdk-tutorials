EXEC=../_build/simple_transcode_opaque_async
INCS= \
  ../common/common_utils.h \
  ../common/common_vaapi.h \
  ../common/bits/linux_defs.h \
  ../common/cmd_options.h
SRCS= \
  src/simple_transcode_opaque_async.cpp \
  ../common/common_utils.cpp \
  ../common/common_utils_linux.cpp \
  ../common/common_vaapi.cpp \
  ../common/cmd_options.cpp

CFLAGS=-I/usr/local/include -I../common -I$(MFX_HOME)/include
LFLAGS=-L$(MFX_HOME)/lib/lin_x64 -lmfx -lva -lva-drm -lpthread -lrt -ldl

$(EXEC): $(INCS) $(SRCS) Makefile
	mkdir -p ../_build
	g++ -o $(EXEC) $(SRCS) $(CFLAGS) $(LFLAGS)

.PHONY: clean
clean:
	rm $(EXEC)
