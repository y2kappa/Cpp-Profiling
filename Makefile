#COLORS
GREEN  := $(shell tput -Txterm setaf 2)
WHITE  := $(shell tput -Txterm setaf 7)
YELLOW := $(shell tput -Txterm setaf 3)
RESET  := $(shell tput -Txterm sgr0)

# Add the following 'help' target to your Makefile
# And add help text after each target name starting with '\#\#'
# A category can be added with @category
HELP_FUN = \
	%help; \
	while(<>) { push @{$$help{$$2 // 'options'}}, [$$1, $$3] if /^([a-zA-Z\-]+)\s*:.*\#\#(?:@([a-zA-Z\-]+))?\s(.*)$$/ }; \
	print "usage: make [target]\n\n"; \
	for (sort keys %help) { \
	print "${WHITE}$$_:${RESET}\n"; \
	for (@{$$help{$$_}}) { \
	$$sep = " " x (32 - length $$_->[0]); \
	print "  ${YELLOW}$$_->[0]${RESET}$$sep${GREEN}$$_->[1]${RESET}\n"; \
	}; \
	print "\n"; }

help: ##@other Show this help.
	@perl -e '$(HELP_FUN)' $(MAKEFILE_LIST)

fibonacci-test: ##@fibonacci
	g++ fibonnaci/fibonnaci.t.cpp fibonnaci/fibonnaci.cpp -o _build/fibonnaci/fibonnaci.t.tsk --std=c++14 -L googletest/ -l gtest
	_build/fibonnaci/fibonnaci.t.tsk

fibonacci-bench: ##@fibonacci
	g++ fibonnaci/fibonnaci.b.cpp fibonnaci/fibonnaci.cpp -o _build/fibonnaci/fibonnaci.b.tsk --std=c++14 -L benchmark/ -l benchmark
	_build/fibonnaci/fibonnaci.b.tsk

quicksort-test: ##@quicksort
	g++ quicksort/quicksort.t.cpp quicksort/quicksort.cpp -o _build/quicksort/quicksort.t.tsk --std=c++14 -L googletest/ -l gtest
	_build/quicksort/quicksort.t.tsk

quicksort-bench: ##@quicksort
	g++ quicksort/quicksort.b.cpp quicksort/quicksort.cpp -o _build/quicksort/quicksort.b.tsk --std=c++14 -L benchmark/ -l benchmark
	_build/quicksort/quicksort.b.tsk

vector-test: ##@vector
	mkdir -p _build/vector
	g++ -o _build/vector/vector.t.tsk vector/vector.cpp vector/vector.t.cpp  --std=c++14 -L googletest/ -l gtest
	_build/vector/vector.t.tsk

vector-benchmark: ##@vector
	mkdir -p _build/vector
	g++ -o _build/vector/vector.b.tsk vector/vector.cpp vector/vector.b.cpp  --std=c++14 -L benchmark/ -l benchmark
	_build/vector/vector.b.tsk