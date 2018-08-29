/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef BUFFER_HH
	# define BUFFER_HH

# include "clang.h"

# define __BUFFER_MAX_SIZE__ 4096

# define CHECK_SIZE(buffer) buffer->write >= buffer->read ? \
			(int)(buffer->write - buffer->read) : \
			(__BUFFER_MAX_SIZE__ - (int)(buffer->read - buffer->write))

# define WRITE_BUFFER(x) this->buffer->buff[(((size_t) this->buffer->write + x)\
				- (size_t)this->buffer->buff) % __BUFFER_MAX_SIZE__]

# define READ_BUFFER(x) this->buffer->buff[(((size_t) this->buffer->read + x)\
				- (size_t)this->buffer->buff) % __BUFFER_MAX_SIZE__]

$new Class
(
	Buffer,

	String read;
	String write;
	char buff[__BUFFER_MAX_SIZE__];
)

public void function(buildBuffer)
{
	alloc(this->buffer, sizeof(Buffer))
	$reset(this->buffer->buff, __BUFFER_MAX_SIZE__);
	this->buffer->read = this->buffer->buff;
	this->buffer->write = this->buffer->buff;
}

public String function(readDataBuffer)
{
	int size = CHECK_SIZE(this->buffer);

	new(char)
	alloc(data, size + 1)

	$reset(data, size + 1);
	foreach(size, {
		data[index] = *this->buffer->read;
		this->buffer->read = &READ_BUFFER(1);
	});
	return data;
}

private void function(addChar, char item)
{
	if (!this->buffer->write)
		this->buffer->write = this->buffer->buff;
	*this->buffer->write = item;
	this->buffer->write = &WRITE_BUFFER(1);
}

public void function(writeDataBuffer, String data)
{
	foreach(char, data, strlen(data), {
		call(addChar, IT);
	});
}

public char function(getData, int data)
{
	if (data >= 0)
		return READ_BUFFER(data);
	return WRITE_BUFFER(data);
}

public int function(getSizeLeft)
{
	if (this->buffer->write >= this->buffer->read)
		return __BUFFER_MAX_SIZE__ - (int)(this->buffer->write
			- this->buffer->read);
	return (int)(this->buffer->read - this->buffer->write);
}

public void function(removeWrite)
{
	if (this->buffer->write != this->buffer->read)
		this->buffer->write = &WRITE_BUFFER(-1);
}

public void function(deleteBuffer)
{
	if (this->buffer)
		free(this->buffer);
}

# endif
