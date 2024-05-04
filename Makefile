NAME = makeall

ANSI_RESET   = \x1b[0m
ANSI_RED     = \x1b[31m
ANSI_GREEN   = \x1b[32m
ANSI_YELLOW  = \x1b[33m
ANSI_BLUE    = \x1b[34m
ANSI_MAGENTA = \x1b[35m
ANSI_CYAN    = \033[0;96m
ANSI_WHITE   = \x1b[37m

TEXT1=$(ANSI_CYAN)<| $(ANSI_GREEN)------ PRINTF HAS BEEN MAKED SUCCESSFULLY ----- $(ANSI_CYAN)|> \n
TEXT2=  \n$(ANSI_CYAN)<|$(ANSI_RESET)$(ANSI_GREEN) ------ LIBFT HAS BEEN MAKED SUCCESSFULLY ------ $(ANSI_CYAN)|>$(ANSI_RESET)\n
TEXT3=          $(ANSI_CYAN)           <| $(ANSI_GREEN)------ SUCCESS ------ $(ANSI_RESET) $(ANSI_CYAN)|> $(ANSI_RESET)

RMLIBFT = @make clean -C mylibft
RMPRINT = @make clean -C ft_printf
FRMLIBFT = @make fclean -C mylibft
FRMPRINT = @make fclean -C ft_printf
RM = @rm -f

SRCC =client.c
SRCS = serveur.c
CCLIENT = client
CSERVERE = serveur

SRCBC=client_bonus.c
SRCBS=serveur_bonus.c
CCLIENTB=client_bonus
CSERVEREB=serveur_bonus

PATHLIBFT =mylibft/libft.a
PATHPRINTF = ft_printf/libftprintf.a

MKlibft = @make -C mylibft > /dev/null && echo  "$(TEXT2)"
MKPRINTF = @make -C ft_printf > /dev/null && echo "$(TEXT1)"

CFLAGSCC = @cc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): makep makel $(CCLIENT) $(CSERVERE) succ

$(CCLIENT): $(SRCC)
	$(CFLAGSCC) $< -o $@ $(PATHLIBFT) $(PATHPRINTF)

$(CSERVERE): $(SRCS)
	$(CFLAGSCC) $< -o $@ $(PATHLIBFT) $(PATHPRINTF)

bonus: makep makel $(CCLIENTB) $(CSERVEREB) succ

$(CCLIENTB): $(SRCBC)
	$(CFLAGSCC) $< -o $@ $(PATHLIBFT) $(PATHPRINTF)

$(CSERVEREB): $(SRCBS)
	$(CFLAGSCC) $< -o $@ $(PATHLIBFT) $(PATHPRINTF)

succ:
	@echo "$(TEXT3)\n$(ANSI_RESET)"

makel:
	$(MKlibft)

makep:
	$(MKPRINTF)

clean: cleanlibft cleanprintf
	$(RM) $(CCLIENT) $(CSERVERE) $(CCLIENTB) $(CSERVEREB)

cleanprintf:
	$(RMPRINT)

cleanlibft:
	$(RMLIBFT)

fcleanprintf: cleanprintf
	$(FRMPRINT)

fcleanlibft: cleanlibft
	$(FRMLIBFT)

fclean: clean fcleanlibft fcleanprintf

re: fclean all

.PHONY: succ makep makel cleanlibft cleanprintf