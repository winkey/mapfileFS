/******************************************************************************
 *
 * Project:  mapfileFS
 * Purpose:  
 * Author:   Brian Case   rush@winkey.org
 *
 ******************************************************************************
 * Copyright (c) 2015, Brian Case   rush@winkey.org
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/


#ifndef _BUFFER_H
#define _BUFFER_H

/*******************************************************************************
	buffer structure
	
	members:
							buf				the buffer
							alloced		amount of space allocated in the buffer
							used			amount of space used in the buffer
*******************************************************************************/

typedef struct {
	char *buf;
	size_t alloced;
	size_t used;
	int indent;
} buffer;

/*******************************************************************************
	function to print to a buffer

	args:
						buf			the buffer to print to
						fmt			the format string
						...			aditianal args that match the format string
	
 returns:
						the number of chars printed to the buffer, not includeing the \0
*******************************************************************************/

int buffer_printf(
	buffer *buf,
	char *fmt,
	...);

/*******************************************************************************
	function to print to a buffer with no indent

	args:
						buf			the buffer to print to
						fmt			the format string
						...			aditianal args that match the format string
	
 returns:
						the number of chars printed to the buffer, not includeing the \0
*******************************************************************************/

int buffer_printf_noindent(
	buffer *buf,
	char *format,
	...);

/*******************************************************************************
	function to free a buffer

	args:
						buf			the buffer to free
	
 returns:
						nothing
*******************************************************************************/

void buffer_free(
	buffer *buf);


#endif /* _BUFFER_H */


