# Some wheels
assert:
	@$(MAKE) assert.o && ./assert.o

buffer:
	@$(MAKE) buffer.o && ./buffer.o

event:
	@gcc ./src/event/*.c ./src/hash_map/hash_map.c ./src/linked-list/linked-list.c -o event.o;./event.o

pipe_channel:
	$(MAKE) pipe_channel.o && ./pipe_channel.o

test-top-k:
	@gcc src/top-k/top-k.c src/top-k/test.c ./src/heap/heap.c -o top-k.o;./top-k.o; rm -rf top-k.o;

test-heap_sorting:
	@gcc src/heap_sorting/heap_sorting.c src/heap/heap.c src/heap_sorting/test.c -o heap_sorting.o;./heap_sorting.o; rm -rf heap_sorting.o;
