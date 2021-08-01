#pragma once

class Mutex {

};

class  Lock {
public:
	explicit Lock(Mutex &m): mutexptr(m, unlock){
		lock(mutexptr.get());
	}
private:
	std::shared_ptr<Mutex> mutexptr;

};

