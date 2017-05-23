NAME= fdf
GCC= gcc -Wall -Wextra -Werror
INCLUDES= -I includes -I libft/includes -I minilibx

LIBFT= libft/libft.a
LFT= -L libft -lft

DLIBMLX= minilibx
include $(DLIBMLX)/lmlx.mk

DOBJS= objs
DSRCS= srcs

SRCS_FILES= main drawline key_handler parse_file #new#

SRCS = $(addprefix $(DSRCS)/, $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(SRCS:$(DSRCS)/%.c=$(DOBJS)/%.o)

all: $(NAME)

$(DOBJS):
	@mkdir -p $(DOBJS)

$(LIBFT):
	@make -C libft

$(LIBMLX):
	@make -C $(DLIBMLX)

$(OBJS): $(DOBJS)/%.o: $(DSRCS)/%.c
	@$(GCC) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(LIBMLX) $(DOBJS) $(OBJS)
	@$(GCC) -o $(NAME) $(OBJS) $(LFT) $(LMLX)

clean:
	@make clean -C libft
	@make clean -C minilibx
	@rm -rf $(DOBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
