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


#ifndef cache_h
#define cache_h

typedef struct {
    int mapfile_id;
    unsigned int expired;
    buffer *buf;
} cache_node_data;

/*****************************************************************************//**
  function to compare cache data
  
 @param	cache1  the first cache pointer to be compared
 @param	cache2   the second cache pointer to be compared
  
 @return	less than 0 if cache1 is less than cache2
 @return	0 if cache1 is equal to cache2
 @return	greater than 0 if cache1 is greater than cache2
        
*******************************************************************************/

int (BSTree_data_cmp_func)cache_cmp (
    cache_node_data* cache1,
    cache_node_data* cache2);

/*****************************************************************************//**
  function to delete a cache
  
 @param	cache pointer to the cache to be free'ed
  
 @return	nothing

*******************************************************************************/

void  (BSTree_data_free_func)cache_free (
    cache_node_data* cache);

#endif
