
#define LOCK "lock ; "

class AtomicCounter {
public:
static inline void add(long i, AtomicCounter *v)
{
	//need asm 
}
private:
    volatile long count;
};

#undef LOCK