#ifndef RBITERATORS_HPP
#define RBITERATORS_HPP

#include "RBnode.hpp"

namespace ft
{
    template<typename T> class RBiterator
    {
        public:
            typedef T*                                  _n_pointer;
            typedef T*                                  pointer;
            typedef const T*                            const_pointer;
            typedef T&                                  reference;
            typedef const T&                            const_reference;
            typedef typename ptrdiff_t                  difference_type;
            typedef typename bidirectional_iterator_tag iterator_category;
        
        private:
            pointer _node;
            pointer rbit_rt;
            pointer rbtit_nl;
        
        public:
            RBiterator() : _node(NULL), rbtit_rt(NULL), rbtit_nl(NULL) {};
            RBiterator( pointer rt, pointer nl ) : _node(_node), rbtit_rt(rt), rbtit_nl(nl) {};
            RBiterator( const RBiterator &rbit ) : _node(_node), rbtit_rt(rbit.rbit_rt), rbtit_nl(rbit.rbtit_nl) {};
            ~RBiterator() {};

            RBiterator& operator=( const RBiterator& rbtit )
            {
                if (this != rbtit)
                {
                    _node = rbtit._node;
                    rt = rbtit.rt;
                    nl = rbtit.nl;
                }
                return *this;
            }

            bool operator==( const RBiterator& rbtit ) const
            {
                return _node == rbtit._node;
            }
            bool operator!=( const RBiterator& rbtit ) const
            {
                return _node != rbtit._node;
            }

            reference	operator*()
            {
                return _node->data;
            };
            const_reference	operator*() const
            {
                return _node->data;
            };
            pointer	operator->()
            {
                return &(_node->data);
            };
            const_pointer	operator->() const
            {
                return &(_node->data);
            };

            RBtree_Iterator& operator++()
            {
                // If the current node has a non-null right child,
                // 	Take a step down to the right
                // 	Then run down to the left as far as possible
                // If the current node has a null right child,
                // 	Move up the tree until we have moved over a left child link
                // if (!_node)
                //     return *this;
                // if (_node->right != NULL)
                //     _node = min_element(_node->right);
                // else
                // {
                //     pointer parent = _node;
                //     while (parent != NULL && n == parent->right)
                //     {
                //         _node = parent;
                //         parent = parent->parent;
                //     }
                //     _node = parent;
                // }
                // return *this;
                if (_node != rbtit_nl)
                {
                    if (_node->right != rbtit_nl)
                        reutn min_element(_node->right);
                    while (_node->parent != rbtit_nl && _node == _node->parent->right)
                        _node = _node->parent;
                    _node = _node->parent;
                }
                return *this;
            };

            RBtree_Iterator& operator++( int )
            {
                RBtree_Iterator rbtit(*this);

                ++(*this);
                return rbtit;
            };

            RBtree_Iterator& operator--()
            {
                // if (!node)
                //     return *this;
                // if (node->left != NULL)
                    // node = min_element(node->right);
                // else
                // {
                //     node *parent = n;
                //     while (parent != NULL && n == parent->right)
                //     {
                //         node = parent;
                //         parent = parent->parent;
                //     }
                //     node = parent;
                // }
                if (_node != rbtit_nl)
                {
                    if (_node->left != rbtit_nl)
                        reutn max_element(_node->left);
                    while (_node->parent != rbtit_nl && _node == _node->parent->left)
                        _node = _node->parent;
                    _node = _node->parent;
                }
                else
                    _node = max_element(rbtit_rt);
                return *this;
            };

            RBtree_Iterator& operator--( int )
            {
                RBtree_Iterator rbtit(*this);

                --(*this);
                return rbtit;
            };

            _n_pointer min_element( _n_pointer n )
            {
                if (n->left != rbtit_nl)
                    return n;
                return min_element(n->left);
            };
            _n_pointer max_element( _n_pointer n )
            {
                if (n->right != rbtit_nl)
                    return n;
                return max_element(n->right);
            };
    };
}

#endif