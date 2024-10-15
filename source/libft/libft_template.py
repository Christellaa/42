# libft_template.py

from base_template import template
import os

# List of functions for documentation
functions = [
    {
        'function_name': 'ft_memset',
        'parameters': 'void *s, int c, size_t n',
        'description': 'Fills the first n bytes of the memory area pointed to by s with the constant byte c.',
        'param_types': ['void *s', 'int c', 'size_t n'],
        'param_descriptions': [
            'Pointer to the memory area to fill.',
            'The byte to fill the memory area with.',
            'Number of bytes to fill.'
        ],
        'return_description': 'Pointer to the memory area s.',
        'example': [
            'char str[15] = "Hello, World!";',
            'ft_memset(str, \'a\', 5);',
            '// str is now "aaaaa, World!"'
        ],
        'notes': [
            'If n is greater than the size of the memory area, the behavior is undefined.',
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_bzero`: Fills the first n bytes with zeros.',
            ':func:`ft_memcpy`: Copies n bytes from memory area src to memory area dest.',
            ':func:`ft_memmove`: Copies n bytes from memory area src to memory area dest, handling overlapping memory areas.',
            ':func:`ft_memchr`: Locates the first occurrence of c in the first n bytes of the memory area pointed to by s.',
            ':func:`ft_memcmp`: Compares the first n bytes of memory areas s1 and s2.',
            ':func:`ft_calloc`: Allocates memory for an array of nmemb elements of size bytes each and sets the memory to zero.',
            ':func:`ft_realloc`: Changes the size of the memory block pointed to by ptr to size bytes.'
        ],
        'output_dir': 'libft/memory'
    },
    {
        'function_name': 'ft_bzero',
		'parameters': 'void *s, size_t n',
        'description': 'Fills the first n bytes of the memory area pointed to by s with zeros.',
        'param_types': ['void *s', 'size_t n'],
        'param_descriptions': [
			'Pointer to the memory area to fill.',
			'Number of bytes to fill.'
		],
        'return_description': 'None.',
		'example': [
			'char str[15] = "Hello, World!";',
			'ft_bzero(str, 5);',
			'// str is now "\\0\\0\\0\\0\\0, World!"'
		],
		'notes': [
			'If n is greater than the size of the memory area, the behavior is undefined.',
			'The function does not check for null pointers.'
		],
		'related_functions': [
			':func:`ft_memset`: Fills the first n bytes of the memory area with the constant byte c.',
			':func:`ft_memcpy`: Copies n bytes from memory area src to memory area dest.',
			':func:`ft_memmove`: Copies n bytes from memory area src to memory area dest, handling overlapping memory areas.',
			':func:`ft_memchr`: Locates the first occurrence of c in the first n bytes of the memory area pointed to by s.',
			':func:`ft_memcmp`: Compares the first n bytes of memory areas s1 and s2.',
			':func:`ft_calloc`: Allocates memory for an array of nmemb elements of size bytes each and sets the memory to zero.',
			':func:`ft_realloc`: Changes the size of the memory block pointed to by ptr to size bytes.'
		],
        'output_dir': 'libft/memory'
	},
	{
		'function_name': 'ft_memcpy',
        'parameters': 'void *dest, const void *src, size_t n',
        'description': 'Copies n bytes from memory area src to memory area dest.',
        'param_types': ['void *dest', 'constvoid *src', 'size_t n'],
        'param_descriptions': [
			'Pointer to the destination memory area.',
			'Pointer to the source memory area.',
			'Number of bytes to copy.'
		],
        'return_description': 'Pointer to the destination memory area.',
		'example': [
			'char src[15] = "Hello, World!";',
			'char dest[15];',
			'ft_memcpy(dest, src, 5);',
			'// dest is now "Hello"'
		],
		'notes': [
			'If the memory areas overlap, the behavior is undefined.',
			'The function does not check for null pointers.'
		],
		'related_functions': [
			':func:`ft_memset`: Fills the first n bytes of the memory area with the constant byte c.',
			':func:`ft_bzero`: Fills the first n bytes with zeros.',
			':func:`ft_memmove`: Copies n bytes from memory area src to memory area dest, handling overlapping memory areas.',
			':func:`ft_memchr`: Locates the first occurrence of c in the first n bytes of the memory area pointed to by s.',
			':func:`ft_memcmp`: Compares the first n bytes of memory areas s1 and s2.',
			':func:`ft_calloc`: Allocates memory for an array of nmemb elements of size bytes each and sets the memory to zero.',
			':func:`ft_realloc`: Changes the size of the memory block pointed to by ptr to size bytes.'
		],
        'output_dir': 'libft/memory'
	},
    {
        'function_name': 'ft_memmove',
        'parameters': 'void *dest, const void *src, size_t n',
        'description': 'Copies n bytes from memory area src to memory area dest, handling overlapping memory areas.',
        'param_types': ['void *dest', 'constvoid *src', 'size_t n'],
        'param_descriptions': [
			'Pointer to the destination memory area.',
			'Pointer to the source memory area.',
			'Number of bytes to copy.'
		],
        'return_description': 'Pointer to the destination memory area.',
		'example': [
			'char str[15] = "Hello, World!";',
			'ft_memmove(str + 7, str, 7);',
			'// str is now "Hello, Hello!"'
		],
		'notes': [
			'The memory areas may overlap.',
			'The function does not check for null pointers.'
		],
		'related_functions': [
			':func:`ft_memset`: Fills the first n bytes of the memory area with the constant byte c.',
			':func:`ft_bzero`: Fills the first n bytes with zeros.',
			':func:`ft_memcpy`: Copies n bytes from memory area src to memory area dest.',
			':func:`ft_memchr`: Locates the first occurrence of c in the first n bytes of the memory area pointed to by s.',
			':func:`ft_memcmp`: Compares the first n bytes of memory areas s1 and s2.',
			':func:`ft_calloc`: Allocates memory for an array of nmemb elements of size bytes each and sets the memory to zero.',
			':func:`ft_realloc`: Changes the size of the memory block pointed to by ptr to size bytes.'
		],
        'output_dir': 'libft/memory'
	},
    {
		'function_name': 'ft_memchr',
		'parameters': 'const void *s, int c, size_t n',
		'description': 'Locates the first occurrence of c in the first n bytes of the memory area pointed to by s.',
		'param_types': ['constvoid *s', 'int c', 'size_t n'],
		'param_descriptions': [
			'Pointer to the memory area to search.',
			'The byte to search for.',
			'Number of bytes to search.'
		],
		'return_description': 'Pointer to the located byte or NULL if the byte is not found.',
		'example': [
			'char str[15] = "Hello, World!";',
			'char *result = ft_memchr(str, \',\', 13);',
			'// result points to the comma in str'
		],
		'notes': [
			'The function does not check for null pointers.'
		],
		'related_functions': [
			':func:`ft_memset`: Fills the first n bytes of the memory area with the constant byte c.',
			':func:`ft_bzero`: Fills the first n bytes with zeros.',
			':func:`ft_memcpy`: Copies n bytes from memory area src to memory area dest.',
			':func:`ft_memmove`: Copies n bytes from memory area src to memory area dest, handling overlapping memory areas.',
			':func:`ft_memcmp`: Compares the first n bytes of memory areas s1 and s2.',
			':func:`ft_calloc`: Allocates memory for an array of nmemb elements of size bytes each and sets the memory to zero.',
			':func:`ft_realloc`: Changes the size of the memory block pointed to by ptr to size bytes.'
		],
        'output_dir': 'libft/memory'
	},
    {
		'function_name': 'ft_memcmp',
		'parameters': 'const void *s1, const void *s2, size_t n',
		'description': 'Compares the first n bytes of memory areas s1 and s2.',
		'param_types': ['constvoid *s1', 'constvoid *s2', 'size_t n'],
		'param_descriptions': [
			'Pointer to the first memory area.',
			'Pointer to the second memory area.',
			'Number of bytes to compare.'
		],
		'return_description': 'Integer less than, equal to, or greater than zero if the first n bytes of s1 are found, respectively, to be less than, to match, or be greater than the first n bytes of s2.',
		'example': [
			'char str1[15] = "Hello, World!";',
			'char str2[15] = "Hello, World!";',
			'int result = ft_memcmp(str1, str2, 14);',
			'// result is 0'
		],
		'notes': [
			'The function does not check for null pointers.'
		],
		'related_functions': [
			':func:`ft_memset`: Fills the first n bytes of the memory area with the constant byte c.',
			':func:`ft_bzero`: Fills the first n bytes with zeros.',
			':func:`ft_memcpy`: Copies n bytes from memory area src to memory area dest.',
			':func:`ft_memmove`: Copies n bytes from memory area src to memory area dest, handling overlapping memory areas.',
			':func:`ft_memchr`: Locates the first occurrence of c in the first n bytes of the memory area pointed to by s.',
			':func:`ft_calloc`: Allocates memory for an array of nmemb elements of size bytes each and sets the memory to zero.',
			':func:`ft_realloc`: Changes the size of the memory block pointed to by ptr to size bytes.'
		],
        'output_dir': 'libft/memory'
	},
	{
		'function_name': 'ft_calloc',
		'parameters': 'size_t nmemb, size_t size',
		'description': 'Allocates memory for an array of nmemb elements of size bytes each and sets the memory to zero.',
		'param_types': ['size_t nmemb', 'size_t size'],
		'param_descriptions': [
			'Number of elements to allocate memory for.',
			'Size of each element.'
		],
		'return_description': 'Pointer to the allocated memory block.',
		'example': [
			'int *arr = ft_calloc(5, sizeof(int));',
			'// arr points to an array of 5 integers initialized to zero'
		],
		'notes': [
			'The function returns NULL if memory allocation fails.'
		],
		'related_functions': [
			':func:`ft_memset`: Fills the first n bytes of the memory area with the constant byte c.',
			':func:`ft_bzero`: Fills the first n bytes with zeros.',
			':func:`ft_memcpy`: Copies n bytes from memory area src to memory area dest.',
			':func:`ft_memmove`: Copies n bytes from memory area src to memory area dest, handling overlapping memory areas.',
			':func:`ft_memchr`: Locates the first occurrence of c in the first n bytes of the memory area pointed to by s.',
			':func:`ft_memcmp`: Compares the first n bytes of memory areas s1 and s2.',
			':func:`ft_realloc`: Changes the size of the memory block pointed to by ptr to size bytes.'
		],
        'output_dir': 'libft/memory'
	},
    {
		'function_name': 'ft_realloc',
		'parameters': 'void *ptr, size_t size',
		'description': 'Changes the size of the memory block pointed to by ptr to size bytes.',
		'param_types': ['void *ptr', 'size_t size'],
		'param_descriptions': [
			'Pointer to the memory block to resize.',
			'New size of the memory block.'
		],
		'return_description': 'Pointer to the resized memory block.',
		'example': [
			'int *arr = ft_calloc(5, sizeof(int));',
			'int *new_arr = ft_realloc(arr, 10 * sizeof(int));',
			'// new_arr points to an array of 10 integers initialized to zero'
		],
		'notes': [
			'The function returns NULL if memory allocation fails.'
		],
		'related_functions': [
			':func:`ft_memset`: Fills the first n bytes of the memory area with the constant byte c.',
			':func:`ft_bzero`: Fills the first n bytes with zeros.',
			':func:`ft_memcpy`: Copies n bytes from memory area src to memory area dest.',
			':func:`ft_memmove`: Copies n bytes from memory area src to memory area dest, handling overlapping memory areas.',
			':func:`ft_memchr`: Locates the first occurrence of c in the first n bytes of the memory area pointed to by s.',
			':func:`ft_memcmp`: Compares the first n bytes of memory areas s1 and s2.',
			':func:`ft_calloc`: Allocates memory for an array of nmemb elements of size bytes each and sets the memory to zero.'
		],
        'output_dir': 'libft/memory'
	},
    {
        'function_name': 'ft_lstadd_back',
        'parameters': 't_list **lst, t_list *new',
        'description': 'Adds the element new at the end of the list lst.',
        'param_types': ['t_list **lst', 't_list *new'],
        'param_descriptions': [
            'Pointer to the pointer to the first element of the list.',
            'Pointer to the element to add to the list.'
        ],
        'return_description': 'None.',
        'example': [
            't_list *lst = NULL;',
            't_list *new = ft_lstnew("Hello, World!");',
            'ft_lstadd_back(&lst, new);',
            '// lst is now a list containing "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.',
            ':func:`ft_lstnew`: Allocates memory for a new element with the content content.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstadd_front',
        'parameters': 't_list **lst, t_list *new',
        'description': 'Adds the element new at the beginning of the list lst.',
        'param_types': ['t_list **lst', 't_list *new'],
        'param_descriptions': [
            'Pointer to the pointer to the first element of the list.',
            'Pointer to the element to add to the list.'
        ],
        'return_description': 'None.',
        'example': [
            't_list *lst = NULL;',
            't_list *new = ft_lstnew("Hello, World!");',
            'ft_lstadd_front(&lst, new);',
            '// lst is now a list containing "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.',
            ':func:`ft_lstnew`: Allocates memory for a new element with the content content.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstclear',
        'parameters': 't_list **lst, void (*del)(void *)',
        'description': 'Deletes and frees the memory of the elements of the list lst.',
        'param_types': ['t_list **lst', 'void (*del)(void*)'],
        'param_descriptions': [
            'Pointer to the pointer to the first element of the list.',
            'Function to delete the content of an element.'
        ],
        'return_description': 'None.',
        'example': [
            't_list *lst = NULL;',
            't_list *new = ft_lstnew("Hello, World!");',
            'ft_lstadd_back(&lst, new);',
            'ft_lstclear(&lst, &free);',
            '// lst is now NULL'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.',
            ':func:`ft_lstnew`: Allocates memory for a new element with the content content.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstdelone',
        'parameters': 't_list *lst, void (*del)(void *)',
        'description': 'Deletes and frees the memory of the element lst.',
        'param_types': ['t_list *lst', 'void (*del)(void*)'],
        'param_descriptions': [
            'Pointer to the element to delete.',
            'Function to delete the content of an element.'
        ],
        'return_description': 'None.',
        'example': [
            't_list *lst = NULL;',
            't_list *new = ft_lstnew("Hello, World!");',
            'ft_lstadd_back(&lst, new);',
            'ft_lstdelone(new, &free);',
            '// lst is now NULL'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.',
            ':func:`ft_lstnew`: Allocates memory for a new element with the content content.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstiter',
        'parameters': 't_list *lst, void (*f)(void *)',
        'description': 'Iterates over the elements of the list lst and applies the function f.',
        'param_types': ['t_list *lst', 'void (*f)(void*)'],
        'param_descriptions': [
            'Pointer to the first element of the list.',
            'Function to apply to each element.'
        ],
        'return_description': 'None.',
        'example': [
            't_list *lst = NULL;',
            't_list *new = ft_lstnew("Hello, World!");',
            'ft_lstadd_back(&lst, new);',
            'ft_lstiter(lst, &print_elem);',
            '// prints "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.',
            ':func:`ft_lstnew`: Allocates memory for a new element with the content content.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstlast',
        'parameters': 't_list *lst',
        'description': 'Returns a pointer to the last element of the list lst.',
        'param_types': ['t_list *lst'],
        'param_descriptions': [
            'Pointer to the first element of the list.'
        ],
        'return_description': 'Pointer to the last element of the list or NULL if the list is empty.',
        'example': [
            't_list *lst = NULL;',
            't_list *new = ft_lstnew("Hello, World!");',
            'ft_lstadd_back(&lst, new);',
            't_list *last = ft_lstlast(lst);',
            '// last points to the element containing "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.',
            ':func:`ft_lstnew`: Allocates memory for a new element with the content content.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstmap',
        'parameters': 't_list *lst, void *(*f)(void *), void (*del)(void *)',
        'description': 'Iterates over the elements of the list lst and applies the function f to create a new list.',
        'param_types': ['t_list *lst', 'void *(*f)(void*)', 'void (*del)(void*)'],
        'param_descriptions': [
            'Pointer to the first element of the list.',
            'Function to apply to each element.',
            'Function to delete the content of an element.'
        ],
        'return_description': 'Pointer to the new list or NULL if memory allocation fails.',
        'example': [
            't_list *lst = NULL;',
            't_list *new = ft_lstnew("Hello, World!");',
            'ft_lstadd_back(&lst, new);',
            't_list *new_lst = ft_lstmap(lst, &duplicate_elem, &free);',
            '// new_lst is a list containing "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstnew`: Allocates memory for a new element with the content content.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstnew',
        'parameters': 'void *content',
        'description': 'Allocates memory for a new element with the content content.',
        'param_types': ['void *content'],
        'param_descriptions': [
            'Pointer to the content to store in the new element.'
        ],
        'return_description': 'Pointer to the new element or NULL if memory allocation fails.',
        'example': [
            't_list *new = ft_lstnew("Hello, World!");',
            '// new points to an element containing "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstsize',
        'parameters': 't_list *lst',
        'description': 'Counts the number of elements in the list lst.',
        'param_types': ['t_list *lst'],
        'param_descriptions': [
            'Pointer to the first element of the list.'
        ],
        'return_description': 'Number of elements in the list.',
        'example': [
            't_list *lst = NULL;',
            't_list *new = ft_lstnew("Hello, World!");',
            'ft_lstadd_back(&lst, new);',
            'int size = ft_lstsize(lst);',
            '// size is 1'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_lstmin_max_int',
        'parameters': 't_list *lst, int *min, int *max',
        'description': 'Finds the minimum and maximum integer values in the list lst.',
        'param_types': ['t_list *lst', 'int *min', 'int *max'],
        'param_descriptions': [
            'Pointer to the first element of the list.',
            'Pointer to store the minimum value.',
            'Pointer to store the maximum value.'
        ],
        'return_description': 'None.',
        'example': [
            't_list *lst = NULL;',
            'ft_lstadd_back(&lst, ft_lstnew((void *)1));',
            'ft_lstadd_back(&lst, ft_lstnew((void *)3));',
            'ft_lstadd_back(&lst, ft_lstnew((void *)2));',
            'int min, max;',
            'ft_lstmin_max_int(lst, &min, &max);',
            '// min is 1, max is 3'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ], 
        'related_functions': [
            ':func:`ft_lstadd_back`: Adds the element new at the end of the list lst.',
            ':func:`ft_lstadd_front`: Adds the element new at the beginning of the list lst.',
            ':func:`ft_lstclear`: Deletes and frees the memory of the elements of the list lst.',
            ':func:`ft_lstdelone`: Deletes and frees the memory of the element lst.',
            ':func:`ft_lstiter`: Iterates over the elements of the list lst and applies the function f.',
            ':func:`ft_lstlast`: Returns a pointer to the last element of the list lst.',
            ':func:`ft_lstmap`: Iterates over the elements of the list lst and applies the function f to create a new list.'
        ],
        'output_dir': 'libft/lists'
    },
    {
        'function_name': 'ft_strchr',
        'parameters': 'const char *s, int c',
        'description': 'Locates the first occurrence of c in the string s.',
        'param_types': ['constchar *s', 'int c'],
        'param_descriptions': [
            'Pointer to the string to search.',
            'The character to search for.'
        ],
        'return_description': 'Pointer to the located character or NULL if the character is not found.',
        'example': [
            'char *str = "Hello, World!";',
            'char *result = ft_strchr(str, \',\');',
            '// result points to the comma in str'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strrchr`: Locates the last occurrence of c in the string s.',
            ':func:`ft_strnstr`: Locates the first occurrence of the string needle in the string haystack, up to n characters.',
            ':func:`ft_strncmp`: Compares the first n bytes of string s1 to string s2.',
            ':func:`ft_strlen`: Calculates the length of the string s.',
            ':func:`ft_strlcpy`: Copies up to size - 1 characters from the string src to the string dst.',
            ':func:`ft_strlcat`: Appends up to size - 1 characters from the string src to the string dst.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strdup',
        'parameters': 'const char *s',
        'description': 'Allocates memory for a copy of the string s.',
        'param_types': ['constchar *s'],
        'param_descriptions': [
            'Pointer to the string to duplicate.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'char *str = "Hello, World!";',
            'char *dup = ft_strdup(str);',
            '// dup points to a copy of str'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strcpy`: Copies the string src to dst.',
            ':func:`ft_strncpy`: Copies at most n bytes from the string src to dst.',
            ':func:`ft_strjoin`: Concatenates the strings s1 and s2.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_striteri',
        'parameters': 'char *s, void (*f)(unsigned int, char *)',
        'description': 'Applies the function f to each character of the string s with its index as argument.',
        'param_types': ['char *s', 'void (*f)(unsignedint, char*)'],
        'param_descriptions': [
            'Pointer to the string to iterate over.',
            'Function to apply to each character.'
        ],
        'return_description': 'None.',
        'example': [
            'char str[] = "Hello, World!";',
            'ft_striteri(str, &print_char_index);',
            '// prints "0:H 1:e 2:l 3:l 4:o 5:, 6: 7:W 8:o 9:r 10:l 11:d 12:!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_striter`: Applies the function f to each character of the string s.',
            ':func:`ft_strmap`: Applies the function f to each character of the string s to create a new string.',
            ':func:`ft_strmapi`: Applies the function f to each character of the string s with its index as argument to create a new string.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strjoin_free_s1',
        'parameters': 'char *s1, char *s2',
        'description': 'Concatenates the strings s1 and s2 and frees s1.',
        'param_types': ['char *s1', 'char *s2'],
        'param_descriptions': [
            'Pointer to the first string.',
            'Pointer to the second string.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'char *s1 = ft_strdup("Hello, ");',
            'char *s2 = "World!";',
            'char *joined = ft_strjoin_free_s1(s1, s2);',
            '// joined points to "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strjoin`: Concatenates the strings s1 and s2.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strjoin',
        'parameters': 'char *s1, char *s2',
        'description': 'Concatenates the strings s1 and s2.',
        'param_types': ['char *s1', 'char *s2'],
        'param_descriptions': [
            'Pointer to the first string.',
            'Pointer to the second string.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'char *s1 = "Hello, ";',
            'char *s2 = "World!";',
            'char *joined = ft_strjoin(s1, s2);',
            '// joined points to "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strjoin_free_s1`: Concatenates the strings s1 and s2 and frees s1.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strlcat',
        'parameters': 'char *dst, const char *src, size_t size',
        'description': 'Appends up to size - 1 characters from the string src to the string dst.',
        'param_types': ['char *dst', 'constchar *src', 'size_t size'],
        'param_descriptions': [
            'Pointer to the destination string.',
            'Pointer to the source string.',
            'Size of the destination buffer.'
        ],
        'return_description': 'Length of the string that would have been created if there were enough space.',
        'example': [
            'char dst[15] = "Hello, ";',
            'char *src = "World!";',
            'size_t len = ft_strlcat(dst, src, 15);',
            '// dst is now "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strlcpy`: Copies up to size - 1 characters from the string src to the string dst.',
            ':func:`ft_strjoin`: Concatenates the strings s1 and s2.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strlcpy',
        'parameters': 'char *dst, const char *src, size_t size',
        'description': 'Copies up to size - 1 characters from the string src to the string dst.',
        'param_types': ['char *dst', 'constchar *src', 'size_t size'],
        'param_descriptions': [
            'Pointer to the destination string.',
            'Pointer to the source string.',
            'Size of the destination buffer.'
        ],
        'return_description': 'Length of the string that would have been created if there were enough space.',
        'example': [
            'char dst[15];',
            'char *src = "Hello, World!";',
            'size_t len = ft_strlcpy(dst, src, 15);',
            '// dst is now "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strlcat`: Appends up to size - 1 characters from the string src to the string dst.',
            ':func:`ft_strjoin`: Concatenates the strings s1 and s2.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strlen',
        'parameters': 'const char *s',
        'description': 'Calculates the length of the string s.',
        'param_types': ['constchar *s'],
        'param_descriptions': [
            'Pointer to the string to calculate the length of.'
        ],
        'return_description': 'Length of the string.',
        'example': [
            'char *str = "Hello, World!";',
            'size_t len = ft_strlen(str);',
            '// len is 13'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strchr`: Locates the first occurrence of c in the string s.',
            ':func:`ft_strrchr`: Locates the last occurrence of c in the string s.',
            ':func:`ft_strnstr`: Locates the first occurrence of the string needle in the string haystack, up to n characters.',
            ':func:`ft_strncmp`: Compares the first n bytes of string s1 to string s2.',
            ':func:`ft_strlcpy`: Copies up to size - 1 characters from the string src to the string dst.',
            ':func:`ft_strlcat`: Appends up to size - 1 characters from the string src to the string dst.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strmapi',
        'parameters': 'char *s, char (*f)(unsigned int, char)',
        'description': 'Applies the function f to each character of the string s with its index as argument to create a new string.',
        'param_types': ['char *s', 'char (*f)(unsignedint, char)'],
        'param_descriptions': [
            'Pointer to the string to iterate over.',
            'Function to apply to each character.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'char str[] = "Hello, World!";',
            'char *new_str = ft_strmapi(str, &duplicate_char);',
            '// new_str is a copy of str'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_striter`: Applies the function f to each character of the string s.',
            ':func:`ft_strmap`: Applies the function f to each character of the string s to create a new string.',
            ':func:`ft_strjoin`: Concatenates the strings s1 and s2.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strncmp',
        'parameters': 'const char *s1, const char *s2, size_t n',
        'description': 'Compares the first n bytes of string s1 to string s2.',
        'param_types': ['constchar *s1', 'constchar *s2', 'size_t n'],
        'param_descriptions': [
            'Pointer to the first string.',
            'Pointer to the second string.',
            'Number of bytes to compare.'
        ],
        'return_description': 'Integer less than, equal to, or greater than zero if the first n bytes of s1 are found, respectively, to be less than, to match, or be greater than the first n bytes of s2.',
        'example': [
            'char str1[15] = "Hello, World!";',
            'char str2[15] = "Hello, World!";',
            'int result = ft_strncmp(str1, str2, 14);',
            '// result is 0'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strchr`: Locates the first occurrence of c in the string s.',
            ':func:`ft_strrchr`: Locates the last occurrence of c in the string s.',
            ':func:`ft_strnstr`: Locates the first occurrence of the string needle in the string haystack, up to n characters.',
            ':func:`ft_strlen`: Calculates the length of the string s.',
            ':func:`ft_strlcpy`: Copies up to size - 1 characters from the string src to the string dst.',
            ':func:`ft_strlcat`: Appends up to size - 1 characters from the string src to the string dst.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strnjoin_free_s1',
        'parameters': 'char *s1, char *s2, size_t len',
        'description': 'Concatenates the first len characters of the strings s1 and s2 and frees s1.',
        'param_types': ['char *s1', 'char *s2', 'size_t len'],
        'param_descriptions': [
            'Pointer to the first string.',
            'Pointer to the second string.',
            'Number of characters to concatenate.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'char *s1 = ft_strdup("Hello, ");',
            'char *s2 = "World!";',
            'char *joined = ft_strnjoin_free_s1(s1, s2, 5);',
            '// joined points to "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strnjoin`: Concatenates the first len characters of the strings s1 and s2.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strnjoin',
        'parameters': 'char *s1, char *s2, size_t len',
        'description': 'Concatenates the first len characters of the strings s1 and s2.',
        'param_types': ['char *s1', 'char *s2', 'size_t len'],
        'param_descriptions': [
            'Pointer to the first string.',
            'Pointer to the second string.',
            'Number of characters to concatenate.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'char *s1 = "Hello, ";',
            'char *s2 = "World!";',
            'char *joined = ft_strnjoin(s1, s2, 5);',
            '// joined points to "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strnjoin_free_s1`: Concatenates the first len characters of the strings s1 and s2 and frees s1.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strnstr',
        'parameters': 'const char *haystack, const char *needle, size_t len',
        'description': 'Locates the first occurrence of the string needle in the string haystack, up to len characters.',
        'param_types': ['constchar *haystack', 'constchar *needle', 'size_t len'],
        'param_descriptions': [
            'Pointer to the string to search.',
            'Pointer to the string to find.',
            'Number of characters to search.'
        ],
        'return_description': 'Pointer to the located string or NULL if the string is not found.',
        'example': [
            'char *haystack = "Hello, World!";',
            'char *needle = "World";',
            'char *result = ft_strnstr(haystack, needle, 13);',
            '// result points to "World" in haystack'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strchr`: Locates the first occurrence of c in the string s.',
            ':func:`ft_strrchr`: Locates the last occurrence of c in the string s.',
            ':func:`ft_strncmp`: Compares the first n bytes of string s1 to string s2.',
            ':func:`ft_strlen`: Calculates the length of the string s.',
            ':func:`ft_strlcpy`: Copies up to size - 1 characters from the string src to the string dst.',
            ':func:`ft_strlcat`: Appends up to size - 1 characters from the string src to the string dst.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strrchr',
        'parameters': 'const char *s, int c',
        'description': 'Locates the last occurrence of c in the string s.',
        'param_types': ['constchar *s', 'int c'],
        'param_descriptions': [
            'Pointer to the string to search.',
            'The character to search for.'
        ],
        'return_description': 'Pointer to the located character or NULL if the character is not found.',
        'example': [
            'char *str = "Hello, World!";',
            'char *result = ft_strrchr(str, \'o\');',
            '// result points to the last "o" in str'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strchr`: Locates the first occurrence of c in the string s.',
            ':func:`ft_strnstr`: Locates the first occurrence of the string needle in the string haystack, up to n characters.',
            ':func:`ft_strncmp`: Compares the first n bytes of string s1 to string s2.',
            ':func:`ft_strlen`: Calculates the length of the string s.',
            ':func:`ft_strlcpy`: Copies up to size - 1 characters from the string src to the string dst.',
            ':func:`ft_strlcat`: Appends up to size - 1 characters from the string src to the string dst.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strtrim',
        'parameters': 'char *s1, char *set',
        'description': 'Allocates memory for a copy of the string s without leading and trailing whitespaces.',
        'param_types': ['char *s1', 'char *set'],
        'param_descriptions': [
            'Pointer to the string to trim.',
            'Pointer to the set of characters to trim.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'char *s = "  Hello, World!  ";',
            'char *trimmed = ft_strtrim(s, " ");',
            '// trimmed points to "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strjoin`: Concatenates the strings s1 and s2.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_substr',
        'parameters': 'char *s, unsigned int start, size_t len',
        'description': 'Allocates memory for a substring of the string s.',
        'param_types': ['char *s', 'unsignedint start', 'size_t len'],
        'param_descriptions': [
            'Pointer to the string to create a substring of.',
            'Index of the first character of the substring.',
            'Number of characters in the substring.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'char *s = "Hello, World!";',
            'char *sub = ft_substr(s, 7, 5);',
            '// sub points to "World"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strjoin`: Concatenates the strings s1 and s2.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_tolower',
        'parameters': 'int c',
        'description': 'Converts the character c to lowercase.',
        'param_types': ['int c'],
        'param_descriptions': [
            'Character to convert.'
        ],
        'return_description': 'Lowercase character if c is an uppercase letter, c otherwise.',
        'example': [
            'char c = \'A\';',
            'char lower = ft_tolower(c);',
            '// lower is \'a\''
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_toupper`: Converts the character c to uppercase.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_toupper',
        'parameters': 'int c',
        'description': 'Converts the character c to uppercase.',
        'param_types': ['int c'],
        'param_descriptions': [
            'Character to convert.'
        ],
        'return_description': 'Uppercase character if c is a lowercase letter, c otherwise.',
        'example': [
            'char c = \'a\';',
            'char upper = ft_toupper(c);',
            '// upper is \'A\''
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_tolower`: Converts the character c to lowercase.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_strcpy',
        'parameters': 'char *dst, const char *src',
        'description': 'Copies the string src to dst.',
        'param_types': ['char *dst', 'constchar *src'],
        'param_descriptions': [
            'Pointer to the destination string.',
            'Pointer to the source string.'
        ],
        'return_description': 'Pointer to the destination string.',
        'example': [
            'char dst[15];',
            'char *src = "Hello, World!";',
            'char *result = ft_strcpy(dst, src);',
            '// dst is now "Hello, World!"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strdup`: Allocates memory for a copy of the string s.',
            ':func:`ft_strncpy`: Copies at most n bytes from the string src to dst.',
            ':func:`ft_strjoin`: Concatenates the strings s1 and s2.',
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/strings'
    },
    {
        'function_name': 'ft_atoi',
        'parameters': 'const char *str',
        'description': 'Converts the initial portion of the string str to an integer.',
        'param_types': ['constchar *str'],
        'param_descriptions': [
            'Pointer to the string to convert.'
        ],
        'return_description': 'The converted integer.',
        'example': [
            'char *str = "42";',
            'int num = ft_atoi(str);',
            '// num is 42'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_itoa`: Converts an integer to a string.'
        ],
        'output_dir': 'libft/conversion'
    },
    {
        'function_name': 'ft_itoa',
        'parameters': 'int n',
        'description': 'Convert an integer to a string.',
        'param_types': ['int n'],
        'param_descriptions': [
            'Integer to convert.'
        ],
        'return_description': 'Pointer to the new string or NULL if memory allocation fails.',
        'example': [
            'int num = 42;',
            'char *str = ft_itoa(num);',
            '// str is "42"'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_atoi`: Converts the initial portion of the string str to an integer.'
        ],
        'output_dir': 'libft/conversion'
    },
    {
        'function_name': 'ft_split',
        'parameters': 'char *s, char c',
        'description': 'Allocates memory for an array of strings obtained by splitting s using the character c as a delimiter.',
        'param_types': ['char *s', 'char c'],
        'param_descriptions': [
            'Pointer to the string to split.',
            'Delimiter character.'
        ],
        'return_description': 'Pointer to the array of strings or NULL if memory allocation fails.',
        'example': [
            'char *s = "Hello, World!";',
            'char **split = ft_split(s, \',\');',
            '// split is ["Hello", " World!"]'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_strtrim`: Allocates memory for a copy of the string s without leading and trailing whitespaces.',
            ':func:`ft_substr`: Allocates memory for a substring of the string s.'
        ],
        'output_dir': 'libft/conversion'
    },
    {
        'function_name': 'ft_putchar_fd',
        'parameters': 'char c, int fd',
        'description': 'Outputs the character c to the given file descriptor.',
        'param_types': ['char c', 'int fd'],
        'param_descriptions': [
            'Character to output.',
            'File descriptor to write to.'
        ],
        'return_description': 'None.',
        'example': [
            'ft_putchar_fd(\'c\', 1);',
            '// outputs \'c\' to the standard output'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_putstr_fd`: Outputs the string s to the given file descriptor.',
            ':func:`ft_putendl_fd`: Outputs the string s to the given file descriptor followed by a newline.',
            ':func:`ft_putnbr_fd`: Outputs the integer n to the given file descriptor.'
        ],
        'output_dir': 'libft/fd_operations'
    },
    {
        'function_name': 'ft_putendl_fd',
        'parameters': 'char *s, int fd',
        'description': 'Outputs the string s to the given file descriptor followed by a newline.',
        'param_types': ['char *s', 'int fd'],
        'param_descriptions': [
            'String to output.',
            'File descriptor to write to.'
        ],
        'return_description': 'None.',
        'example': [
            'ft_putendl_fd("Hello, World!", 1);',
            '// outputs "Hello, World!" to the standard output followed by a newline'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_putchar_fd`: Outputs the character c to the given file descriptor.',
            ':func:`ft_putstr_fd`: Outputs the string s to the given file descriptor.',
            ':func:`ft_putnbr_fd`: Outputs the integer n to the given file descriptor.'
        ],
        'output_dir': 'libft/fd_operations'
    },
    {
        'function_name': 'ft_putnbr_fd',
        'parameters': 'int n, int fd',
        'description': 'Outputs the integer n to the given file descriptor.',
        'param_types': ['int n', 'int fd'],
        'param_descriptions': [
            'Integer to output.',
            'File descriptor to write to.'
        ],
        'return_description': 'None.',
        'example': [
            'ft_putnbr_fd(42, 1);',
            '// outputs 42 to the standard output'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_putchar_fd`: Outputs the character c to the given file descriptor.',
            ':func:`ft_putstr_fd`: Outputs the string s to the given file descriptor.',
            ':func:`ft_putendl_fd`: Outputs the string s to the given file descriptor followed by a newline.'
        ],
        'output_dir': 'libft/fd_operations'
    },
    {
        'function_name': 'ft_putstr_fd',
        'parameters': 'char *s, int fd',
        'description': 'Outputs the string s to the given file descriptor.',
        'param_types': ['char *s', 'int fd'],
        'param_descriptions': [
            'String to output.',
            'File descriptor to write to.'
        ],
        'return_description': 'None.',
        'example': [
            'ft_putstr_fd("Hello, World!", 1);',
            '// outputs "Hello, World!" to the standard output'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_putchar_fd`: Outputs the character c to the given file descriptor.',
            ':func:`ft_putendl_fd`: Outputs the string s to the given file descriptor followed by a newline.',
            ':func:`ft_putnbr_fd`: Outputs the integer n to the given file descriptor.'
        ],
        'output_dir': 'libft/fd_operations'
    },
    {
        'function_name': 'ft_rand',
        'parameters': 'unsigned int min, unsigned int max',
        'description': 'Generates a random number between min and max.',
        'param_types': ['unsignedint min', 'unsignedint max'],
        'param_descriptions': [
            'Minimum value of the random number.',
            'Maximum value of the random number.'
        ],
        'return_description': 'Random number between min and max.',
        'example': [
            'unsigned int num = ft_rand(1, 10);',
            '// num is between 1 and 10'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
        ],
        'output_dir': 'libft/others'
    },
    {
        'function_name': 'ft_isalnum',
        'parameters': 'int c',
        'description': 'Checks if the character c is alphanumeric.',
        'param_types': ['int c'],
        'param_descriptions': [
            'Character to check.'
        ],
        'return_description': '1 if c is alphanumeric, 0 otherwise.',
        'example': [
            'int result = ft_isalnum(\'a\');',
            '// result is 1'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_isalpha`: Checks if the character c is alphabetic.',
            ':func:`ft_isdigit`: Checks if the character c is a digit.',
            ':func:`ft_isascii`: Checks if the character c is ASCII.',
            ':func:`ft_isprint`: Checks if the character c is printable.',
            ':func:`ft_strequ`: Compares the strings s1 and s2.',
        ],
        'output_dir': 'libft/checks'
    },
    {
        'function_name': 'ft_isalpha',
        'parameters': 'int c',
        'description': 'Checks if the character c is alphabetic.',
        'param_types': ['int c'],
        'param_descriptions': [
            'Character to check.'
        ],
        'return_description': '1 if c is alphabetic, 0 otherwise.',
        'example': [
            'int result = ft_isalpha(\'a\');',
            '// result is 1'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_isalnum`: Checks if the character c is alphanumeric.',
            ':func:`ft_isdigit`: Checks if the character c is a digit.',
            ':func:`ft_isascii`: Checks if the character c is ASCII.',
            ':func:`ft_isprint`: Checks if the character c is printable.',
            ':func:`ft_strequ`: Compares the strings s1 and s2.',
        ],
        'output_dir': 'libft/checks'
    },
    {
        'function_name': 'ft_isascii',
        'parameters': 'int c',
        'description': 'Checks if the character c is ASCII.',
        'param_types': ['int c'],
        'param_descriptions': [
            'Character to check.'
        ],
        'return_description': '1 if c is ASCII, 0 otherwise.',
        'example': [
            'int result = ft_isascii(\'a\');',
            '// result is 1'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_isalnum`: Checks if the character c is alphanumeric.',
            ':func:`ft_isalpha`: Checks if the character c is alphabetic.',
            ':func:`ft_isdigit`: Checks if the character c is a digit.',
            ':func:`ft_isprint`: Checks if the character c is printable.',
            ':func:`ft_strequ`: Compares the strings s1 and s2.',
        ],
        'output_dir': 'libft/checks'
    },
    {
        'function_name': 'ft_isdigit',
        'parameters': 'int c',
        'description': 'Checks if the character c is a digit.',
        'param_types': ['int c'],
        'param_descriptions': [
            'Character to check.'
        ],
        'return_description': '1 if c is a digit, 0 otherwise.',
        'example': [
            'int result = ft_isdigit(\'1\');',
            '// result is 1'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_isalnum`: Checks if the character c is alphanumeric.',
            ':func:`ft_isalpha`: Checks if the character c is alphabetic.',
            ':func:`ft_isascii`: Checks if the character c is ASCII.',
            ':func:`ft_isprint`: Checks if the character c is printable.',
            ':func:`ft_strequ`: Compares the strings s1 and s2.',
        ],
        'output_dir': 'libft/checks'
    },
    {
        'function_name': 'ft_isprint',
        'parameters': 'int c',
        'description': 'Checks if the character c is printable.',
        'param_types': ['int c'],
        'param_descriptions': [
            'Character to check.'
        ],
        'return_description': '1 if c is printable, 0 otherwise.',
        'example': [
            'int result = ft_isprint(\' \');',
            '// result is 1'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_isalnum`: Checks if the character c is alphanumeric.',
            ':func:`ft_isalpha`: Checks if the character c is alphabetic.',
            ':func:`ft_isascii`: Checks if the character c is ASCII.',
            ':func:`ft_isdigit`: Checks if the character c is a digit.',
            ':func:`ft_strequ`: Compares the strings s1 and s2.',
        ],
        'output_dir': 'libft/checks'
    },
    {
        'function_name': 'ft_strequ',
        'parameters': 'const char *s1, const char *s2',
        'description': 'Compares the strings s1 and s2.',
        'param_types': ['constchar *s1', 'constchar *s2'],
        'param_descriptions': [
            'Pointer to the first string.',
            'Pointer to the second string.'
        ],
        'return_description': '1 if the strings are equal, 0 otherwise.',
        'example': [
            'int result = ft_strequ("Hello", "Hello");',
            '// result is 1'
        ],
        'notes': [
            'The function does not check for null pointers.'
        ],
        'related_functions': [
            ':func:`ft_isalnum`: Checks if the character c is alphanumeric.',
            ':func:`ft_isalpha`: Checks if the character c is alphabetic.',
            ':func:`ft_isascii`: Checks if the character c is ASCII.',
            ':func:`ft_isdigit`: Checks if the character c is a digit.',
            ':func:`ft_isprint`: Checks if the character c is printable.',
        ],
        'output_dir': 'libft/checks'
    }
]

# Define your function categories and their corresponding directories
categories = {
    "Memory Functions": "memory",
    "List Functions": "lists",
    "String Functions": "strings",
    "Conversion Functions": "conversion",
    "Fd Operations Functions": "fd_operations",
    "Checks Functions": "checks",
    "Others": "others",  # Use this for functions not falling under specific categories
}

# Generate .rst files for each function
def generate_rst_files():
    # Initialize content for libft.rst
    libft_rst_content = [
        "Libft Documentation",
        "===================",
        "",
        "This project is a library of functions.",
        ""
    ]

    # Initialize a dictionary to keep track of function entries for each category
    category_entries = {category: [] for category in categories.keys()}

    for function in functions:
        # Create the .rst filename
        rst_filename = os.path.join(function['output_dir'], f"{function['function_name']}.rst")
        
        print(f"Creating output directory: {function['output_dir']}")
        os.makedirs(function['output_dir'], exist_ok=True)

        # Prepare param_descriptions as a formatted string
        param_descriptions_formatted = "\n".join(
            f"   - **{param.split()[1]}** (*{param.split()[0]}*): {desc}"
            for param, desc in zip(function['param_types'], function['param_descriptions'])
        )

        # Prepare param_types as a formatted string
        param_types_formatted = "\n   ".join(f":param {param_type}:" for param_type in function['param_types'])

        # Prepare notes as a formatted string
        notes_formatted = "\n   ".join(f"- {note}" for note in function['notes'])

        # Prepare related functions as a formatted string in list format
        related_functions_formatted = "\n   ".join(f"- {func}" for func in function['related_functions'])

        # Prepare example as a formatted string
        example_formatted = "\n       ".join(line for line in function['example'])

        # Fill in the template with function details
        with open(rst_filename, 'w') as f:
            print(f"Writing RST content for {function['function_name']} to {rst_filename}...")
            f.write(template.format(
                param_descriptions=param_descriptions_formatted,
                notes=notes_formatted,
                related_functions=related_functions_formatted,
                example=example_formatted,
                function_name=function['function_name'],
                parameters=function['parameters'],
                description=function['description'],
                param_types=function['param_types'],
                return_description=function['return_description']
            ))

        print(f"Generated documentation for {function['function_name']} in {rst_filename}.")

        # Determine the category of the function and add it to the category_entries
        for category, directory in categories.items():
            if directory in function['output_dir']:
                category_entries[category].append(f"{directory}/{function['function_name']}")
                break

    # Now, generate the libft.rst content based on category_entries
    for category, entries in category_entries.items():
        underline = "-" * len(category)
        libft_rst_content.append(f"{category}\n{underline}")
        libft_rst_content.append("\n.. toctree::\n   :maxdepth: 2\n")
        libft_rst_content.extend(f"   {entry}" for entry in entries)
        libft_rst_content.append("")  # Add a newline after each category

    # Write to libft.rst
    with open("libft/libft_index.rst", "w") as f:
        f.write("\n".join(libft_rst_content))

    print("Updated libft.rst with all functions.")

if __name__ == "__main__":
    generate_rst_files()
