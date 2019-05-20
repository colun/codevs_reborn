#line 4 "codevs_r/colun11.cpp"

#define NDEBUG

#line 1 "codevs_r/../.cpp/time/report.h"

#define TIME_REPORT_H

#line 1 "codevs_r/../.cpp/time/../time/time.h"

#define TIME_TIME_H

#include <sys/time.h>
#include <unistd.h>
#include <cmath>

inline void getCpuClock(unsigned long long & t) {
    __asm__ __volatile__ ("rdtsc" : "=a"(*(unsigned int*)&t), "=d"(((unsigned int*)&t)[1]));
}

inline double getNativeTime() {
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

unsigned long long g_initCpuClock;
unsigned long long g_reserveUpdateCpuClock;
double g_initNativeTime;
double g_secPerClock;
double g_doneTime;
inline void initTime() {
    g_initNativeTime = getNativeTime();
    getCpuClock(g_initCpuClock);
    g_secPerClock = 0.00000000025;
    g_reserveUpdateCpuClock = 10000000;
    g_doneTime = 0;
}

inline double getTime() {
    unsigned long long now;
    getCpuClock(now);
    now -= g_initCpuClock;
    if(g_reserveUpdateCpuClock < now) {
        double nowTime = getNativeTime() - g_initNativeTime;
        g_secPerClock = nowTime / now;
        g_reserveUpdateCpuClock = now + (unsigned long long)(0.05 * now / nowTime);
    }
    return g_doneTime = std::fmax(g_doneTime, g_secPerClock * now);
}

#line 5 "codevs_r/../.cpp/time/report.h"

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>
#include <csignal>

#line 77 "codevs_r/../.cpp/time/report.h"

unsigned long long g_main_iteration_start = 0;
unsigned long long g_main_iteration_end = 0;
unsigned long long g_main_iteration_count = 0;
inline void countMainIteration() {
	getCpuClock(g_main_iteration_end);
	if(1==++g_main_iteration_count) {
		g_main_iteration_start = g_main_iteration_end;
	}
}

inline void reportTime() {
	double t = getNativeTime();
	unsigned long long c;
	getCpuClock(c);
	t -= g_initNativeTime;
	c -= g_initCpuClock;
	if(g_main_iteration_count) {
		fprintf(stderr, "time_report: %fsec = %lldclock, %lldtimes ( %.0f clock/sec, %.3f times/sec )\n", t, c, g_main_iteration_count, c / t, g_main_iteration_count*c / (t * (g_main_iteration_end - g_main_iteration_start)));
	}
	else {
		fprintf(stderr, "time_report: %fsec = %lldclock ( %.0f clock/sec )\n", t, c, c / t);
	}



	fflush(stderr);
}

#line 1 "codevs_r/../.cpp/random/random.h"

#define RANDOM_RANDOM_H

#line 1 "codevs_r/../.cpp/random/../arch/assert.h"

#define ARCH_ASSERT_H

#line 1 "codevs_r/../.cpp/random/../arch/../io/dump.h"

#define IO_DUMP_H

#include <cstdio>
#include <cstdarg>
#include <string>
#include <vector>

void dump_hg3WeHwE8nS6oBeL_(bool val) {
	std::fprintf(stderr, "%s", val ? "true" : "false");
}
void dump_hg3WeHwE8nS6oBeL_(int val) {
	std::fprintf(stderr, "%d", val);
}
void dump_hg3WeHwE8nS6oBeL_(unsigned int val) {
	std::fprintf(stderr, "%u", val);
}
void dump_hg3WeHwE8nS6oBeL_(size_t val) {
	#ifdef __WIN32
	std::fprintf(stderr, "%d", (int)val);
	#else
	std::fprintf(stderr, "%zd", val);
	#endif
}
void dump_hg3WeHwE8nS6oBeL_(const void * val) {
	std::fprintf(stderr, "%p", val);
}
void dump_hg3WeHwE8nS6oBeL_(long long val) {
	#ifdef __WIN32
	std::fprintf(stderr, "%I64d", val);
	#else
	std::fprintf(stderr, "%lld", val);
	#endif
}
void dump_hg3WeHwE8nS6oBeL_(double val) {
	std::fprintf(stderr, "%g", val);
}
void dump_hg3WeHwE8nS6oBeL_(const char * val) {
	std::fprintf(stderr, "%s", val);
}
void dump_hg3WeHwE8nS6oBeL_(const std::string & val) {
	std::fprintf(stderr, "%s", val.c_str());
}
template<class T>void dump_hg3WeHwE8nS6oBeL_(const std::vector<T> & val) {
	std::fprintf(stderr, "%d {", (int)val.size());
	for(int i=0; i<(int)val.size(); ++i) {
		std::fprintf(stderr, " ");
		dump_hg3WeHwE8nS6oBeL_(val[i]);
	}
	std::fprintf(stderr, " }");
}
#define dump_hg3WeHwE8nS6oBeL(expr, val) std::fprintf(stderr, "%s = ", expr),dump_hg3WeHwE8nS6oBeL_(val)
#define dump0()
#define dump1(expr) dump_hg3WeHwE8nS6oBeL(#expr, expr)
#define dump2(expr1, expr2) dump1(expr1),std::fprintf(stderr, ", "),dump1(expr2)
#define dump3(expr1, expr2, expr3) dump2(expr1, expr2),std::fprintf(stderr, ", "),dump1(expr3)
#define dump4(expr1, expr2, expr3, expr4) dump3(expr1, expr2, expr3),std::fprintf(stderr, ", "),dump1(expr4)
#define dump5(expr1, expr2, expr3, expr4, expr5) dump4(expr1, expr2, expr3, expr4),std::fprintf(stderr, ", "),dump1(expr5)
#define dump6(expr1, expr2, expr3, expr4, expr5, expr6) dump5(expr1, expr2, expr3, expr4, expr5),std::fprintf(stderr, ", "),dump1(expr6)
#define dump7(expr1, expr2, expr3, expr4, expr5, expr6, expr7) dump6(expr1, expr2, expr3, expr4, expr5, expr6),std::fprintf(stderr, ", "),dump1(expr7)
#define dump8(expr1, expr2, expr3, expr4, expr5, expr6, expr7, expr8) dump7(expr1, expr2, expr3, expr4, expr5, expr6, expr7),std::fprintf(stderr, ", "),dump1(expr8)
#define dump9(expr1, expr2, expr3, expr4, expr5, expr6, expr7, expr8, expr9) dump8(expr1, expr2, expr3, expr4, expr5, expr6, expr7, expr8),std::fprintf(stderr, ", "),dump1(expr9)
#define dump10(expr1, expr2, expr3, expr4, expr5, expr6, expr7, expr8, expr9, expr10) dump9(expr1, expr2, expr3, expr4, expr5, expr6, expr7, expr8, expr9),std::fprintf(stderr, ", "),dump1(expr10)
#define GET_DUMP_MACRO_NAME(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define dump(...) GET_DUMP_MACRO_NAME(__VA_ARGS__, dump10, dump9, dump8, dump7, dump6, dump5, dump4, dump3, dump2, dump1, dump0)(__VA_ARGS__),fputs("\n", stderr),fflush(stderr)

#line 19 "codevs_r/../.cpp/random/../arch/assert.h"

#include <cassert>

#line 5 "codevs_r/../.cpp/random/random.h"

unsigned long long g_rand49_state = 0x8a5cd789635d2dffULL;
int mrand49() {
    g_rand49_state *= 6364136223846793005ULL;
    g_rand49_state += 1442695040888963407ULL;
    unsigned int ret = ((g_rand49_state>>18)^g_rand49_state) >> 27;
    unsigned int rot = (g_rand49_state>>59);
    return (ret>>rot) | (ret<<-rot);
}
long long mmrand49() {
    int v = mrand49();
    return ((long long)v << 32) | mrand49();
}
int lrand49() {
    return mrand49() & 0x7FFFFFFF;
}
int lrand49(int r) {
    assert(1<=r);
    return ((unsigned long long)(unsigned int)mrand49() * r)>>32;
}

double drand49() {
    return ((unsigned int)mrand49() + 0.5) * (1.0/4294967296.0);
}

void srand49(int seed) {
    g_rand49_state = seed + 1442695040888963407ULL;
}
void srand49() {
    int clk;
    __asm__ __volatile__ ("rdtsc" : "=a"(*(unsigned int*)&clk) : : "%rdx");
    srand49(clk);
}

#line 1 "codevs_r/../.cpp/container/slice.h"

#define CONTAINER_SLICE_H


#include <vector>

template<class T> class slice {
private:
	const T * pointer_;
	int size_;
public:
	template<class T2> inline slice(const T2 & o) : pointer_(o.data()), size_(o.size()) {
	}
	inline slice(const T * p, int s) : pointer_(p), size_(s) {
		assert(0<=s);
	}
	inline int size() const {
		return size_;
	}
	inline const T & operator [] (int pos) const {
		assert(0<=pos && pos<size_);
		return pointer_[pos];
	}
	inline void pop_front() {
		assert(1<=size_);
		++pointer_;
		--size_;
	}
	inline void pop_front(int size) {
		assert(size<=size_);
		pointer_ += size;
		size_ -= size;
	}
	inline void pop_back() {
		assert(1<=size_);
		--size_;
	}
	inline void pop_back(int size) {
		assert(size<=size_);
		size_ -= size;
	}
	inline const T * data() const {
		return pointer_;
	}
	inline const T * begin() const {
		return pointer_;
	}
	inline const T * end() const {
		return pointer_ + size_;
	}
	inline const T & front() const {
		assert(1<=size_);
		return pointer_[0];
	}
	inline const T & back() const {
		assert(1<=size_);
		return pointer_[size_-1];
	}
};

#line 1 "codevs_r/../.cpp/container/fast_vector.h"

#define CONTAINER_FAST_VECTOR_H

#include <utility>

#line 1 "codevs_r/../.cpp/container/../arch/likely.h"

#define ARCH_LIKELY_H

#define likely(expr) (__builtin_expect(!!(expr), 1))
#define unlikely(expr) (__builtin_expect(!!(expr), 0))

#line 1 "codevs_r/../.cpp/container/../container/fast_array.h"

#define CONTAINER_FAST_ARRAY_H

#include <cstddef>


template<typename T, int N> class fast_array {
private:
	char data_[sizeof(T)*N];
public:
	inline T* data() {
		return (T*)data_;
	}
	inline const T* data() const {
		return (const T*)data_;
	}
	inline std::size_t sizeofData() const {
		return sizeof(data_);
	}
	inline int size() const {
		return N;
	}
	inline T* begin() {
		return (T*)data_;
	}
	inline const T* begin() const {
		return (const T*)data_;
	}
	inline T* end() {
		return ((T*)data_) + N;
	}
	inline const T* end() const {
		return ((const T*)data_) + N;
	}
	inline T & operator[] (int i) {
		assert(0<=i && i<N);
		return ((T*)data_)[i];
	}
	inline const T & operator[] (int i) const {
		assert(0<=i && i<N);
		return ((const T*)data_)[i];
	}
};

#line 7 "codevs_r/../.cpp/container/fast_vector.h"

template<typename T, int N> class fast_vector {
private:
	int count;
	fast_array<T, N> data_;
public:
	inline fast_vector() : count(0) {
	}
	inline void clear() {
		count = 0;
	}
	inline bool empty() const {
		return count==0;
	}
	inline bool full() const {
		return count==N;
	}
	inline int full_size() const {
		return N;
	}
	template<class TyIt> inline void assign(TyIt st, TyIt et) {
		int cnt = 0;
		while(st!=et) {
			assert(cnt<N);
			data_[cnt] = *st;
			++st;
			++cnt;
		}
		count = cnt;
	}
	inline void push_back(const T & value) {
		assert(0<=count && count<N);
		data_[count] = value;
		++count;
	}
	template<class... TyArgs> inline void emplace_back(TyArgs&&... args) {
		assert(0<=count && count<N);
		::new(&data_[count])T(std::forward<TyArgs>(args)...);
		++count;
	}
	inline T & let_back() {
		assert(0<=count && count<N);
		return data_[count++];
	}
	inline void insert_slow(int idx, const T & value) {
		assert(0<=count && count<N);
		assert(0<=idx && idx<=count);
		int v = count;
		++count;
		while(idx<v) {
			data_[v] = data_[v-1];
			--v;
		}
		data_[idx] = value;
	}
	inline void pop_back() {
		assert(0<count);
		--count;
	}
	inline T & pop_back_with_value() {
		assert(0<count);
		--count;
		return data_[count];
	}
	inline void pop_swap_back(int i) {
		assert(0<=i && i<count);
		--count;
		if likely(i!=count) {
			data_[i] = data_[count];
		}
	}
	inline T pop_swap_back_with_value(int i) {
		assert(0<=i && i<count);
		--count;
		T ret = data_[i];
		if likely(i!=count) {
			data_[i] = data_[count];
		}
		return ret;
	}
	inline T & front() {
		assert(0<count);
		return *data_.data();
	}
	inline const T & front() const {
		assert(0<count);
		return *data_.data();
	}
	inline T & back() {
		assert(0<count);
		return data_[count-1];
	}
	inline const T & back() const {
		assert(0<count);
		return data_[count-1];
	}
	inline int & size() {
		return count;
	}
	inline int size() const {
		return count;
	}
	inline void resize(int n, const T & value) {
		assert(0<=n && n<=N);
		for(int i=count; i<n; ++i) {
			data_[i] = value;
		}
		count = n;
	}
	inline void resize(int n) {
		assert(0<=n && n<=N);
		count = n;
	}
	inline T * data() {
		return data_.data();
	}
	inline T * begin() {
		return data_.data();
	}
	inline T * end() {
		return data_.data()+count;
	}
	inline const T * data() const {
		return data_.data();
	}
	inline const T * begin() const {
		return data_.data();
	}
	inline const T * end() const {
		return data_.data()+count;
	}
	inline T & operator[] (int i) {
		assert(0<=i && i<count);
		return data_[i];
	}
	inline const T & operator[] (int i) const {
		assert(0<=i && i<count);
		return data_[i];
	}
	bool in_array_slow(const T & value) const {
		for(int i=0; i<count; ++i) {
			if unlikely(data_[i]==value) {
				return true;
			}
		}
		return false;
	}
};

#line 1 "codevs_r/../.cpp/container/fast_dpque.h"

#define CONTAINER_FAST_DPQUE_H

#line 37 "codevs_r/../.cpp/container/fast_dpque.h"

#include <utility>



template<typename T> struct fast_dpque_dummy_callback {
	inline fast_dpque_dummy_callback() {
	}
	inline void operator () (const T & o, int pos) {
	}
};

template<typename T, int N, typename F=fast_dpque_dummy_callback<T> > class fast_dpque {
private:
	int count;
	F callback;
	fast_array<T, N> data;
	inline void adjustDown(int now, const T & value) {
		while(true) {
			int nxt1 = now + now + 2;
			int nxt2 = nxt1 + 1;
			if(nxt2<count) {
				if(data[nxt1] < data[nxt2]) {
					if(value < data[nxt2]) {
						data[now] = data[nxt2];
						callback(data[now], now);
						now = nxt2;
					}
					else {
						data[now] = value;
						callback(data[now], now);
						return;
					}
				}
				else {
					if(value < data[nxt1]) {
						data[now] = data[nxt1];
						callback(data[now], now);
						now = nxt1;
					}
					else {
						data[now] = value;
						callback(data[now], now);
						return;
					}
				}
			}
			else if(nxt1<count) {
				if(value < data[nxt1]) {
					data[now] = data[nxt1];
					callback(data[now], now);
					now = nxt1;
				}
				else {
					data[now] = value;
					callback(data[now], now);
					return;
				}
			}
			else {
				break;
			}
		}
		int clz = __builtin_clz(now+2);
		int nxt = now+(1<<(30-clz));
		if(count<=nxt) {
			nxt = (nxt-2)>>1;
		}
		if(0<=nxt) {
			while(value < data[nxt]) {
				data[now] = data[nxt];
				callback(data[now], now);
				now = nxt;
				if(now<2) {
					break;
				}
				nxt = (now-2)>>1;
			}
		}
		data[now] = value;
		callback(data[now], now);
	}
	inline void adjustUp(int now, const T & value) {
		while(true) {
			int nxt1 = now + now + 2;
			int nxt2 = nxt1 + 1;
			if(nxt2<count) {
				if(data[nxt2] < data[nxt1]) {
					if(data[nxt2] < value) {
						data[now] = data[nxt2];
						callback(data[now], now);
						now = nxt2;
					}
					else {
						data[now] = value;
						callback(data[now], now);
						return;
					}
				}
				else {
					if(data[nxt1] < value) {
						data[now] = data[nxt1];
						callback(data[now], now);
						now = nxt1;
					}
					else {
						data[now] = value;
						callback(data[now], now);
						return;
					}
				}
			}
			else if(nxt1<count) {
				if(data[nxt1] < value) {
					data[now] = data[nxt1];
					callback(data[now], now);
					now = nxt1;
				}
				else {
					data[now] = value;
					callback(data[now], now);
					return;
				}
			}
			else {
				break;
			}
		}
		int clz = __builtin_clz(now+2);
		int nxt = now+now-(1<<(31-clz))+2;
		if(count<=nxt) {
			nxt = (nxt-2)>>1;
		}
		if(0<=nxt) {
			while(data[nxt] < value) {
				data[now] = data[nxt];
				callback(data[now], now);
				now = nxt;
				if(now<2) {
					break;
				}
				nxt = (now-2)>>1;
			}
		}
		data[now] = value;
		callback(data[now], now);
	}
public:
	inline fast_dpque() {
		count = 0;
	}
	inline void clear() {
		assert(0<=count && count<=N);
		for(int i=0; i<count; ++i) {
			callback(data[i], -1);
		}
		count = 0;
	}
	inline ~fast_dpque() {
		clear();
	}
	inline void clearWithoutCallback() {
		assert(0<=count && count<=N);
		count = 0;
	}
	inline bool empty() const {
		assert(0<=count && count<=N);
		return count==0;
	}
	inline bool full() const {
		assert(0<=count && count<=N);
		return count==N;
	}
	inline void push(const T & value) {
		assert(0<=count && count<=N);
		assert(count<N);
		++count;
		if(3<=count) {
			int now = count-1;
			int clz = __builtin_clz(now+2);
			int nxt = (now-2)>>1;
			if(now<((3<<(30-clz))-2)) {
				if(data[nxt] < value) {
					do {
						data[now] = data[nxt];
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					} while(data[nxt] < value);
				}
				else {
					int nxt = (now+(1<<(30-clz))-2)>>1;
					while(value < data[nxt]) {
						data[now] = data[nxt];
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					}
				}
			}
			else {
				if(value < data[nxt]) {
					do {
						data[now] = data[nxt];
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					} while(value < data[nxt]);
				}
				else {
					int nxt = now-(1<<(30-clz));
					while(data[nxt] < value) {
						data[now] = data[nxt];
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					}
				}
			}
			data[now] = value;
			callback(data[now], now);
		}
		else if(count==2) {
			if(data[0] < value) {
				data[1] = data[0];
				callback(data[1], 1);
				data[0] = value;
				callback(data[0], 0);
			}
			else {
				data[1] = value;
				callback(data[1], 1);
			}
		}
		else {
			data[0] = value;
			callback(data[0], 0);
		}
	}
	inline const T & large() const {
		assert(0<=count && count<=N);
		assert(0<count);
		return data[0];
	}
	inline const T & small() const {
		assert(0<=count && count<=N);
		assert(0<count);
		return count==1 ? data[0] : data[1];
	}
	inline void pop_large() {
		assert(0<=count && count<=N);
		assert(0<count);
		--count;
		callback(data[0], -1);
		if(1<=count) {
			adjustDown(0, data[count]);
		}
	}
	inline void pop_small() {
		assert(0<=count && count<=N);
		assert(0<count);
		--count;
		if(count) {
			callback(data[1], -1);
			if(2<=count) {
				adjustUp(1, data[count]);
			}
		}
		else {
			callback(data[0], -1);
		}
	}
	inline void swap_large(const T & value) {
		assert(0<=count && count<=N);
		assert(0<count);
		callback(data[0], -1);
		adjustDown(0, value);
	}
	inline void swap_small(const T & value) {
		assert(0<=count && count<=N);
		assert(0<count);
		if(2<=count) {
			callback(data[1], -1);
			adjustUp(1, value);
		}
		else {
			callback(data[0], -1);
			data[0] = value;
			callback(data[0], 0);
		}
	}
	inline void push_large(const T & value) {
		assert(this);
		assert(0<=count && count<=N);
		if(!full()) {
			push(value);
		}
		else if(small()<value) {
			swap_small(value);
		}
	}
	inline void push_small(const T & value) {
		assert(0<=count && count<=N);
		if(!full()) {
			push(value);
		}
		else if(value<large()) {
			swap_large(value);
		}
	}
	template<class... TyArgs> inline void emplace(TyArgs&&... args) {
		assert(0<=count && count<=N);
		T value;
		::new(&value)T(std::forward<TyArgs>(args)...);
		push(value);
	}
	template<class... TyArgs> inline void emplace_large(TyArgs&&... args) {
		assert(0<=count && count<=N);
		T value;
		::new(&value)T(std::forward<TyArgs>(args)...);
		push_large(value);
	}
	template<class... TyArgs> inline void emplace_small(TyArgs&&... args) {
		assert(0<=count && count<=N);
		T value;
		::new(&value)T(std::forward<TyArgs>(args)...);
		push_small(value);
	}
	inline void swap(int now, const T & value) {
		assert(0<=count && count<=N);
		assert(0<=now && now<count);
		callback(data[now], -1);
		int clz0 = __builtin_clz(now+2);
		if(now<((3<<(30-clz0))-2)) {
			if(2<=now) {
				int nxt = (now-2)>>1;
				if(data[nxt] < value) {
					do {
						data[now] = data[nxt];
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					} while(data[nxt] < value);
					data[now] = value;
					callback(data[now], now);
					return;
				}
			}
			adjustDown(now, value);
		}
		else {
			if(2<=now) {
				int nxt = (now-2)>>1;
				if(value < data[nxt]) {
					do {
						data[now] = data[nxt];
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					} while(value < data[nxt]);
					data[now] = value;
					callback(data[now], now);
					return;
				}
			}
			adjustUp(now, value);
		}
	}
	inline void remove(int i) {
		assert(0<=count && count<=N);
		assert(0<=i && i<count);
		--count;
		if(i==count) {
			callback(data[i], -1);
		}
		else {
			swap(i, data[count]);
		}
	}
	inline const T & operator [] (int i) const {
		assert(0<=count && count<=N);
		assert(0<=i && i<count);
		return data[i];
	}
	inline const T & get(int i) const {
		assert(0<=count && count<=N);
		assert(0<=i && i<count);
		return data[i];
	}
	inline int size() const {
		assert(0<=count && count<=N);
		return count;
	}
};

#line 1 "codevs_r/../.cpp/container/dpque.h"

#define CONTAINER_DPQUE_H

#line 7 "codevs_r/../.cpp/container/dpque.h"

#include <utility>



template<typename T> struct dpque_dummy_callback {
	inline dpque_dummy_callback() {
	}
	inline void operator () (const T & o, int pos) {
	}
};

template<typename T, typename F=dpque_dummy_callback<T> > class dpque {
private:
	F callback;
	std::vector<T> data;
	inline void adjustDown(int now, const T & value) {
		int count = size();
		while(true) {
			int nxt1 = now + now + 2;
			int nxt2 = nxt1 + 1;
			if(nxt2<count) {
				if(data[nxt1] < data[nxt2]) {
					if(value < data[nxt2]) {
						data[now] = std::move(data[nxt2]);
						callback(data[now], now);
						now = nxt2;
					}
					else {
						data[now] = std::move(value);
						callback(data[now], now);
						return;
					}
				}
				else {
					if(value < data[nxt1]) {
						data[now] = std::move(data[nxt1]);
						callback(data[now], now);
						now = nxt1;
					}
					else {
						data[now] = std::move(value);
						callback(data[now], now);
						return;
					}
				}
			}
			else if(nxt1<count) {
				if(value < data[nxt1]) {
					data[now] = std::move(data[nxt1]);
					callback(data[now], now);
					now = nxt1;
				}
				else {
					data[now] = std::move(value);
					callback(data[now], now);
					return;
				}
			}
			else {
				break;
			}
		}
		int clz = __builtin_clz(now+2);
		int nxt = now+(1<<(30-clz));
		if(count<=nxt) {
			nxt = (nxt-2)>>1;
		}
		if(0<=nxt) {
			while(value < data[nxt]) {
				data[now] = std::move(data[nxt]);
				callback(data[now], now);
				now = nxt;
				if(now<2) {
					break;
				}
				nxt = (now-2)>>1;
			}
		}
		data[now] = std::move(value);
		callback(data[now], now);
	}
	inline void adjustUp(int now, const T & value) {
		int count = size();
		while(true) {
			int nxt1 = now + now + 2;
			int nxt2 = nxt1 + 1;
			if(nxt2<count) {
				if(data[nxt2] < data[nxt1]) {
					if(data[nxt2] < value) {
						data[now] = std::move(data[nxt2]);
						callback(data[now], now);
						now = nxt2;
					}
					else {
						data[now] = std::move(value);
						callback(data[now], now);
						return;
					}
				}
				else {
					if(data[nxt1] < value) {
						data[now] = std::move(data[nxt1]);
						callback(data[now], now);
						now = nxt1;
					}
					else {
						data[now] = std::move(value);
						callback(data[now], now);
						return;
					}
				}
			}
			else if(nxt1<count) {
				if(data[nxt1] < value) {
					data[now] = std::move(data[nxt1]);
					callback(data[now], now);
					now = nxt1;
				}
				else {
					data[now] = std::move(value);
					callback(data[now], now);
					return;
				}
			}
			else {
				break;
			}
		}
		int clz = __builtin_clz(now+2);
		int nxt = now+now-(1<<(31-clz))+2;
		if(count<=nxt) {
			nxt = (nxt-2)>>1;
		}
		if(0<=nxt) {
			while(data[nxt] < value) {
				data[now] = std::move(data[nxt]);
				callback(data[now], now);
				now = nxt;
				if(now<2) {
					break;
				}
				nxt = (now-2)>>1;
			}
		}
		data[now] = std::move(value);
		callback(data[now], now);
	}
public:
	inline dpque() {
	}
	inline void clear() {
		for(T & o : data) {
			callback(o, -1);
		}
		data.clear();
	}
	inline ~dpque() {
		clear();
	}
	inline void clearWithoutCallback() {
		data.clear();
	}
	inline bool empty() const {
		return data.empty();
	}
	inline void push(const T & value) {
		int now = size();
		if(2<=now) {
			int clz = __builtin_clz(now+2);
			int nxt = (now-2)>>1;
			data.emplace_back();
			if(now<((3<<(30-clz))-2)) {
				if(data[nxt] < value) {
					do {
						data[now] = std::move(data[nxt]);
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					} while(data[nxt] < value);
				}
				else {
					int nxt = (now+(1<<(30-clz))-2)>>1;
					while(value < data[nxt]) {
						data[now] = std::move(data[nxt]);
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					}
				}
			}
			else {
				if(value < data[nxt]) {
					do {
						data[now] = std::move(data[nxt]);
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					} while(value < data[nxt]);
				}
				else {
					int nxt = now-(1<<(30-clz));
					while(data[nxt] < value) {
						data[now] = std::move(data[nxt]);
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					}
				}
			}
			data[now] = std::move(value);
			callback(data[now], now);
		}
		else if(now==1) {
			if(data[0] < value) {
				data.emplace_back(data[0]);
				callback(data[1], 1);
				data[0] = std::move(value);
				callback(data[0], 0);
			}
			else {
				data.emplace_back(std::move(value));
				callback(data[1], 1);
			}
		}
		else {
			assert(empty());
			data.push_back(std::move(value));
			callback(data[0], 0);
		}
	}
	inline const T & large() const {
		assert(!empty());
		return data[0];
	}
	inline const T & small() const {
		assert(!empty());
		return size()==1 ? data[0] : data[1];
	}
	inline void pop_large() {
		assert(!empty());
		if(size()==1) {
			callback(data[0], -1);
			data.pop_back();
		}
		else {
			T o = std::move(data.back());
			data.pop_back();
			callback(data[0], -1);
			adjustDown(0, o);
		}
	}
	inline void pop_small() {
		assert(!empty());
		if(size()==1) {
			callback(data[0], -1);
			data.pop_back();
		}
		else {
			callback(data[1], -1);
			if(size()==2) {
				data.pop_back();
			}
			else {
				T o = std::move(data.back());
				data.pop_back();
				adjustUp(1, o);
			}
		}
	}
	inline void swap_large(const T & value) {
		assert(!empty());
		callback(data[0], -1);
		adjustDown(0, value);
	}
	inline void swap_small(const T & value) {
		assert(!empty());
		if(2<=size()) {
			callback(data[1], -1);
			adjustUp(1, value);
		}
		else {
			callback(data[0], -1);
			data[0] = std::move(value);
			callback(data[0], 0);
		}
	}
	inline void push_large(const T & value, int size_) {
		if(size()<size_) {
			push(value);
		}
		else if(small()<value) {
			swap_small(value);
		}
	}
	inline void push_small(const T & value, int size_) {
		if(size()<size_) {
			push(value);
		}
		else if(value<large()) {
			swap_large(value);
		}
	}
	template<class... TyArgs> inline void emplace(TyArgs&&... args) {
		T value;
		::new(&value)T(std::forward<TyArgs>(args)...);
		push(value);
	}
	template<class... TyArgs> inline void emplace_large(TyArgs&&... args) {
		T value;
		::new(&value)T(std::forward<TyArgs>(args)...);
		push_large(value);
	}
	template<class... TyArgs> inline void emplace_small(TyArgs&&... args) {
		T value;
		::new(&value)T(std::forward<TyArgs>(args)...);
		push_small(value);
	}
	inline void swap(int now, const T & value) {
		assert(0<=now && now<size());
		callback(data[now], -1);
		int clz0 = __builtin_clz(now+2);
		if(now<((3<<(30-clz0))-2)) {
			if(2<=now) {
				int nxt = (now-2)>>1;
				if(data[nxt] < value) {
					do {
						data[now] = std::move(data[nxt]);
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					} while(data[nxt] < value);
					data[now] = std::move(value);
					callback(data[now], now);
					return;
				}
			}
			adjustDown(now, value);
		}
		else {
			if(2<=now) {
				int nxt = (now-2)>>1;
				if(value < data[nxt]) {
					do {
						data[now] = std::move(data[nxt]);
						callback(data[now], now);
						now = nxt;
						if(now<2) {
							break;
						}
						nxt = (now-2)>>1;
					} while(value < data[nxt]);
					data[now] = std::move(value);
					callback(data[now], now);
					return;
				}
			}
			adjustUp(now, value);
		}
	}
	inline void remove(int i) {
		assert(0<=i && i<size());
		if(i+1==size()) {
			callback(data[i], -1);
			data.pop_back();
		}
		else {
			T o = std::move(data.back());
			data.pop_back();
			swap(i, o);
		}
	}
	inline const T & operator [] (int i) const {
		assert(0<=i && i<size());
		return data[i];
	}
	inline const T & get(int i) const {
		assert(0<=i && i<size());
		return data[i];
	}
	inline int size() const {
		return data.size();
	}
};

#line 1 "codevs_r/../.cpp/container/pooled_list.h"

#define CONTAINER_POOLED_LIST_H

#include <cstdlib>
#include <cstring>

template<typename T> class pooled_list {
	void * mem;
	T * data;
	int size;
	int char_size;
	int stack;
	int pos;
public:
	inline pooled_list() {
		size = 1024;
		char_size = size * sizeof(T);
		mem = std::malloc(char_size+15);
		data = (T*)(void*)(((size_t)mem + 15) & ~15);
		stack = -1;
		pos = 0;
	}
	inline void clear() {
		stack = -1;
		pos = 0;
	}
	inline T & operator [] (int i) {
		return data[i];
	}
	inline int pop() {
		if(0<=stack) {
			int ret = stack;
			stack = data[ret].next;
			return ret;
		}
		if(size<=pos) {
			void * new_mem = std::malloc(char_size+char_size+15);
			T * new_data = (T*)(void*)(((size_t)new_mem + 15) & ~15);
			std::memcpy(new_data, data, char_size);
			std::free(mem);
			mem = new_mem;
			data = new_data;
			size += size;
			char_size += char_size;
		}
		assert(pos<size);
		return pos++;
	}
	inline void push(int i) {
		data[i].next = stack;
		stack = i;
	}
};

#line 1 "codevs_r/../.cpp/container/pooled_vector.h"

#define CONTAINER_POOLED_VECTOR_H

#include <cstdlib>
#include <cstring>


template<typename T> class pooled_vector {
	std::vector<T> data;
	dpque<int> pool;
public:
	inline pooled_vector() {
	}
	inline void clear() {
		data.clear();
		pool.clear();
	}
	inline T & operator [] (int i) {
		return data[i];
	}
	inline int pop() {
		if(!pool.empty()) {
			int ret = pool.small();
			pool.pop_small();
			return ret;
		}
		int ret = data.size();
		data.emplace_back();
		return ret;
	}
	inline void push(int i) {
		pool.push(i);
	}
};

#line 1 "codevs_r/../.cpp/search/pool.h"

#define SEARCH_POOL_H

#include <cstdlib>

#line 8 "codevs_r/../.cpp/search/pool.h"

template<typename Ty, int blockSize = 524288, int align = sizeof(void*)> class pool {
	void * top;
	std::size_t mem;
	std::size_t it;
	std::size_t et;
	std::size_t unitSize;
	int unitSizeNum;
public:
	void init(std::size_t size=sizeof(Ty)) {
		while(mem) {
			std::size_t m = *(std::size_t*)mem;
			std::free((void*)mem);
			mem = m;
		}
		top = NULL;
		it = 0;
		et = 0;

		unitSize = ((size+(align-1)) & ~(align-1));
		int unitSizeInt = unitSize;
		int num = (blockSize-(sizeof(void*)+(align-1))) / unitSize;
		unitSizeNum = unitSize * num;
	}
	pool() {
		mem = 0;
		init();
	}
	inline void push(Ty * p) {
		*(void**)p = top;
		top = (void*)p;
	}
	inline Ty * pop() {
		if(top!=NULL) {
			Ty * result = (Ty*)top;
			top = *(void**)top;
			return result;
		}
		if(it==et) {
			it = (std::size_t)std::malloc(unitSizeNum + (sizeof(void*)+(align-1)));
			*(std::size_t*)it = mem;
			mem = it;
			it = (it+(sizeof(void*)+(align-1))) & ~(align-1);
			et = it + unitSizeNum;
		}
		Ty * result = (Ty*)it;
		it += unitSize;
		return result;
	}
};

#line 1 "codevs_r/../.cpp/search/zobrist.h"

#define SEARCH_ZOBRIST_H

#line 6 "codevs_r/../.cpp/search/zobrist.h"

template<typename T, int N> class zobrist {
private:
	T hash[N];
public:
	zobrist() {
		if(8<=sizeof(T)) {
			for(int i=0; i<N; ++i) {
				hash[i] = (T)mmrand49();
			}
		}
		else {
			for(int i=0; i<N; ++i) {
				hash[i] = (T)mrand49();
			}
		}
	}
	inline const T & operator[] (int i) const {
		assert(0<=i && i<N);
		return hash[i];
	}
};

#line 1 "codevs_r/../.cpp/search/fast_weak_set64.h"

#define SEARCH_FAST_WEAK_SET64_H

#include <cstring>


template<int N=16777216>class fast_weak_set64 {
private:
	const unsigned int mask = N - 1;
	fast_array<long long, N> memo;
public:
	inline void clear() {
		memset(memo.data(), 0, sizeof(memo));
	}
	inline fast_weak_set64() {
		assert((N&(N-1))==0);
	}
	inline bool test(long long hash) const {
		unsigned int key = (unsigned int)hash & mask;
		if(hash==0) {
			hash = 1;
		}
		return memo[key]==hash;
	}
	inline void set(long long hash) {
		unsigned int key = (unsigned int)hash & mask;
		if(hash==0) {
			hash = 1;
		}
		memo[key] = hash;
	}
	inline void reset(long long hash) {
		unsigned int key = (unsigned int)hash & mask;
		if(hash==0) {
			hash = 1;
		}
		memo[key] = 0;
	}
	inline bool testWithSet(long long hash) {
		unsigned int key = (unsigned int)hash & mask;
		if(hash==0) {
			hash = 1;
		}
		if(memo[key]==hash) {
			return true;
		}
		memo[key] = hash;
		return false;
	}
};

#line 18 "codevs_r/colun11.cpp"

#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


#define BEAM_SIZE 50000
#define CHOKUDAI_WIDTH 1
#define CHOKUDAI_ITERATION 1
#define PARAM_BEAM_FLUCTUATION 0.5
#define PARAM_BEAM_FAMILY_BONUS 1.0
#define PARAM_BLACKET_BONUS2 0.5
#define PARAM_BLACKET_BONUS3 0.5
#define PARAM_KATA_BONUS2 0.1
#define PARAM_KATA_BONUS3 0.1
#define PARAM_KATA_BONUS4 0.1
#define PARAM_KATA_BONUS5 0.1
#define MAX_CHILDREN 15
double PARAM_CHAIN_EVAL = 2.0;
double PARAM_KEIMA_EVAL = 0.2;
int g_appear_turn = 14;

#line 53 "codevs_r/colun11.cpp"

namespace search {

#line 1 "codevs_r/../.cpp/search/exbeam.h"

#define SEARCH_EXBEAM_H

#line 45 "codevs_r/../.cpp/search/exbeam.h"

struct exbeam_candidate {
	int next;
	int act;
	long long hash;
	double evalDiffAlone;
	double evalDiffStore;
};
pooled_list<exbeam_candidate> g_exbeam_candidates;

struct exbeam_node;
struct exbeam_node_callback;

typedef fast_dpque<std::pair<double, exbeam_node*>, BEAM_SIZE, exbeam_node_callback> exbeam_ranking;

struct exbeam_node;

::pool<exbeam_node> exbeam_node_pool;
fast_weak_set64<> hash_set;
pooled_vector<std::vector<int> > reserved_dna_vec;

struct exbeam_node {
private:
	exbeam_ranking * ranking;
public:
	exbeam_node * parent;
	int ref;
private:
	int depth_;
public:
	int generation;
	int ranking_pos;
	int act;
	int next;
	int children;
	long long hash;
	double evalAlone;
	double evalStore;
#ifdef BEAM_NODE_MEMBER
	BEAM_NODE_MEMBER
#endif
	static inline exbeam_node * create() {
		exbeam_node * ret = exbeam_node_pool.pop();
		ret->ranking = NULL;
		ret->parent = NULL;
		ret->ref = 1;
		ret->depth_ = 0;
		ret->generation = 0;
		ret->ranking_pos = -1;
		ret->act = -1;
		ret->next = -2;
		ret->children = 0;
		ret->hash = 0;
		ret->evalAlone = 0;
		ret->evalStore = 0;
		return ret;
	}
	inline exbeam_node * createWithoutAddRef(int act_, long long hash_, double evalDiffStore_) {
		exbeam_node * ret = exbeam_node_pool.pop();
		memcpy(ret, this, sizeof(exbeam_node));
		ret->ranking = NULL;
		ret->parent = this;
		ret->ref = 1;
		++ret->depth_;
		if(act_<-0x40000000) {
			int l = act_+0x80000000;
			assert(1<=reserved_dna_vec[l].size());
			ret->generation += reserved_dna_vec[l].size();
			if(reserved_dna_vec[l].size()==1) {
				act_ = reserved_dna_vec[l][0];
				reserved_dna_vec.push(l);
			}
		}
		else {
			++ret->generation;
		}
		ret->ranking_pos = -1;
		ret->act = act_;
		ret->next = -2;
		ret->children = 0;
		ret->hash = hash_;
		if(ret->hash) {


			hash_set.set(ret->hash);
		}
		ret->evalStore += evalDiffStore_;
		return ret;
	}
	inline exbeam_node * createChildWithoutAddRef() {
		assert(0<=next);
		exbeam_candidate & reserved = g_exbeam_candidates[next];
		exbeam_node * ret = createWithoutAddRef(reserved.act, reserved.hash, reserved.evalDiffStore);
		skip();
		return ret;
	}
	inline void skip();
	inline void setRanking(exbeam_ranking * ranking);
	inline void setEval(double newEval);
	inline void updateEval(double newEval) {
		if(evalAlone<newEval) {
			setEval(newEval);
		}
	}
	inline double getNextEval() const {
		assert(0<=next);
		return evalAlone + evalStore + g_exbeam_candidates[next].evalDiffAlone;
	}
	inline long long getNextHash() const {
		assert(0<=next);
		return g_exbeam_candidates[next].hash;
	}
	inline void release() {
		assert(1<=ref);
		if(ref!=1) {
			--ref;
		}
		else {
			if(parent) {
				parent->release();
			}
			int n = next;
			while(0<=n) {
				exbeam_candidate & reserved = g_exbeam_candidates[n];
				int a = reserved.act;
				if(a<-0x40000000) {
					int l = a+0x80000000;
					reserved_dna_vec[l].clear();
					reserved_dna_vec[l].shrink_to_fit();
					reserved_dna_vec.push(l);
				}
				int n2 = reserved.next;
				g_exbeam_candidates.push(n);
				n = n2;
			}
			exbeam_node_pool.push(this);
		}
	}
	inline int depth() const {
		return depth_;
	}
};

struct exbeam_node_callback {
	inline void operator () (const std::pair<double, exbeam_node*> & o, int pos) {
		if(o.second->ranking_pos==-1) {
			assert(pos!=-1);
			++o.second->ref;
		}
		o.second->ranking_pos = pos;
		if(pos==-1) {
			o.second->release();
		}
	}
};

std::vector<exbeam_ranking*> rankings;
std::vector<std::tuple<double, double, long long, int> > reserve_list;
std::vector<int> oracle_stack;
std::vector<int> suggest_stack;
std::vector<exbeam_node*> depthwise_stack;
exbeam_node * current;
int skip_reserve_count;
int last_generation;
bool make_child_flag;

int chokudai_remain;
int generation_loop_count;
double g_timelimit = 0;


constexpr int OPE_RETURN = -1;
constexpr int OPE_RESERVE = -2;
constexpr int OPE_RESUME = -3;
constexpr int OPE_CONFIRM = -4;

inline void exbeam_node::skip() {
	while(true) {
		assert(0<=next);
		{
			int before = next;
			exbeam_candidate & reserved = g_exbeam_candidates[before];
			int a = reserved.act;
			if(a<-0x40000000) {
				int l = a+0x80000000;
				reserved_dna_vec[l].clear();
				reserved_dna_vec[l].shrink_to_fit();
				reserved_dna_vec.push(l);
			}
			next = reserved.next;
			g_exbeam_candidates.push(before);
		}
		if(next<0) {
			if(0<=ranking_pos && ranking) {
				ranking->remove(ranking_pos);
			}
			return;
		}
		if(hash_set.test(getNextHash())) {
			continue;
		}
		if(ranking) {
			std::pair<double, exbeam_node*> v(getNextEval(), this);
			if(ranking_pos<0) {
				assert(ranking_pos==-1);
				ranking->push_large(v);
			}
			else {
				ranking->swap(ranking_pos, v);
			}
		}
		return;
	}
}
inline void exbeam_node::setRanking(exbeam_ranking * ranking) {
	assert(ranking_pos==-1);
	this->ranking = ranking;
	std::pair<double, exbeam_node*> v(getNextEval(), this);
	ranking->push_large(v);
}
inline void exbeam_node::setEval(double newEval) {
	evalAlone = newEval;
	if(0<=next) {
		std::pair<double, exbeam_node*> v(getNextEval(), this);
		if(ranking_pos==-1) {
			ranking->push_large(v);
		}
		else {
			ranking->swap(ranking_pos, v);
		}
	}
}

inline void init() {
	for(exbeam_ranking * ranking : rankings) {
		if(ranking) {
			ranking->clearWithoutCallback();
			delete ranking;
		}
	}
	rankings.clear();
	depthwise_stack.clear();
	exbeam_node_pool.init();
	g_exbeam_candidates.clear();
	reserve_list.clear();
	skip_reserve_count = 0;
	oracle_stack.clear();
	suggest_stack.clear();
	current = exbeam_node::create();
	last_generation = 0;
	hash_set.clear();
	make_child_flag = true;

	chokudai_remain = CHOKUDAI_WIDTH;
	generation_loop_count = 0;

}
inline exbeam_node * getCurrent() {
	return current;
}
inline void reserve(int act, double evalDiff=0, long long hashDiff=0) {
	assert(oracle_stack.empty());
	long long hash = hashDiff ^ current->hash;
	if(hash_set.test(hash)) {
		++skip_reserve_count;
	}
	else {
		reserve_list.emplace_back(evalDiff + PARAM_BEAM_FLUCTUATION * drand49(), evalDiff, hash, act);
	}
	++current->children;
}
inline void reserveDNA(const std::vector<int> & dna, double evalDiff=0, long long hashDiff=0) {
	assert(oracle_stack.empty());
	long long hash = hashDiff ^ current->hash;
	if(hash_set.test(hash)) {
		++skip_reserve_count;
	}
	else {
		int i = reserved_dna_vec.pop();
		reserved_dna_vec[i] = std::move(dna);
		reserve_list.emplace_back(evalDiff + PARAM_BEAM_FLUCTUATION * drand49(), evalDiff, hash, i-0x80000000);
	}
	++current->children;
}
inline void endReserve_() {
	assert(current);
	assert(oracle_stack.empty());
	if(!reserve_list.empty()) {
		std::sort(reserve_list.rbegin(), reserve_list.rend());
		assert(-256<=current->next && current->next<0);
		int before = current->next;
		if(before==-3 && MAX_CHILDREN<=current->children) {
			before = -1;
		}
		int i = current->children - skip_reserve_count;
		if(MAX_CHILDREN<i) {
			int new_size = max(0, (int)(reserve_list.size()+MAX_CHILDREN-i));
			for(int j=new_size; j<reserve_list.size(); ++j) {
				int k = std::get<3>(reserve_list[j]);
				if(k<-0x40000000) {
					int l = k+0x80000000;
					reserved_dna_vec[l].clear();
					reserved_dna_vec[l].shrink_to_fit();
					reserved_dna_vec.push(l);
				}
			}
			if(new_size<=0) {
				goto LABEL_B;
			}
			reserve_list.resize(new_size);
			i = MAX_CHILDREN;
		}
		while(!reserve_list.empty()) {
			std::tuple<double, double, long long, int> & r = reserve_list.back();
			int now = g_exbeam_candidates.pop();
			exbeam_candidate & candidate = g_exbeam_candidates[now];
			candidate.next = before;
			candidate.act = std::get<3>(r);
			candidate.hash = std::get<2>(r);
			candidate.evalDiffStore = std::get<1>(r);
			candidate.evalDiffAlone = std::get<0>(r) + PARAM_BEAM_FAMILY_BONUS/i;
			before = now;
			--i;
			reserve_list.pop_back();
		}
		LABEL_B:;
		reserve_list.clear();
		current->next = before;
		if(0<=current->next) {
			if(0<=current->generation) {
				if(rankings.size()<=current->generation) {
					rankings.resize(current->generation+1);
				}
				if(rankings[current->generation]==NULL) {
					rankings[current->generation] = new exbeam_ranking();
				}
				current->setRanking(rankings[current->generation]);
			}
			else {
				++current->ref;
				depthwise_stack.emplace_back(current);
			}
		}
	}
	skip_reserve_count = 0;
}
inline void moveNode_(exbeam_node * from, exbeam_node * to) {
	int ret_count = 0;
	while(to!=from) {
		if(from->depth()<to->depth()) {
			int act = to->act;
			if(act<-0x40000000) {
				for(int a : reserved_dna_vec[act+0x80000000]) {
					oracle_stack.emplace_back(a);
				}
			}
			else {
				oracle_stack.emplace_back(act);
			}
			to = to->parent;
		}
		else {
			int act = from->act;
			if(act<-0x40000000) {
				ret_count += reserved_dna_vec[act+0x80000000].size();
			}
			else {
				++ret_count;
			}
			from = from->parent;
		}
	}
	for(int i=0; i<ret_count; ++i) {
		oracle_stack.emplace_back(OPE_RETURN);
	}
}
inline void suspendReserve() {
	current->next = -3;
}
std::vector<int> dna_;
const std::vector<int> & getDNA() {
	return dna_;
}
int suggest_vec_id;
long long suggest_hash;
double suggest_eval_diff_store;
double suggest_eval_alone;
inline void breakDNA() {
	suggest_stack.clear();
	current = current->createWithoutAddRef(suggest_vec_id-0x80000000, suggest_hash, suggest_eval_diff_store);
	current->evalAlone = suggest_eval_alone;
}
inline int oracle() {
	if(!reserve_list.empty()) {
		endReserve_();
	}
	assert(reserve_list.empty());



	LABEL_C:;
	if(!oracle_stack.empty()) {
		LABEL_E:;
		int ret = oracle_stack.back();
		oracle_stack.pop_back();
		if(ret<0) {
			assert(ret==OPE_RETURN || ret==OPE_CONFIRM);
			if(ret==OPE_RETURN) {
				assert(!dna_.empty());
				dna_.pop_back();
			}
		}
		else {
			dna_.emplace_back(ret);
		}
		return ret;
	}
	if(!suggest_stack.empty()) {
		int ret = suggest_stack.back();
		suggest_stack.pop_back();
		reserved_dna_vec[suggest_vec_id].emplace_back(ret);
		assert(0<=ret);
		dna_.emplace_back(ret);
		if(suggest_stack.empty()) {
			breakDNA();
		}
		else {
			oracle_stack.emplace_back(OPE_CONFIRM);
		}
		return ret;
	}
	if(current==NULL) {
		dna_.clear();
		return OPE_RETURN;
	}
	if(current->next<0 || !make_child_flag) {
		if(current->next==-2) {
			current->next = -1;
			make_child_flag = false;
			return OPE_RESERVE;
		}
		if(current->next==-3) {
			current->next = -1;
			return OPE_RESUME;
		}

		LABEL_D:;
		exbeam_node * dst;
		while(!depthwise_stack.empty()) {
			dst = depthwise_stack.back();
			if(dst->next<0) {
				if(dst->next==-3) {
					depthwise_stack.pop_back();
					goto LABEL_A;
				}
				assert(dst->next==-1);
				dst->release();
				depthwise_stack.pop_back();
				continue;
			}
			if(hash_set.test(dst->getNextHash())) {
				dst->skip();
				if(dst->next==-1) {
					dst->release();
					depthwise_stack.pop_back();
					continue;
				}
			}
			++dst->ref;
			goto LABEL_A;
		}
		while(true) {
			if(rankings.size()<=last_generation) {

				if(generation_loop_count<BEAM_SIZE*CHOKUDAI_ITERATION && (!g_timelimit || getTime()<g_timelimit)) {
					generation_loop_count += CHOKUDAI_WIDTH;
					last_generation = 0;
					continue;
				}

				current->release();
				current = NULL;
				dna_.clear();
				return OPE_RETURN;
			}
			if(rankings[last_generation]) {
				while(!rankings[last_generation]->empty()) {
					dst = rankings[last_generation]->large().second;
					++dst->ref;
					assert(0<=dst->next);
					if(hash_set.test(dst->getNextHash())) {
						dst->skip();
						dst->release();
					}
					else {

						if(--chokudai_remain<=0) {
							chokudai_remain = CHOKUDAI_WIDTH;
							++last_generation;
						}

						goto LABEL_A;
					}
				}



			}

			chokudai_remain = CHOKUDAI_WIDTH;

			++last_generation;
		}
		LABEL_A:;
		assert(oracle_stack.empty());
		exbeam_candidate & reserved = g_exbeam_candidates[dst->next];
		int a = reserved.act;
		if(a<-0x40000000) {
			int l = a + 0x80000000;
			vector<int> & dna = reserved_dna_vec[l];
			reverse(dna.begin(), dna.end());
			int best_size = 0;
			exbeam_node * best_node = NULL;
			int bestSc = -1;
			vector<int> v;
			for(int i=0; i<2; ++i) {
				exbeam_node * node = i ? dst : current;
				while(node->parent) {
					v.emplace_back(node->act);
					node = node->parent;
				}
				int sc;
				int esc = min(dna.size(), v.size());
				for(sc=0; sc<esc && dna[dna.size()-1-sc]==v[v.size()-1-sc]; ++sc);
				if(bestSc<sc) {
					bestSc = sc;
					best_size = v.size();
					best_node = i ? dst : current;
				}
				v.clear();
			}
			assert(best_node!=NULL);
			assert(0<=bestSc && bestSc<=dna.size());
			for(int i=best_size-bestSc; i; --i) {
				best_node = best_node->parent;
			}
			assert(best_node!=NULL);
			dna.resize(dna.size()-bestSc);
			if(dna.empty()) {
				dst->skip();
				dst->release();
				goto LABEL_D;
			}
			reserved.act = 0;
			assert(suggest_stack.empty());
			suggest_stack = std::move(dna);
			dna.clear();
			suggest_vec_id = l;
			suggest_hash = reserved.hash;
			suggest_eval_alone = current->evalAlone;
			suggest_eval_diff_store = reserved.evalDiffStore;
			++best_node->ref;
			dst->skip();
			dst->release();
			moveNode_(current, best_node);
			current->release();
			current = best_node;
			goto LABEL_C;
		}

		moveNode_(current, dst);
		current->release();
		if(current!=dst) {
			current = dst;
			make_child_flag = true;
			goto LABEL_E;
		}
	}
	current = current->createChildWithoutAddRef();
	assert(0<=current->act);
	dna_.emplace_back(current->act);
	return current->act;
}


void setTimeLimit(double timelimit) {
	g_timelimit = timelimit;
}

#line 55 "codevs_r/colun11.cpp"

};

constexpr int g_W = 10;
constexpr int g_H = 16;
constexpr int g_T = 2;
constexpr int g_S = 10;
constexpr int g_HT = g_H + g_T + 1;
constexpr int g_TT = g_T * g_T;
fast_vector<fast_array<fast_array<fast_vector<char, g_T>, g_T>, 4>, 512> g_packs;

fast_array<fast_vector<char, g_HT>, g_W> field;
fast_array<fast_array<fast_vector<char, g_HT>, g_W>, g_S> digit_positions;
int g_base_turn;
int g_last_chain_turn = 0;
int g_turn;
int g_end_turn;
int g_obst_turn;
int g_turn_count;

char g_permit[512][g_S+6];

#line 79 "codevs_r/colun11.cpp"

vector<int> obstList = { 0, 0, 1, 2, 3, 4, 6, 9, 13, 18, 25, 33, 45, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 104, 108, 112, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140 };

void init() {
	for(int x=0; x<g_W; ++x) {
		field[x].clear();
	}
	g_turn = 0;
	g_obst_turn = 0;
}
bool isOver() {
	for(int x=0; x<g_W; ++x) {
		if(g_H<field[x].size()) {
			return true;
		}
	}
	return false;
}
void putObst() {
	if(g_turn<g_obst_turn) {
		for(int x=0; x<g_W; ++x) {
			assert(!field[x].full());
			field[x].emplace_back(g_S+1);
		}
	}
}
void popObst() {
	if(g_turn<g_obst_turn) {
		for(int x=0; x<g_W; ++x) {
			assert(!field[x].empty());
			assert(field[x].back()==g_S+1);
			field[x].pop_back();
		}
	}
}

double below_bonus[g_HT] = { 0, 0, 1.0, 0.50, 0.30, 0.2, 0.16, 0.14, 0.12, 0.10, 0.08, 0.06, 0.04, 0.02 };
double side_bonus[g_HT]  = { 0, 0, 0.5, 0.25, 0.15, 0.1, 0.08, 0.07, 0.06, 0.05, 0.04, 0.03, 0.02, 0.01 };

array<array<zobrist<long long, g_W>, g_HT>, g_S> hash_seed;

pair<double, long long> checkPack(int x0, char rotate) {
	long long hashDiff = 0;
	fast_array<fast_vector<char, g_T>, g_T> & pack = g_packs[g_turn][rotate];
	assert(g_turn - g_base_turn<50);
	double ret = 0;
	bool obst = (g_turn<g_obst_turn ? 1 : 0);
	for(int x2=0; x2<g_T; ++x2) {
		int x = x0 + x2;
		assert(0<=x && x<g_W);
		int y = field[x].size() + obst;
		for(char b : pack[x2]) {
			assert(b);
			char b2 = g_S - b;
			hashDiff ^= hash_seed[b][y][x];
			if(1<=x) {
				for(char y2 : digit_positions[b2][x-1]) {
					int dy = abs(y-y2);
					ret += side_bonus[dy];
				}
			}
			for(char y2 : digit_positions[b2][x]) {
				int dy = abs(y-y2);
				ret += below_bonus[dy];
			}
			if(x+1<g_W) {
				for(char y2 : digit_positions[b2][x+1]) {
					int dy = abs(y-y2);
					ret += side_bonus[dy];
				}
			}
			++y;
		}
	}
	return pair<double, long long>(PARAM_KEIMA_EVAL*ret, hashDiff);
}
void putBlock(int x, char b) {
	digit_positions[b][x].emplace_back(field[x].size());
	field[x].emplace_back(b);
}
void putPack(int x0, char rotate) {
	fast_array<fast_vector<char, g_T>, g_T> & pack = g_packs[g_turn][rotate];
	assert(g_turn - g_base_turn<50);
	char his = g_turn - g_base_turn;
	if(15<his) {
		his = 15;
	}
	his <<= 4;
	++g_turn;
	for(int x2=0; x2<g_T; ++x2) {
		int x = x0 + x2;
		assert(0<=x && x<g_W);
		for(char b : pack[x2]) {
			assert(b);
			assert(!field[x].full());
			digit_positions[b][x].emplace_back(field[x].size());
			field[x].emplace_back(b|his);
		}
	}
}
void popPack(int x0, char rotate) {
	--g_turn;
	fast_array<fast_vector<char, g_T>, g_T> & pack = g_packs[g_turn][rotate];
	for(int x2=0; x2<g_T; ++x2) {
		int x = x0 + x2;
		assert(0<=x && x<g_W);
		assert(pack[x2].size()<=field[x].size());
		field[x].resize(field[x].size() - pack[x2].size());
		for(char b : pack[x2]) {
			assert(b);
			digit_positions[b][x].pop_back();
		}
	}
}
bool setObst(int obst) {
	int old = max(g_turn, g_obst_turn);
	g_obst_turn = g_turn + (obst / 10);
	return old!=g_obst_turn;
}
void clearHistory() {
	for(int c=0; c<g_S; ++c) {
		for(int x=0; x<g_W; ++x) {
			digit_positions[c][x].clear();
		}
	}
	for(int x=0; x<g_W; ++x) {
		for(int y=0; y<field[x].size(); ++y) {
			char c = field[x][y] & 15;
			field[x][y] = c;
			if(c<g_S) {
				assert(1<=c);
				digit_positions[c][x].emplace_back(y);
			}
		}
	}
}
fast_array<fast_vector<char, g_HT*2>, g_W> eraseBlocks;
fast_array<fast_vector<char, g_HT>, g_W> fieldBackup;
vector<char> lastChains;
inline void rollback() {
	for(int x=0; x<g_W; ++x) {
		field[x].assign(fieldBackup[x].begin(), fieldBackup[x].end());
	}
}
inline void backup() {
	for(int x=0; x<g_W; ++x) {
		fieldBackup[x].assign(field[x].begin(), field[x].end());
	}
}
fast_array<int, g_W> fillHeight;
fast_array<int, g_W> stableHeight;
inline int execErase() {
	int ret = 0;
	for(int x=0; x<g_W; ++x) {
		auto & vv = eraseBlocks[x];
		if(vv.empty()) {
			stableHeight[x] = fillHeight[x];
		}
		else {
			sort(vv.begin(), vv.end());
			auto it=vv.begin();
			int posBegin = *it;
			assert(posBegin<fillHeight[x]);
			stableHeight[x] = posBegin;
			char * nowRow = field[x].data();
			int posNew = posBegin;
			int posOld = posBegin + 1;
			for(++it; it!=vv.end(); ++it) {
				assert(*it<fillHeight[x]);
				int endPosOld = *it;
				if(posOld!=endPosOld+1) {
					while(posOld<endPosOld) {
						nowRow[posNew++] = nowRow[posOld++];
					}
					assert(posOld==endPosOld);
					posOld = endPosOld + 1;
				}
			}
			int & rCnt = fillHeight[x];
			int endPosOld = rCnt;
			while(posOld<endPosOld) {
				nowRow[posNew++] = nowRow[posOld++];
			}
			ret += rCnt - posNew;
			rCnt = posNew;
			vv.clear();
		}
	}
	return ret;
}
inline char checkErase() {
	char his = 16;
	for(int x=0; x<g_W; ++x) {
		for(int y=stableHeight[x], ey=fillHeight[x]; y<ey; ++y) {
			char c = g_S - (field[x][y]&15);
			char his1 = (field[x][y]>>4)&15;
			bool flag = false;
			if(1<=y && (field[x][y-1]&15)==c) {
				eraseBlocks[x].emplace_back(y-1);
				flag = true;
				his = min(his, max((char)((field[x][y-1]>>4)&15), his1));
			}
			if(1<=x && y-1<stableHeight[x-1]) {
				if(1<=y && (field[x-1][y-1]&15)==c) {
					eraseBlocks[x-1].emplace_back(y-1);
					flag = true;
					his = min(his, max((char)((field[x-1][y-1]>>4)&15), his1));
				}
				if(y<stableHeight[x-1] && (field[x-1][y]&15)==c) {
					eraseBlocks[x-1].emplace_back(y);
					flag = true;
					his = min(his, max((char)((field[x-1][y]>>4)&15), his1));
				}
				if(y+1<stableHeight[x-1] && (field[x-1][y+1]&15)==c) {
					eraseBlocks[x-1].emplace_back(y+1);
					flag = true;
					his = min(his, max((char)((field[x-1][y+1]>>4)&15), his1));
				}
			}
			if(x+1<g_W && y-1<fillHeight[x+1]) {
				if(1<=y && (field[x+1][y-1]&15)==c) {
					eraseBlocks[x+1].emplace_back(y-1);
					flag = true;
					his = min(his, max((char)((field[x+1][y-1]>>4)&15), his1));
				}
				if(y<fillHeight[x+1] && (field[x+1][y]&15)==c) {
					eraseBlocks[x+1].emplace_back(y);
					flag = true;
					his = min(his, max((char)((field[x+1][y]>>4)&15), his1));
				}
				if(y+1<fillHeight[x+1] && (field[x+1][y+1]&15)==c) {
					eraseBlocks[x+1].emplace_back(y+1);
					flag = true;
					his = min(his, max((char)((field[x+1][y+1]>>4)&15), his1));
				}
			}
			if(flag) {
				eraseBlocks[x].emplace_back(y);
			}
		}
	}
	return his;
}
int lastEraseCount;
inline int stablize(int x0, char rotate) {
	assert(1<=g_turn);
	fast_array<fast_vector<char, g_T>, g_T> & pack = g_packs[g_turn-1][rotate];
	for(int x=0; x<g_W; ++x) {
		stableHeight[x] = fillHeight[x] = field[x].size();
		assert(eraseBlocks[x].empty());
	}
	for(int x2=0; x2<g_T; ++x2) {
		int x = x0 + x2;
		assert(0<=x && x<g_W);
		assert(pack[x2].size()<=fillHeight[x]);
		stableHeight[x] -= pack[x2].size();
	}
	lastChains.clear();
	lastEraseCount = 0;
	while(true) {
		for(int x=0; x<g_W; ++x) {
			assert(eraseBlocks[x].empty());
		}
		char his = checkErase();
		if(16<=his) {
			break;
		}
		if(lastChains.empty()) {
			backup();
		}
		lastChains.emplace_back(his);
		lastEraseCount += execErase();
	}
	return lastChains.size();
}
inline bool isChain(int x0, char rotate) {
	assert(1<=g_turn);
	fast_array<fast_vector<char, g_T>, g_T> & pack = g_packs[g_turn-1][rotate];
	for(int x=0; x<g_W; ++x) {
		stableHeight[x] = fillHeight[x] = field[x].size();
		assert(eraseBlocks[x].empty());
	}
	for(int x2=0; x2<g_T; ++x2) {
		int x = x0 + x2;
		assert(0<=x && x<g_W);
		assert(pack[x2].size()<=fillHeight[x]);
		stableHeight[x] -= pack[x2].size();
	}
	char his = checkErase();
	if(his<16) {
		for(int x=0; x<g_W; ++x) {
			eraseBlocks[x].clear();
		}
		return true;
	}
	return false;
}
void commit() {
	for(int x=0; x<g_W; ++x) {
		field[x].resize(fillHeight[x]);
	}
}
bool tryEraseYetBackup;
double tryErase(int x, int y) {
	if(field[x].size()<=y+1) {
		return 0.0;
	}
	assert(eraseBlocks[x].empty());
	if(0<=x-1 && y-1<field[x-1].size()) {
		assert(eraseBlocks[x-1].empty());
		if(0<=y-1 && field[x-1][y-1]+field[x][y+1]==g_S) {
			eraseBlocks[x-1].emplace_back(y-1);
			eraseBlocks[x].emplace_back(y+1);
		}
		for(int y2=y+2; y2<field[x].size() && y2-2<field[x-1].size(); ++y2) {
			if(field[x-1][y2-2]+field[x][y2]==g_S) {
				eraseBlocks[x-1].emplace_back(y2-2);
				eraseBlocks[x].emplace_back(y2);
			}
		}
	}
	if(x+1<g_W && y-1<field[x+1].size()) {
		assert(eraseBlocks[x+1].empty());
		if(0<=y-1 && field[x+1][y-1]+field[x][y+1]==g_S) {
			eraseBlocks[x+1].emplace_back(y-1);
			eraseBlocks[x].emplace_back(y+1);
		}
		for(int y2=y+2; y2<field[x].size() && y2-2<field[x+1].size(); ++y2) {
			if(field[x+1][y2-2]+field[x][y2]==g_S) {
				eraseBlocks[x+1].emplace_back(y2-2);
				eraseBlocks[x].emplace_back(y2);
			}
		}
	}
	if(0<=y-1 && field[x][y-1]+field[x][y+1]==g_S) {
		eraseBlocks[x].emplace_back(y-1);
		eraseBlocks[x].emplace_back(y+1);
	}
	if(eraseBlocks[x].empty()) {
		return 0.0;
	}
	eraseBlocks[x].emplace_back(y);
	if(tryEraseYetBackup) {
		tryEraseYetBackup = false;
		backup();
	}
	int ret2 = execErase() - 3;
	int ret = 1;
	char his = 0;
	while(true) {
		his = checkErase();
		if(16<=his) {
			break;
		}
		++ret;
		ret2 += execErase() - 2;
	}
	rollback();
	for(int x=0; x<g_W; ++x) {
		stableHeight[x] = fillHeight[x] = field[x].size();
		assert(eraseBlocks[x].empty());
	}
	return ret - ret2 * 0.2;
}
int evalCount = 0;
int evalTryCount = 0;
double evaluate() {
	++evalCount;
	for(int x=0; x<g_W; ++x) {
		stableHeight[x] = fillHeight[x] = field[x].size();
		assert(eraseBlocks[x].empty());
	}
	tryEraseYetBackup = true;
	int blacket_count2 = 0;
	int blacket_count3 = 0;
	int kata_count2 = 0;
	int kata_count3 = 0;
	int kata_count4 = 0;
	int kata_count5 = 0;
	double ret = 0;
	for(int x=1; x+1<g_S; ++x) {
		int sz = field[x].size();
		for(int y=sz-2; 1<=y; --y) {
			int szL = field[x-1].size();
			int szR = field[x+1].size();
			char uc = field[x][y+1];
			bool flag = (y+2<sz);
			bool flagL = (y-1<szL && uc+field[x-1][y-1]==g_S);
			bool flagR = (y-1<szR && uc+field[x+1][y-1]==g_S);
			bool flagM = (uc+field[x][y-1]==g_S);
			bool flagL2 = (y-1<=szL && szL<=y+2);
			bool flagR2 = (y-1<=szR && szR<=y+2);
			bool flagL3 = (0<=y-2 && y<szL && field[x-1][y]+field[x][y-2]==g_S);
			bool flagR3 = (0<=y-2 && y<szR && field[x+1][y]+field[x][y-2]==g_S);
			bool flagL4 = (0<=y-3 && y-3<szL && field[x-1][y-3]+field[x][y-1]==g_S);
			bool flagR4 = (0<=y-3 && y-3<szR && field[x+1][y-3]+field[x][y-1]==g_S);
			bool flagL5 = (0<=y-2 && y+1<szL && field[x-1][y+1]+field[x-1][y-2]==g_S);
			bool flagR5 = (0<=y-2 && y+1<szR && field[x+1][y+1]+field[x+1][y-2]==g_S);
			bool flagL6 = (0<=y-3 && y+1<szL && field[x-1][y+1]+field[x][y-3]==g_S);
			bool flagR6 = (0<=y-3 && y+1<szR && field[x+1][y+1]+field[x][y-3]==g_S);
			bool flagL7 = (0<=y-3 && y-3<szL && y+2<sz && field[x-1][y-3]+field[x][y+2]==g_S);
			bool flagR7 = (0<=y-3 && y-3<szR && y+2<sz && field[x+1][y-3]+field[x][y+2]==g_S);
			bool flagL8 = (0<=y-3 && y-1<szL && field[x-1][y-1]+field[x][y-3]==g_S);
			bool flagR8 = (0<=y-3 && y-1<szR && field[x+1][y-1]+field[x][y-3]==g_S);
			bool flagL9 = (0<=y-3 && y-3<szL && field[x-1][y-3]+field[x][y]==g_S);
			bool flagR9 = (0<=y-3 && y-3<szR && field[x+1][y-3]+field[x][y]==g_S);
			bool flag10 = (0<=y-2 && y+1<sz && field[x][y-2]+field[x][y+1]==g_S);
			bool flagL11 = (0<=y-2 && y-2<szL && field[x-1][y-2]+field[x][y]==g_S);
			bool flagR11 = (0<=y-2 && y-2<szL && field[x-1][y-2]+field[x][y]==g_S);
			if(
				(flagL && (flag || y<szL))
				||
				(flagR && (flag || y<szR))
				||
				(flagM && flag)
				) {
				++evalTryCount;
				ret = max(ret, tryErase(x, y));
				break;
			}
			blacket_count2 += (flagL&&flagL3 ? 1 : 0) + (flagR&&flagR3 ? 1 : 0);
			kata_count2 += (flagL3&&flagR4 ? 1 : 0) + (flagR3&&flagL4 ? 1 : 0);
			kata_count2 += (flagL4&&flagR8 ? 1 : 0) + (flagR4&&flagL8 ? 1 : 0);
			blacket_count3 += (flagL&&flagL3&&(flagR4||flagR11) ? 1: 0) + (flagR&&flagR3&&(flagL4||flagL11) ? 1: 0);
			blacket_count3 += (flagL&&flagL3&&flagR5 ? 1: 0) + (flagR&&flagR3&&flagL5 ? 1: 0);
			kata_count3 += (flagL4&&flagR8&&flagR9 ? 1 : 0) + (flagR4&&flagL8&&flagL9 ? 1 : 0);
			kata_count4 += (flagL&&flagL3&&flagR4&&flagL6 ? 1: 0) + (flagR&&flagR3&&flagL4&&flagR6 ? 1: 0);
			kata_count4 += (flagL4&&flagR8&&flagR9&&flag10 ? 1 : 0) + (flagR4&&flagL8&&flagL9&&flag10 ? 1 : 0);
			kata_count5 += (flagL&&flagL3&&flagR4&&flagL6&&flagL7 ? 1: 0) + (flagR&&flagR3&&flagL4&&flagR6&&flagR7 ? 1: 0);
		}
	}
	return PARAM_CHAIN_EVAL * ret + blacket_count2 * PARAM_BLACKET_BONUS2 + blacket_count3 * PARAM_BLACKET_BONUS3 + kata_count2 * PARAM_KATA_BONUS2 + kata_count3 * PARAM_KATA_BONUS3 + kata_count4 * PARAM_KATA_BONUS4 + kata_count5 * PARAM_KATA_BONUS5;
}

void printState() {
	fprintf(stderr, "===============================\n");
	for(int y=g_HT-1; 0<=y; --y) {
		for(int x=0; x<g_W; ++x) {
			if(y<field[x].size()) {
				fprintf(stderr, " %02x", (int)field[x][y] & 255);
			}
			else {
				fprintf(stderr, "   ");
			}
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	fflush(stderr);
}

vector<char> bestAns;
double bestSc;

int g_count = 0;

void thinkF() {
	while(true) {
		int ope = search::oracle();
		if(ope<0) {
			if(ope==search::OPE_RETURN) {
				return;
			}
			if(ope==search::OPE_RESUME) {
				vector<int> dna = search::getDNA();
				dna.pop_back();
				assert(dna.size());
				if(dna.size()<=1 || lrand49(2)) {
					dna[lrand49(dna.size())] ^= lrand49(3)+1;
				}
				else {
					int len = max(1, min((int)dna.size()-1, __builtin_ffs(mrand49())));
					int s = lrand49(dna.size()-len);
					swap(dna[s], dna[s+len]);
					dna[s] ^= lrand49(4);
					dna[s+len] ^= lrand49(4);
				}
				while(dna.size()<g_turn_count) {
					dna.emplace_back(lrand49(36));
				}
				search::reserveDNA(dna, 0, search::getCurrent()->hash);
				search::suspendReserve();
			}
			if(ope==search::OPE_RESERVE) {
				search::getCurrent()->generation = g_turn_count + 2;
				search::suspendReserve();
			}
		}
		else {
		}
	}
}

void think() {
	while(true) {
		int ope = search::oracle();
		if(ope<0) {
			if(ope==search::OPE_RETURN) {
				return;
			}
			if(ope==search::OPE_RESERVE) {
				countMainIteration();
				auto current = search::getCurrent();
				const vector<int> & dna = search::getDNA();
				int lastAct = dna.empty() ? 0 : dna.back();
				assert(current!=NULL);
				++g_count;
				int chain = g_base_turn<g_turn ? stablize(lastAct >> 2, lastAct & 3) : 0;
				bool overFlag = isOver();
				if(chain) {
					rollback();
					current->generation -= 10000;
					search::reserve(65536, chain, 1234567891);
					if(!overFlag) {
						int turns = g_turn - g_base_turn;
						if(turns) {
							int chain_turn = g_turn-g_last_chain_turn;
							double sc = (double)obstList[chain] / chain_turn - (lastEraseCount-chain*2) * 0.01;
							current->setEval(sc*2-(lastEraseCount-chain*2)*0.2);
							if(bestSc<sc) {
								bestSc = sc;

#line 606 "codevs_r/colun11.cpp"

								bestAns.clear();
								for(int i : search::getDNA()) {
									bestAns.emplace_back(i);
								}
								dump(chain, chain_turn, lastEraseCount, g_count, search::generation_loop_count);

#line 616 "codevs_r/colun11.cpp"

								reverse(bestAns.begin(), bestAns.end());

							}
						}
					}
				}
				else if(g_turn<g_end_turn && !overFlag) {

					if(g_end_turn-1<=g_turn) {
						current->generation -= 10000;
					}
					else {
						current->setEval(evaluate());
					}

					if(false) {

						if(g_turn==0) {
							constexpr int x = (g_W-g_T)>>1;
							constexpr int base = x << 2;
							for(int j=0; j<4; ++j) {
								pair<double, long long> r = checkPack(x, j);
								search::reserve(base+j, r.first, r.second);
							}
						}
						else {
							for(int x=0; x<=g_W-g_T; ++x) {
								int base = x<<2;
								for(int j=0; j<4; ++j) {
									pair<double, long long> r = checkPack(x, j);
									search::reserve(base+j, r.first, r.second);
								}
							}
						}
					}
					else {

#line 666 "codevs_r/colun11.cpp"

						if(g_turn<g_end_turn-3) {
							for(int x=3; x<=g_W-g_T-1; ++x) {
								int base = x<<2;
								for(int j=0; j<4; ++j) {
									pair<double, long long> r = checkPack(x, j);
									search::reserve(base+j, r.first, r.second);
								}
							}
						}
						else {
							for(int x=0; x<=g_W-g_T; ++x) {
								int base = x<<2;
								for(int j=0; j<4; ++j) {
									pair<double, long long> r = checkPack(x, j);
									search::reserve(base+j, r.first, r.second);
								}
							}
						}

					}
				}
			}
			if(ope==search::OPE_CONFIRM) {
				int lastAct = search::getDNA().back();
				if(isOver() || isChain(lastAct >> 2, lastAct & 3)) {
					search::breakDNA();
				}
			}
		}
		else if(ope==65536) {
			thinkF();
		}
		else {
			int x0 = ope >> 2;
			int r = ope & 3;
			putObst();
			putPack(x0, r);
			think();
			popPack(x0, r);
			popObst();
		}
	}
}
vector<char> solve(int end_turn) {
	initTime();
	srand49();
	evalCount = 0;
	evalTryCount = 0;
	g_count = 0;
	bestSc = 0;
	bestAns.clear();
	for(int k=0; k<1; ++k) {
		dump(k);
		search::init();
		search::setTimeLimit(18);
		g_turn_count = end_turn - g_turn;
		g_end_turn = end_turn;
		g_base_turn = g_turn;
		clearHistory();
		for(int t=g_turn; t<g_end_turn; ++t) {
			for(int i=0; i<g_S+6; ++i) {
				g_permit[t][i] = 0;
			}
			for(int t2=t; t2<min(g_end_turn, t+4); ++t2) {
				for(int x=0; x<2; ++x) {
					assert(0<=t && t<g_end_turn);
					assert(0<=t2 && t2<g_end_turn);
					for(char c : g_packs[t2][0][x]) {
						assert(1<=c && c<g_S);
						g_permit[t][g_S-c] = 1+(t2-t);
					}
				}
			}
		}
		think();
	}
	if(bestAns.empty()) {
		bestAns.emplace_back(4<<2);
	}
	dump(g_count, evalTryCount, evalCount);
	reportTime();
	return bestAns;
}

#line 1 "codevs_r/suffix-main.cpp"
#ifdef MARATHON_INFO
#pragma MARATHON RUN time ./run $*
#pragma MARATHON DEBUG time ./debug $*
#endif

void rotate_pack(char * pack, fast_array<fast_array<fast_vector<char, g_T>, g_T>, 4> & out) {
	for(int x=0; x<g_T; ++x) {
		out[0][x].clear();
		for(int t=g_TT-g_T+x; 0<=t; t-=g_T) if(pack[t]) {
			out[0][x].emplace_back(pack[t]);
		}
		out[1][x].clear();
		for(int t=g_TT-1-x*g_T, et=t-g_T; et<t; --t) if(pack[t]) {
			out[1][x].emplace_back(pack[t]);
		}
		out[2][x].clear();
		for(int t=g_T-1-x; t<g_TT; t+=g_T) if(pack[t]) {
			out[2][x].emplace_back(pack[t]);
		}
		out[3][x].clear();
		for(int t=x*g_T,et=t+g_T; t<et; ++t) if(pack[t]) {
			out[3][x].emplace_back(pack[t]);
		}
	}
}
void first_pack(fast_array<fast_array<fast_vector<char, g_T>, g_T>, 4> & out) {
	for(int i=0; i<4; ++i) {
		vector<pair<int, int> > v;
		if(0<out[i][0].size() && 0<out[i][1].size() && out[i][0][0]+out[i][1][0]==g_S) {
			v.emplace_back(0, 0);
			v.emplace_back(1, 0);
		}
		if(1<out[i][0].size() && out[i][0][0]+out[i][0][1]==g_S) {
			v.emplace_back(0, 0);
			v.emplace_back(0, 1);
		}
		if(0<out[i][0].size() && 1<out[i][1].size() && out[i][0][0]+out[i][1][1]==g_S) {
			v.emplace_back(0, 0);
			v.emplace_back(1, 1);
		}
		if(1<out[i][0].size() && 0<out[i][1].size() && out[i][0][1]+out[i][1][0]==g_S) {
			v.emplace_back(0, 1);
			v.emplace_back(1, 0);
		}
		if(1<out[i][0].size() && 1<out[i][1].size() && out[i][0][1]+out[i][1][1]==g_S) {
			v.emplace_back(0, 1);
			v.emplace_back(1, 1);
		}
		if(1<out[i][1].size() && out[i][1][0]+out[i][1][1]==g_S) {
			v.emplace_back(1, 0);
			v.emplace_back(1, 1);
		}
		for(pair<int, int> u : v) {
			out[i][u.first][u.second] = 0;
		}
		for(int x=0; x<2; ++x) {
			for(int y=0; y<out[i][x].size(); ++y) {
				if(out[i][x][y]==0) {
					out[i][x][y] = out[i][x].back();
					out[i][x].pop_back();
					--y;
				}
			}
		}
	}

}

int randByDist(vector<int> & dist) {
	int n = dist.size();
	int sum = 0; for(int i=0; i<n; ++i) sum += dist[i];
	int r = lrand49(sum);
	int ret; for(ret=0; ret<n && 0<=r; ++ret) r -= dist[ret];
	--ret;
	assert(ret<n);
	assert(1<=dist[ret]);
	--dist[ret];
	return ret;
}

double test(int seed, int appear_turn, int obst_turn) {
	srand49(seed);
	vector<int> dist1 = { 102, 102, 102, 101, 93 };
	vector<int> dist2 = { 0, 177, 177, 177, 177, 177, 177, 177, 177, 177 };
	int max_turn = appear_turn + obst_turn;
	assert(0<=obst_turn && obst_turn<appear_turn);
	g_packs.clear();
	for(int i=0; i<max_turn; ++i) {
		char pack[4];
		int u = randByDist(dist1);
		for(int j=0; j<4; ++j) {
			pack[j] = (u==j) ? 0 : randByDist(dist2);
		}
		rotate_pack(pack, g_packs.let_back());
		if(i==0) {
			first_pack(g_packs.back());
		}
	}
	init();
	vector<char> ans = solve(g_turn + 12);
	while(true) {
		assert(!ans.empty());
		char c = ans.back();
		ans.pop_back();
		putObst();
		putPack(c>>2, c&3);
		int chain = stablize(c>>2, c&3);
		if(chain) {
			commit();
			assert(ans.empty());
			return (double)obstList[chain] / g_turn;
		}
		if(ans.empty()) {
			return 0;
		}
		--obst_turn;
		if(obst_turn==0) {
			setObst(20);
			ans = solve(g_turn + 8);
		}
	}
}

char buf[512];
int main() {

	printf("colun10\n");
	fflush(stdout);


	for(int i=0; i<500; ++i) {
		int pack_int[4];
		scanf("%d%d%d%d%s", &pack_int[0], &pack_int[1], &pack_int[2], &pack_int[3], buf);
		char pack[4];
		pack[0] = pack_int[0];
		pack[1] = pack_int[1];
		pack[2] = pack_int[2];
		pack[3] = pack_int[3];
		rotate_pack(pack, g_packs.let_back());
		if(i==0) {
			first_pack(g_packs.back());
		}
	}
	int next_turn = 12;
	g_last_chain_turn = 0;
	vector<char> reserve;
	for(int i=0; i<500; ++i) {
		int turn;
		scanf("%d", &turn);
		g_turn = turn;
		{
			int ms, obstCnt, skill, score;
			scanf("%d%d%d%d", &ms, &obstCnt, &skill, &score);
			if(setObst(obstCnt)) {
				reserve.clear();
				next_turn = 10;
			}
			dump(ms, obstCnt, skill, score);
			int data[10][16];
			for(int y=15; 0<=y; --y) {
				for(int x=0; x<10; ++x) {
					scanf("%d", &data[x][y]);
				}
			}
			scanf("%s", buf);
			if(reserve.empty()) {
				init();
				g_turn = turn;
				for(int x=0; x<10; ++x) {
					for(int y=0; y<16; ++y) {
						if(data[x][y]==0) {
							break;
						}
						putBlock(x, data[x][y]);
					}
				}
				reserve = solve(g_turn + next_turn);
				next_turn = 12;
			}
			printf("%d %d\n", reserve.back()>>2, reserve.back()&3);
			fflush(stdout);
			reserve.pop_back();
			if(reserve.empty()) {
				g_last_chain_turn = turn;
			}
		}
		{
			int msE, obstCntE, skillE, scoreE;
			scanf("%d%d%d%d", &msE, &obstCntE, &skillE, &scoreE);
			dump(msE, obstCntE, skillE, scoreE);
			int data[10][16];
			for(int y=15; 0<=y; --y) {
				for(int x=0; x<10; ++x) {
					scanf("%d", &data[x][y]);
				}
			}
			scanf("%s", buf);
		}
	}
	return 0;
}
