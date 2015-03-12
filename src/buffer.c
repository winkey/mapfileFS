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


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "buffer.h"
#include "error.h"

#define INDENTSPACES 2

#define INITIAL 4096

/*******************************************************************************
	function to allocate memory for a buffer
*******************************************************************************/

void buffer_alloc (
	buffer *buf,
	size_t need)
{
	char *temp;
	
	/***** if no memory alocate *****/

	if (!buf->alloced) {
		buf->alloced = INITIAL;
		if (!(buf->buf = malloc (buf->alloced)))
			ERROR("buffer_alloc");
		
		buf->buf[0] = 0;
	}

	/***** if not enough memory realocate *****/

	while (buf->alloced < buf->used + need) {

		buf->alloced *= 2;
		if (!(temp = realloc (buf->buf, buf->alloced)))
			ERROR("buffer_alloc");
			
		buf->buf = temp;
	}
	
	return;
}

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
	char *format,
	...)
{

	va_list ap;
	int result = 0;
	int need = 0;
	
	int spaces = buf->indent * INDENTSPACES;
	need = 1 + spaces;
	
	/***** alocate for spaces *****/
	
	if (buf->alloced < buf->used + need )
		buffer_alloc(buf, need);
	
	/***** add spaces *****/
	
	int i;
	for (i = 0 ; i < spaces; i++) {
		*(buf->buf + buf->used) = ' ';
		buf->used++;
	}
	*(buf->buf + buf->used) = '\0';

/***** check if there is any memory *****/
	/*
	if (!buf->alloced) {
		va_start (ap, format);
		need = 1 + vsnprintf (NULL, 0, format, ap);
		buffer_alloc(buf, need);
		va_end (ap);
	}
	*/
	/***** try to print to the buffer *****/
	
	va_start (ap, format);
	result = vsnprintf (buf->buf + buf->used,
											buf->alloced - buf->used,
											format,
											ap);
	va_end (ap);
	
	/***** check if there was enough memory *****/
	
	if (buf->alloced < buf->used + result + 2) {
		va_start (ap, format);
		need = 1 + vsnprintf (NULL, 0, format, ap);
		buffer_alloc(buf, need);
		va_end (ap);
		
		/***** reprint *****/
		
		va_start (ap, format);
		result = vsprintf (buf->buf + buf->used,
												format,
												ap);
		va_end (ap);
	}
		
	buf->used += result;

	return result + buf->indent * INDENTSPACES;
}

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
	...)
{

	va_list ap;
	size_t result = 0;
	
	/***** try to print to the buffer *****/
	
	va_start (ap, format);
	result = vsnprintf (buf->buf + buf->used,
											buf->alloced - buf->used,
											format,
											ap);
	va_end (ap);
	
	/***** check if there was enough memory *****/
	
	if (buf->alloced < buf->used + result + 2) {
		va_start (ap, format);
		size_t need = 1 + vsnprintf (NULL, 0, format, ap);
		buffer_alloc(buf, need);
		va_end (ap);
		
		/***** reprint *****/
		
		va_start (ap, format);
		result = vsprintf (buf->buf + buf->used,
												format,
												ap);
		va_end (ap);
	}
		
	buf->used += result;
	

	return result;
}

/*******************************************************************************
	function to free a buffer

	args:
						buf			the buffer to free
	
 returns:
						nothing
*******************************************************************************/

void buffer_free(
	buffer *buf)
{
	
	free(buf->buf);
	
	return;
}
