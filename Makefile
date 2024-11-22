NAME = libftprintf.a
# ^ Definit le nom du fichier genere.

cc = gcc
# ^ Définit le compilateur à utiliser, ici gcc.

CFLAGS = -Wall -Wextra -Werror
# ^ Options de compilation passées au compilateur.

SRC = ft_printf.c ft_put.c
# ^ Définit la liste des fichiers sources.

OBJ = $(SRC:.c=.o)
# ^ Génère une liste des fichiers objets (.o) à partir des fichiers sources (.c). Par exemple, ft_printf.c devient ft_printf.o.

AR = ar rcs
# ^ Définit la commande pour créer une bibliothèque statique.
# ar rcs signifie :
# r : Remplace ou ajoute des fichiers dans la bibliothèque.
# c : Crée la bibliothèque si elle n'existe pas.
# s : Ajoute un index pour optimiser l'accès.

all : $(NAME)
# ^ Cible principale. Elle dépend de $(NAME), ce qui signifie qu'elle exécute les instructions nécessaires pour générer libftprintf.a.

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
# ^ Cette règle crée la bibliothèque statique.
# Dépend de $(OBJ) : il faut que tous les fichiers objets soient compilés avant de construire la bibliothèque.
# Commande : utilise ar rcs pour regrouper tous les fichiers objets dans la bibliothèque.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# ^ Définit comment compiler un fichier .c en .o.
# $< : Représente le fichier source (%.c).
# $@ : Représente le fichier cible (%.o).
# La commande utilise gcc avec les options spécifiées dans CFLAGS.

clean:
	rm -f $(OBJ)
# ^ Supprime tous les fichiers objets (.o).
# rm -f : Force la suppression sans poser de questions, même si les fichiers n'existent pas.

fclean: clean
	rm -f $(NAME)
# ^ Supprime les fichiers objets et la bibliothèque statique générée.
# Cette règle combine clean et la suppression de $(NAME).

re: fclean all
# ^ Reconstruit complètement le projet.
# Supprime tout avec fclean et relance la cible all pour tout régénérer.
