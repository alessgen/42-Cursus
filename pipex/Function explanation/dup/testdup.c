/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:56:57 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/04 12:02:41 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	file_desc;
	int	copy_desc;
    // open() returns a file descriptor file_desc to the file "dup.txt" here
	file_desc = open("dup.txt", O_WRONLY | O_APPEND);
	if (file_desc < 0)
		printf("Error opening the file\n");
    // dup() will create the copy of file_desc as the copy_desc
    // then both can be used interchangeably.
	copy_desc = dup(file_desc);
    // write() will write the given string into the file referred by the file descriptors
	write (copy_desc, "This will be output to the file named dup.txt\n", 46);
	write (file_desc, "This will also be output to the file named dup.txt\n", 51);
    return 0;
}
