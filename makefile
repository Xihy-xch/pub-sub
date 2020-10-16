bin = ./bin
src = ./src
inc = ./inc
obj = ./obj
source = $(wildcard $(src)/*.cc)
object = $(patsubst %.cc,$(obj)/%.o,$(notdir $(source)))
target = main
bin_target = ${bin}/${target}
cc = clang++
${bin_target}:${object}
	${cc} -g -o $@ ${object} -lpthread
${obj}/%.o:${src}/%.cc
	${cc} -g -c $< -o $@ -I ${inc}
.PHONY:clean
clean:
	-rm $(bin_target) $(object)
