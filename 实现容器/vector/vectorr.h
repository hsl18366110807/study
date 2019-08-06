#include <stdlib.h>
#include <malloc.h>
template<class T>
class vectorr
{
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef size_t      size_type;
	typedef ptrdiff_t   different_type;
protected:
	iterator start;
	iterator finish;
	iterator end_of_storage;
public:
	iterator begin() { return start; }
	iterator end() { return finish; }
	size_type size() { return size_type(end() - begin()); }
	size_type capacity() { return size_type(end_of_storage - begin()); }
	T& back() { return *(finish-1); }
	bool empty() { if (size() == 0)return true; else return false; }
	T& front() { return *start; }
	iterator insert(iterator position, const T& x) {
		if (finish != end_of_storage) {
			for (iterator iter = finish; iter != position; iter--) {
				*iter = *(iter - 1);
			}
			*position = x;
			finish++;
			return position;
		}
		else {
			size_type n = capacity();
			iterator iter = new T[2 * n * sizeof(T)];
			iterator s = iter;
			for (iterator it = start; it < finish; it++) {
				*iter++ = *it;
			}
			*iter = x;
			start = s;
			finish = iter + 1;
			end_of_storage = start + 2 * n;
			return insert(position, x);
		}
	}
	vectorr() :start(NULL), finish(NULL), end_of_storage(NULL) {};
	vectorr(int n, T x) {
		T* iter = reinterpret_cast<T*>( malloc(sizeof(T) * n));
		start = iter;
		for (int i = 0; i < n; i++) {
			*iter++ = x;
		}	
		finish = iter;
		end_of_storage = iter;
	}
	~vectorr()
	{
		iterator one = start;
		for (; start < finish; start++) {
			_Destroy(start);//析构掉该位置上的元素	
		}
		free(one);//只需要释放首地址即可
	}
	void push_back(T x) {
		if (finish != end_of_storage) *finish++ = x;
		else {
			size_type n = capacity();
			iterator iter = new T[2*n*sizeof(T)];
			iterator s = iter;
			for (iterator it = start; it < finish; it++) {
				*iter++ = *it;
			}
			*iter = x;
			start = s;
			finish = iter+1;
			end_of_storage = start + 2 * n;
		}
	}
	iterator erase(iterator pos) {
		if (pos == finish - 1) {
			_Destroy(pos);
			--finish;
			return pos - 1;
		}
		for (iterator it = pos; it < finish-1; it++) {
			*it = *(it + 1);
		}
		--finish;
		_Destroy(finish);
		return pos;
	}
	void clear() {
		for (iterator it = finish-1; it >=start; it--) {
			_Destroy(it);
		}
		finish = start;
   }
	reference operator[](size_type n) { return *(begin() + n); }
};

