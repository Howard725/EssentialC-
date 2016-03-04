//
// Created by Administrator on 2016/3/4.
//

#ifndef CHAPTER6_EXAMPLE_H
#define CHAPTER6_EXAMPLE_H


template <typename T>
class example {

public:
    example( const T& min, const T& max );
    example( const T *array, int size );
    T& operator[]( int index );
    bool operator==( const T& ) const;
    bool insert( const T*, int );
    bool insert( const T& );
    T min() const { return _min; }
    T max() const { return _max; }
    void min( const T& );
    void max ( const T& );
    int count( const T& value ) const;

private:
    int size;
    T *parray;
    T _min;
    T _max;

};


#endif //CHAPTER6_EXAMPLE_H
