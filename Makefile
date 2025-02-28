##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/help.c	\
		src/create_window.c	\
		src/animation.c	\
		src/init_structs.c	\
		src/clock_animation.c	\
		src/play_special_sound.c	\
		src/deplacements.c	\
		src/timecode_speed.c	\
		src/check_interaction_mouse_demon.c	\
		src/start_menu.c	\
		src/score_window.c	\
		src/swap.c	\

SRC_UNIT_TESTS	=

OBJ	=	$(SRC:.c=.o)

OBJ_UNIT_TESTS	=	$(SRC_UNIT_TESTS:.c=.o)

NAME	=	my_hunter

CC	=	gcc

FLAGS	=	-Wall -Wextra -g

LIBS	=	-Llib/ -lmy	\
			-lcsfml-graphics	\
			-lcsfml-system \
			-lcsfml-window	\
			-lcsfml-audio	\

CFLAGS	=	$(FLAGS) $(LIBS)

$(NAME):
		cd lib/; make re; cd ..
		$(CC) -o $(NAME) $(SRC) $(FLAGS) $(CFLAGS)

all:	$(NAME)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_UNIT_TESTS)
		find . -type f -name '*.gcda' -exec rm -f {} +
		find . -type f -name '*.gcno' -exec rm -f {} +
		find . -type f -name '*.gcov' -exec rm -f {} +
		find . -type f -name '*~' -exec rm -f {} +

fclean:	clean
		rm -f $(NAME)
		rm -f a.out
		rm -f unit_tests

re:		fclean all

tests_run:	$(OBJ_UNIT_TESTS)
		$(CC) --coverage -lcriterion -o unit_tests $(SRC_UNIT_TESTS) $(CFLAGS)
		./unit_tests --verbose

coding_style:	fclean
			coding-style . .
			cat coding-style-reports.log
			rm -f coding-style-reports.log

.PHONY:	all clean fclean re tests_run coding_style
