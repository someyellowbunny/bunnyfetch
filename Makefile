.PHONY: all

all:
	$(MAKE) -C src/ all
	cp src/bunnyfetch .

run: all
	./bunnyfetch

clean:
	rm -f bunnyfetch
	$(MAKE) -C src/ clean