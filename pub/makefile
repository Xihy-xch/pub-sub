obj = ../obj
inc = ../inc
src = ../src
cc = clang++
CFLAGS = -std=c++11

object = ${obj}/common.o  ${obj}/pubNode.o pub.o
target = pub

${target}:${object}
	${cc} -g -o $@ ${object} 
${obj}/%.o:${src}/%.cc
	${cc} -g -c $< -o $@ -I ${inc}
pub.o:pub.cc
	${cc} -g -c pub.cc -o pub.o -I ${inc}
.PHONY:clean
clean:
	-rm $(target)
