OBJECTS = $(patsubst %.cpp, %, $(shell ls *.cpp))

all: $(OBJECTS)

%: %.cpp
	@if [ "$@" != "all" ]; then \
		g++ -o $@ $@.cpp && echo "CREATE $@"; \
	fi

%_clean:
	@TARGET=$@ && rm -f $${TARGET:0:4} && echo "REMOVE "$${TARGET:0:4}

clean:
	@rm -f $(OBJECTS) && echo "REMOVE "$(OBJECTS)
