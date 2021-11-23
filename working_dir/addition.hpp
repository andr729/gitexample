#ifndef ADD_H
#define ADD_H

template<class... T>
long sum(T... args) {
    return (args + ...);
}

int add(int a, int b);

#endif /* ADD_H */