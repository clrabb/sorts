src = $(wildcard src/*.cc)
obj = $(src:.cc=.o)
dep = $(obj:.o=.d)

LDFLAGS = 
CFLAGS = 
CC = g++

sort1: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(dep)

%.d: %.cc
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(obj) sort1

.PHONY: cleandep
cleandep:
	rm -f $(dep)
