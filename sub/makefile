obj = ../obj
inc = ../inc
cc = clang++
CFLAGS = -std=c++11

object = ${obj}/common.o ${obj}/master.o ${obj}/node.o sub.o
target = sub

${target}:${object}
	${cc} -g -o $@ ${object} -lpthread
pub.o:sub.cc
	${cc} -g -c sub.cc -o sub.o -I ${inc}
.PHONY:clean
clean:
	-rm $(target)
