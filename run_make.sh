# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_make.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 08:09:39 by nfordoxc          #+#    #+#              #
#    Updated: 2024/09/18 13:21:35 by nfordoxc         ###   Luxembourg.lu      #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

WATCH_DIR="."
COMMAND="make re"

calculate_checksum()
{
    find "$WATCH_DIR" -type f -exec md5sum {} \; | sort -k 2 | md5sum
}

previous_checksum=$(calculate_checksum)

while true
do
    current_checksum=$(calculate_checksum)
    
    if [ "$previous_checksum" != "$current_checksum" ]; then
    	clear
        $COMMAND
        previous_checksum=$current_checksum
    fi
    sleep 1
done

