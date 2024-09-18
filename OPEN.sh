# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    OPEN.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 16:20:49 by nfordoxc          #+#    #+#              #
#    Updated: 2024/09/11 16:27:14 by nfordoxc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

COUNT=3

run=(
	"bash run_make.sh"
	"valgrind --tool=memcheck --leak-check=full --show-leak-kinds=definite,indirect,possible --track-fds=yes ./minishell"
	""
	)

for ((i=0; i < COUNT ; i++))
do
	if [ -n "${run[i]}" ]; then
		gnome-terminal -- bash -c "cd /home/nfordoxc/Cursus_42_Luxembourg/Git_42_Luxembourg/Minishell;${run[i]};exec bash --posix"
	else
        gnome-terminal -- bash -c "cd /home/nfordoxc/Cursus_42_Luxembourg/Git_42_Luxembourg/Minishell;exec bash --posix"
    fi
done
