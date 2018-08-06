/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef TIME_HH
	# define TIME_HH

# include "project.h"

OBJECT_CREATOR
(
	Times,

	struct timespec *time;
	bool refresh;
);

OBJECT_CREATOR
(
	TimeManager,

	Times *timeout;
	Times *now_io;
	Times *now_pl;
);

# define _now_io this->time->now_io

# define _now_pl this->time->now_pl

# define reload(t) CALL_FUNCTION_PARAMS(refreshTime, t);

# define convert(t) CALL_FUNCTION_PARAMS(TimeConverter, t)

# define addTime(x, y) CALL_FUNCTION_PARAMS(addTime, \
			setUnknown\
			(\
				x, \
				CALL_FUNCTION_PARAMS(TimeConverter, y)\
			));

# define addTimes(x, y) CALL_FUNCTION_PARAMS(addTime, \
			setUnknown\
			(\
				x, \
				y\
			));

# define canI(t1, t2) CALL_FUNCTION_PARAMS(isActionPossible, \
						setUnknown(t1, t2))

# define load CALL_FUNCTION(createTime)

CREATE_FUNCTION_PARAMS(void, refreshTime, Times *_time)
{
	_(clock_gettime(CLOCK_BOOTTIME, _time->time))
}

CREATE_FUNCTION(Times *, createTime)
{
	__MALLOC_CR__(Times, _time, sizeof(Times))

	__MALLOC__(_time->time, sizeof(struct timespec))

	reload(_time)

	__return(_time)
}

CREATE_FUNCTION_PARAMS(Times *, cloneTime, Times *clone)
{
	__MALLOC_CR__(Times, _time, sizeof(Times))

	__MALLOC__(_time->time, sizeof(struct timespec))

	_(_time->time->tv_sec = clone->time->tv_sec)
	_(_time->time->tv_nsec = clone->time->tv_nsec)

	__return(_time)
}

CREATE_FUNCTION_PARAMS(void, addTime, Unknown unknown)
{
	_get(Times, _time, alpha)
	_get(Times, __time, beta)

	if (_time->refresh)
		reload(_time)

	_A_(_time->time->tv_sec, __time->time->tv_sec)
	_A_(_time->time->tv_nsec, __time->time->tv_nsec)
}

CREATE_FUNCTION_PARAMS(void, delTime, Unknown unknown)
{
	_get(Times, _time, alpha)
	_get(Times, __time, beta)

	if (_time->refresh)
		reload(_time)

	_D_(_time->time->tv_sec, __time->time->tv_sec)
	_D_(_time->time->tv_nsec, __time->time->tv_nsec)

}

CREATE_FUNCTION_PARAMS(Times *, TimeConverter, int sec)
{
	__MALLOC_CR__(Times, _time, sizeof(Times))

	__MALLOC__(_time->time, sizeof(struct timespec))

	_(double a = (sec / (double)(this->params->freq)) * 1000000)

	_(_time_attr x = (_time_attr)a)

	_(_time->time->tv_sec = x / 1000000)

	_(_time->time->tv_nsec = (x % 1000000) * 100)

	__return(_time)
}

CREATE_FUNCTION(TimeManager *, setTimeManager)
{
	__MALLOC_CR__(TimeManager, tm, sizeof(TimeManager))

	_(tm->timeout = convert(1))
	_(tm->now_io = load)
	_(tm->now_pl = load)
	__return(tm)
}

CREATE_FUNCTION_PARAMS(bool, isActionPossible, Unknown unknown)
{
	_get(Times, _time, alpha)
	_get(Times, __time, beta)

	__return(_time->time->tv_sec > __time->time->tv_sec ? true :
		_time->time->tv_sec == __time->time->tv_sec &&
		_time->time->tv_nsec > __time->time->tv_nsec ?
		true : false)
}

CREATE_FUNCTION_PARAMS(void, destroyTime, Times *_time)
{
	_(free(_time->time))
	_(free(_time))
}

CREATE_FUNCTION(void, destroyTimeManager)
{
	_(CALL_FUNCTION_PARAMS(destroyTime, this->time->timeout))
	_(CALL_FUNCTION_PARAMS(destroyTime, _now_io))
	_(CALL_FUNCTION_PARAMS(destroyTime, _now_pl))
	_(free(this->time))
}

# endif
