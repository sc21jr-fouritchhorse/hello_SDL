OBJS	=	*.cpp
CC	=	g++

COMPILER_FLAGS	=  -fmax-errors=1 -Wall -Werror
LINKER_FLAGS	= -lSDL2 -lGLEW -lGL

OBJ_NAME	= SDL_hello_window


all	:$(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean :
	rm ${OBJ_NAME}