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

private:
    T value;
    ChainNode<T> *next;
};

#endif //DATA_STRUCTURE_VISUALIZATION_CHAINNODE_H
