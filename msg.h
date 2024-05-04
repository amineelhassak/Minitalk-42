/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:54:07 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/29 07:54:12 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define MSG_ERRR "\n\033[0;91m               😡ERROR PID NOT EXISTE !\n\n\n\033[0m"
# define MSG_ERPPID "\n\033[0;91m 😡ERROR PRINT PID !\n\033[0m"
# define MSG_ER "\n\033[0;91m               😡ERROR WRONG INPUT !\n\033[0m"
# define PIDS "\033[0;96m \n\n  Server's PID IS :      \xe2\x9d\xa4====> \
  %d   <=====\xe2\x9d\xa4\n\n\033[0m"
# define PIDC "\033[0;96m \n\n       Client's PID IS :\
 \xe2\x9d\xa4====>   %d   <=====\xe2\x9d\xa4\033[0m"
# define MSG_DATAC "\033[0;96m <-- \xe2\x9d\xa4 TRY AGAIN, \
WITH A CORRECT INPUT \xe2\x9d\xa4\xe2\x9d\xa4 -->\n \033[0m"
# define EXP_DATA "\033[0;92m\n\nEXEMPLE :\n ====> \
./client 1337(Pid) Message(string) <==== \n\033[0m"
# define MSG_FC "\033[0;92m \n          Connection Established \n\033[0m"
# define CHEV "\033[0:90m>>\033[0m"
# define PID_GIG "\033[0;96m PID THE CLIENT IS : ====>   %d   <=====[0m"
# define MSGR "\x1b[47m\x1b[0;33m\n           \
MESSAGE'VE BEEN SENT SUCCESSFULLY\x1b[0m"
#endif
