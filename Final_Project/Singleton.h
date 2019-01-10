/*
 * Singleton.h
 *
 *  Created on: 28 de set de 2016
 *      Author: arliones.hoeller
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

template<typename T>
class Singleton {
public:
    Singleton() { _singleton = static_cast<T*>(this); }
    ~Singleton() { _singleton = 0; }

    static T * self() { return _singleton; }

private:
    static T * _singleton;
};

template<typename T>
T * Singleton<T>::_singleton;

#endif /* SINGLETON_H_ */
