OBJECTS = $(patsubst %.c, %, $(shell ls *.c))

all: $(OBJECTS)

%: %.c
	@if [ "$@" != "all" ]; then \
		gcc -o $@ $@.c -std=c99 && echo "CREATE $@"; \
	fi

%_clean:
	@TARGET=$@ && rm -f $${TARGET:0:4} && echo "REMOVE "$${TARGET:0:4}

clean:
	@rm -f $(OBJECTS) && echo "REMOVE "$(OBJECTS)
