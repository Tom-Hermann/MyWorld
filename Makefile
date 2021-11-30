##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

SRC				=	src/change_dimen.c\
					src/usefull/my_len.c\
					src/usefull/set_rectangle.c\
					src/init/creat_map.c\
					src/init/init_struct.c\
					src/init/init_sprite.c\
					src/init/open_window.c\
					src/init/creat_map_vector.c\
					src/init/recreat_map.c\
					src/destroy/destroy_struct.c\
					src/world/world.c\
					src/world/draw_sprite.c\
					src/world/event/close_window.c\
					src/world/event/event.c\
					src/world/event/restart.c\
					src/world/event/change_map/add_line.c\
					src/world/event/change_map/less_line.c\
					src/world/event/change_map/add_column.c\
					src/world/event/change_map/less_column.c\
					src/world/event/mouse_is_clicked/mouse_is_clicked.c\
					src/world/event/mouse_is_clicked/change_zoom.c\
					src/world/event/mouse_is_clicked/change_view.c\
					src/world/event/mouse_is_clicked/up_down_node.c

SRC_M			=	src/main.c

SRC_UT			=	tests/*.c

OBJ				=	$(SRC:.c=.o)

OBJ_M			=	$(SRC_M:.c=.o)

INCLUDE			=	-I./include

NAME			=	my_world

NAME_UT			=	unit_test

CFLAGS			=	 -g -I./include -lcsfml-graphics -lcsfml-system -lcsfml-window -lm -lcsfml-audio

CFLAGS_UT		=	-lcriterion --coverage

RM				=	rm -rf


all:		$(NAME)

$(NAME):	$(OBJ_M) $(OBJ)
		gcc -o $(NAME) $(OBJ) $(OBJ_M) $(INCLUDE) $(CFLAGS)

tests_run:
		gcc -o $(NAME_UT) $(SRC) $(SRC_UT) $(INCLUDE) $(CFLAGS_UT)
		./$(NAME_UT)

clean:
		$(RM) $(OBJ) $(OBJ_UT) $(OBJ_M)

fclean:		clean fclean_ut
		$(RM) $(NAME)
		$(RM) *.gcda *.gcno

fclean_ut:	clean
		$(RM) $(NAME_UT)
		$(RM) *.gcda *.gcno

re:		fclean all
