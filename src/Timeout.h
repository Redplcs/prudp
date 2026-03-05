#ifndef _Timeout_H_
#define _Timeout_H_

#include <Platform/Time.h>

class Timeout {
public:

	Timeout();
	~Timeout();

	void SetExpirationTime(Time tTime);
	void SetRelativeExpirationTime(long lTime);
	bool IsExpired();
	bool IsAwaited();

	void SetRTO(unsigned long ulRTO);
	unsigned long GetRTO();

	void Start();
	Time GetAwaitedTime();

	bool operator<(Timeout &refTimeout);

};

#endif
