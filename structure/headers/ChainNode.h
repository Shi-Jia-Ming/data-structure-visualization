//
// Created by sjiam on 2024/3/21.
//

#ifndef DATA_STRUCTURE_VISUALIZATION_CHAINNODE_H
#define DATA_STRUCTURE_VISUALIZATION_CHAINNODE_H

template<typename T>
class ChainNode {
public:
    explicit ChainNode(T value, ChainNode<T> *next)
            :value(value), next(next) {}

    T value;
    ChainNode<T> *next;

private:

};

#endif //DATA_STRUCTURE_VISUALIZATION_CHAINNODE_H
