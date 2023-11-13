#include "stdafx.h"
#include "string_t.h"

int string_file_len(char *s)
{
	int i = 0;
	while (s[i] != EOF)
	{
		i++;
	}
	return i;
}
string_t string_file(char *s,int *file_length)
{
	int len = string_file_len(s);

	char *content = (char *)malloc(len + 1);
	memcpy(content, s, len);
	content[len] = EOF;
	string_t st = (string_t)malloc(sizeof(struct_var));
	st->len = len + 1;
	st->str = content;
	st->back = content + len - 1;
	if (strcmp(s, "\0"))
		st->empty = 1;
    *file_length = len;
	return st;
}

 string_t string(char *s)
{
	int len = strlen(s);
	
	char *content = (char *)malloc(len + 1);
	memcpy(content, s, len);
	content[len] = '\0';
	string_t st = (string_t)malloc(sizeof(struct_var));
	st->len = len + 1;
	st->str = content;
	st->back = content + len - 1;
	if (strcmp(s, "\0"))
		st->empty = 1;

	return st;
}
#define empty_str(st)   if(st->len == 0)                                                 \
{ printf("Underflow ! func:%s line:%d\n", __FUNCDNAME__, __LINE__);      \
	return '\0';       }

void push(string_t st, char s)
{
	st->str = (char *)realloc(st->str, st->len + 1);
	st->str[st->len - 1] = s;
	st->len++;
	st->str[st->len - 1] = '\0';
}
char pop(string_t st)
{
	empty_str(st);

	char temp = st->str[st->len - 1];
	st->str = (char *)realloc(st->str, st->len - 1);
	st->len--;
	st->str[st->len - 1] = '\0';
	return temp;
}
char *con(string_t a) // content of the string
{
	return a->str;
}
int length(string_t a)
{
	return a->len;
}
char at(string_t a, int i)
{
	if (i >= a->len)
	{
		printf("length limit crossed\n");
		return 0;
	}

	return a->str[i];
}
string_t copy(string_t a, string_t b)
{
	int length_b = b->len;
	if (a->len >= b->len)
	{
		memcpy(a->str, b->str, length_b);
	}
	else
	{

		a->str = (char *)realloc(a->str, length_b);
		memcpy(a->str, b->str, length_b);
		a->len = length_b;
	}
	return a;
}

string_t getlines(string_t a)
{
	int prev = 0;
	static int k = 0;
	prev = k;
	string_t tk = NULL;
	while (a->str[k] != '\n' && a->str[k] != '\0')
	{
		k++;
	}
	if (a->str[k] == '\n' || a->str[k] == '\0')
	{
		tk = (string_t)malloc(sizeof(string_t));
		tk->str = (char*)malloc(a->len);
		memcpy(tk->str, a->str + prev, k - prev + 1);
		tk->len = k - prev + 1;
		tk->empty = 0;

		k++; // \n character to traverse
	}
	return tk;
}

int locate(string_t s, string_t find_str)
{
	int ln = find_str->len - 1;
	char *arr = (char*)malloc(ln*sizeof(char));
	int i, j;
	for (i = 0; i< s->len - find_str->len - 1; i++)
	{
		memcpy(arr, s->str + i, find_str->len - 1);
		for (j = find_str->len - 1; j > 0; j--)
		{
			printf("%s\n", arr);
			if (memcmp(arr, find_str->str, j) == 0)
			{
				return i;
			}
		}
	}
	return -1;
}
string_t partOfstring(string_t s, int start, int length)
{
	char *new_str = (char*)malloc(sizeof(char)*length + 1);
	int i;
	if (length > s->len)
	{
		printf("[ERROR] $s:%s String length is Out Of Bounds ! \n", __FUNCDNAME__, __LINE__);
		return NULL;
	}

	for (i = 0; i <= length; i++)
	{
		new_str[i] = s->str[i + start];
	}
	new_str[i] = '\0';

	string_t ret = string(new_str);
	return ret;
}
char* c_string(string_t s)
{
	char *new_str = (char*)malloc(sizeof(char)*s->len + 1);
	int i;
	for (i = 0; i< s->len; i++)
	{
		new_str[i] = s->str[i];
	}
	new_str[i] = '\0';
	return new_str;
}
void manipulate(string_t s, const char *str, int start)
{
	int length = 0, length2 = 0, i;
	while (str[length] != '\0')
		length++;

	if (s->len < length + start)
	{
		printf("[ERROR] $s:%s String length is Out Of Bounds ! \n", __FUNCDNAME__, __LINE__);
		return;
	}
	length2 = s->len;

	char *temp = (char*)malloc(sizeof(s->len));
	memcpy(temp, s->str, s->len);

	if (length > length2)
	{
		s->str = (char *)realloc(s->str, length);
		memcpy(s->str, temp, length);
	}
	else if (length < length2)
	{
		s->str = (char *)realloc(s->str, length2);
		memcpy(s->str, temp, length2);
	}
	for (i = 0; i< length; i++)
	{
		s->str[i + start] = str[i];
	}

	return;
}

bool is_first(string_t str_line, int t_pos, char c)
{
	while (at(str_line, t_pos) == ' ' || at(str_line, t_pos) == '\v' || at(str_line, t_pos) == '\t')
		t_pos++;
	if (at(str_line, t_pos) == c)
		return true;
	else
		return false;
}


void swap(string_t a, string_t b)
{
	int length_a = a->len;
	int length_b = b->len;
	char *temp = (char*)malloc(sizeof(a->len));
	memcpy(temp, a->str, a->len);

	a->str = (char *)realloc(a->str, length_b);
	memcpy(a->str, b->str, length_b);
	b->str = (char *)realloc(b->str, length_a);
	memcpy(b->str, temp, length_a);

	free(temp);
}
int compare(string_t a, string_t b)
{
	char c1, c2;
	int i;
	if (a->len == b->len)
	{
		for (i = 0; i<a->len; i++)
		{
			c1 = b->str[i];
			c2 = a->str[i];
			if (c1 != c2)
			{
				return c2 - c1;
			}
		}
	}
	else
	{
		return b->len - a->len;
	}

	return 0;
}

string_t concat(string_t a, string_t b)
{

	char *ptr;
	//string_t temp;
	if (a == NULL || a->str == NULL)
	{
		printf("Error in concat as first string is empty !\n");
		return NULL;
	}
	else if (b == NULL || b->str == NULL)
	{
		return a;
	}
	a->str = (char *)realloc(a->str, a->len + b->len);
	ptr = a->str + a->len - 1;
	memcpy(ptr, b->str, b->len);

	return a;
}

string_t tokenize(string_t a, char delim)
{
	int len_counter = 0;
	static int k = 0;
	int prev = k;
	while (a->str[k] != delim && len_counter < a->len)
	{
		k++;
		len_counter++;
	}
	if (len_counter >= a->len)
		return NULL;
	char *content = (char *)malloc(len_counter + 1);
	memcpy(content, a->str + prev, len_counter); // prev needs to added for next string totokenize
	content[len_counter] = '\0';
	string_t b = (string_t)malloc(sizeof(struct_var));
	b->str = content;
	b->len = len_counter;
	b->back = content + len_counter - 1;
	b->empty = 0;
	k++;
	return b;
}
char pos(string_t a, int p)
{
	return a->str[p];
}
void string_destroy(string_t st)
{
	free(st->str);
	free(st);
}
#define append_str(a,b) concat(a,b)
#define string_instances(a,b,arr)  searchstr(c_string(a), c_string(b), arr)
int *searchstr(char *arr, char *find, int *numberOfOccurrance)
{
	int k = strlen(arr);
	int l = strlen(find);
	int i;
	int *z = (int*)malloc((k / l)*sizeof(int));
	int x = 0;
	for (i = 0; i<k; k++)
	{
		if (strncmp(arr + i, find, l) == 0)
		{
			z[x] = i;
			x++;
			*numberOfOccurrance = x;
		}
	}
	return z;
}
/*int main()
{
string_t c, d;
string_t a = string("abc-bcd-");
string_t b = string("abc");
c = string("abc\nhelo\nbye");
printf("%s\n", con(tokenize(a, '-')));
printf("%s\n", con(tokenize(a, '-')));
concat(a, b);
printf("concat is:%s\n", con(a));
push(a, '/');
printf("%s\n", con(a));
pop(a);
printf("%s\n", con(a));
swap(a, b);
printf("swapped are:%s %s\n", con(a), con(b));
printf("parsed lines are:%s %s\n", con(getlines(c)), con(getlines(c)));
printf("%d\n", locate(a, b));

printf("at string is:%c\n", at(b, 1));
string_destroy(a);
string_destroy(b);
}*/
