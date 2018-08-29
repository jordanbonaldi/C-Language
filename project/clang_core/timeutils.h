/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef TIME_HH
	# define TIME_HH

# include "clang.h"

$new Object
(
	Times,

	struct timespec *time;
	bool refresh;
)

$new Object
(
	TimeManager,

	Times *timeout;
	Times *now_io;
	Times *now_pl;
)

# define _now_io this->time->now_io

# define _now_pl this->time->now_pl

# define reload(t) call(refreshTime, t);

# define convert(t) call(TimeConverter, t)

# define addTime(x, y) call(addTime, \
			setUnknown\
			(\
				x, \
				call(TimeConverter, y)\
			));

# define addTimes(x, y) call(addTime, \
			setUnknown\
			(\
				x, \
				y\
			));

# define canI(t1, t2) call(isActionPossible, \
						setUnknown(t1, t2))

# define load call(createTime)

public void function(refreshTime, Times *_time)
{
	_(clock_gettime(CLOCK_BOOTTIME, _time->time))
}

public Times * function(createTime)
{
	new(Times)
	alloc(_time, sizeof(Times))

	alloc(_time->time, sizeof(struct timespec))

	reload(_time)

	$return(_time)
}

public Times * function(cloneTime, Times *clone)
{
	new(Times)
	alloc(_time, sizeof(Times))

	alloc(_time->time, sizeof(struct timespec))

	_(_time->time->tv_sec = clone->time->tv_sec)
	_(_time->time->tv_nsec = clone->time->tv_nsec)

	$return(_time)
}

public void function(addTime, Unknown unknown)
{
	$get(Times, _time, alpha)
	$get(Times, __time, beta)

	if (_time->refresh)
		reload(_time)

	$a(_time->time->tv_sec, __time->time->tv_sec)
	$a(_time->time->tv_nsec, __time->time->tv_nsec)
}

public void function(delTime, Unknown unknown)
{
	$get(Times, _time, alpha)
	$get(Times, __time, beta)

	if (_time->refresh)
		reload(_time)

	$d(_time->time->tv_sec, __time->time->tv_sec)
	$d(_time->time->tv_nsec, __time->time->tv_nsec)

}

public Times * function(TimeConverter, int sec)
{
	new(Times)
	alloc(_time, sizeof(Times))

	alloc(_time->time, sizeof(struct timespec))

	_(double a = (sec / 1000000))

	_(_time_attr x = (_time_attr)a)

	_(_time->time->tv_sec = x / 1000000)

	_(_time->time->tv_nsec = (x % 1000000) * 100)

	$return(_time)
}

public TimeManager * function(setTimeManager)
{
	new(TimeManager)
	alloc(tm, sizeof(TimeManager))

	_(tm->timeout = convert(1))
	_(tm->now_io = load)
	_(tm->now_pl = load)
	$return(tm)
}

public bool function(isActionPossible, Unknown unknown)
{
	$get(Times, _time, alpha)
	$get(Times, __time, beta)

	$return(_time->time->tv_sec > __time->time->tv_sec ? true :
		_time->time->tv_sec == __time->time->tv_sec &&
		_time->time->tv_nsec > __time->time->tv_nsec ?
		true : false)
}

public void function(destroyTime, Times *_time)
{
	_(free(_time->time))
	_(free(_time))
}

public void function(destroyTimeManager)
{
	_(call(destroyTime, this->time->timeout))
	_(call(destroyTime, _now_io))
	_(call(destroyTime, _now_pl))
	_(free(this->time))
}

# endif
