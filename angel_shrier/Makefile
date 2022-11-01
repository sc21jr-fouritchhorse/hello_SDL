OBJS	=	*.cpp
CC	=	g++

COMPILER_FLAGS	=  -fmax-errors=1  -Wall -Werror -g
LINKER_FLAGS	= -lSDL2 -lGLEW -lGL

OBJ_NAME	= helloPolygons


all	:$(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean :
	rm ${OBJ_NAME}