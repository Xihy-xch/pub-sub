obj = ../obj
inc = ../inc
cc = clang++
CFLAGS = -std=c++11

object = ${obj}/common.o ${obj}/master.o ${obj}/node.o pub.o
target = pub

${target}:${object}
	${cc} -g -o $@ ${object} -lpthread
pub.o:pub.cc
	${cc} -g -c pub.cc -o pub.o -I ${inc}
.PHONY:clean
clean:
	-rm $(target)
