NAME_NM = ft_nm
NAME_OTOOL = ft_otool

DIR_NM = ./nm
DIR_OTOOL = ./otool

all: $(NAME_NM) $(NAME_OTOOL)

$(NAME_NM):
	@make -C $(DIR_NM)
	@cp $(DIR_NM)/$(NAME_NM) .

$(NAME_OTOOL):
	@make -C $(DIR_OTOOL)
	@cp $(DIR_OTOOL)/$(NAME_OTOOL) .

clean:
	@make -C $(DIR_NM) clean
	@make -C $(DIR_OTOOL) clean

fclean: clean
	@make -C $(DIR_NM) fclean
	@make -C $(DIR_OTOOL) fclean
	@rm -rf $(NAME_NM)
	@rm -rf $(NAME_OTOOL)

re: fclean all

.PHONY: all clean fclean re