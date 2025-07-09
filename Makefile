CXX = emcc
CXXFLAGS = -Wall -Wextra -std=c++17 -O2 -s WASM=1 -s MODULARIZE=1 -s EXPORT_NAME="createModule" -s EXPORTED_FUNCTIONS="['_processFileForHexView', '_malloc', '_free']" -s EXPORTED_RUNTIME_METHODS="['cwrap', 'stringToUTF8', 'HEAPU8']" -s ALLOW_MEMORY_GROWTH=1 -s MALLOC=emmalloc --no-entry
TARGET = hex_viewer_web
SRCS = main_web.cpp
all: $(TARGET).js
$(TARGET).js: $(SRCS)
	$(CXX) $(CXXFLAGS) $< -o $@
clean:
	rm -f $(TARGET).js $(TARGET).wasm $(OBJS)
