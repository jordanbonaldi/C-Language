/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef BUFFER_HH
	# define BUFFER_HH

# include "project.h"

# define MAX_SIZE 4096

# define CHECK_SIZE(buffer) buffer->write >= buffer->read ? \
			(int)(buffer->write - buffer->read) : \
			(MAX_SIZE - (int)(buffer->read - buffer->write))

# define WRITE_BUFFER(x) this->buffer->buff[(((size_t) this->buffer->write + x)\
				- (size_t)this->buffer->buff) % MAX_SIZE]

# define READ_BUFFER(x) this->buffer->buff[(((size_t) this->buffer->read + x)\
				- (size_t)this->buffer->buff) % MAX_SIZE]

OBJECT_CREATOR
(
	Buffer,

	String read;
	String write;
	char buff[MAX_SIZE];
)

CREATE_FUNCTION(void, buildBuffer)
{
	this->buffer = malloc(sizeof(Buffer));
	__(this->buffer, 1, CRITICAL);
	RESET(this->buffer->buff, MAX_SIZE);
	this->buffer->read = this->buffer->buff;
	this->buffer->write = this->buffer->buff;
}

CREATE_FUNCTION(String, readDataBuffer)
{
	int size = CHECK_SIZE(this->buffer);
	String data = malloc(size + 1);

	__(data, 1, CRITICAL);
	RESET(data, size + 1);
	FOREACH_IT(size, {
		data[index] = *this->buffer->read;
		this->buffer->read = &READ_BUFFER(1);
	});
	return data;
}

CREATE_FUNCTION_PARAMS(void, addChar, char item)
{
	if (!this->buffer->write)
		this->buffer->write = this->buffer->buff;
	*this->buffer->write = item;
	this->buffer->write = &WRITE_BUFFER(1);
}

CREATE_FUNCTION_PARAMS(void, writeDataBuffer, String data)
{
	FOREACH_LENGTH(char, data, strlen(data), {
		__SETUNUSED__(index);
		CALL_FUNCTION_PARAMS(addChar, IT);
	});
}

CREATE_FUNCTION_PARAMS(char, getData, int data)
{
	if (data >= 0)
		return READ_BUFFER(data);
	return WRITE_BUFFER(data);
}

CREATE_FUNCTION(int, getSizeLeft)
{
	if (this->buffer->write >= this->buffer->read)
		return MAX_SIZE - (int)(this->buffer->write
			- this->buffer->read);
	return (int)(this->buffer->read - this->buffer->write);
}

CREATE_FUNCTION(void, removeWrite)
{
	if (this->buffer->write != this->buffer->read)
		this->buffer->write = &WRITE_BUFFER(-1);
}

CREATE_FUNCTION(void, deleteBuffer)
{
	if (this->buffer)
		free(this->buffer);
}

# endif
