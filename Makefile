src = $(wildcard src/*.cc)
obj = $(src:.cc=.o)
dep = $(obj:.o=.d)

LDFLAGS = -g
CPPFLAGS = -g
CPP = g++

sort1: $(obj)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(LDFLAGS) 

-include $(dep)

%.d: %.cc
	@$(CC) $(CPPFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(obj) sort1

.PHONY: cleandep
cleandep:
	rm -f $(dep)
