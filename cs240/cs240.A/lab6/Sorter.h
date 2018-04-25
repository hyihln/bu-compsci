
#ifndef SORTER_H
#define SORTER_H

template <class T>
class Sorter{
	public:
		Sorter();
		void clear();
		unsigned int size();
		void insert(int i);
		void shuffle();
		typename T::iterator operator[] (int i);
	private:
		std::T<int> t;
		typename T::iterator iter = t.begin();
};

template <class T>
Sorter<T>::Sorter(){
	
}

template <class T>
void Sorter<T>::clear(){
	while(iter != t.end()){
		iter = t.erase(iter);
	}
}

template <class T>
unsigned int Sorter<T>::size(){
	t.size();
}

template <class T>
void Sorter<T>::insert(int i){
	t.insert(iter+1, i);
}

template <class T>
void Sorter<T>::shuffle(){
	std::random_shuffle(t.begin(), t.end());
}

#endif
