//
// Created by danter on 1/16/18.
//

#ifndef C_EXPERIMENTS_ARRAYWRAPPER_H
#define C_EXPERIMENTS_ARRAYWRAPPER_H

#include <string>
#include <ostream>

namespace wrapper {
    class MetaData
    {
    public:
        MetaData (int size, const std::string& name)
                : _name( name )
                , _size( size )
        {}

        // copy constructor
        MetaData (const MetaData& other)
                : _name( other._name )
                , _size( other._size )
        {}

        // move constructor
        MetaData (MetaData&& other)
                : _name( std::move(other._name) )
                , _size( other._size )
        {}

        MetaData& operator=(MetaData other) {
            std::swap( _name, other._name);
            std::swap( _size, other._size);
        }

        friend std::ostream &operator<<(std::ostream &os, const MetaData &data) {
            os << "{_name: " << data._name << " ,_size: " << data._size << "}";
            return os;
        }

        std::string getName () const { return _name; }
        int getSize () const { return _size; }
    private:
        std::string _name;
        int _size;
    };

    class ArrayWrapper {
    public:
        ArrayWrapper (int n)
                : _p_vals( new int[ n ] )
                , _metadata( n, "ArrayWrapper" )
        {}

        ArrayWrapper (int n, const std::string& meta)
                : _metadata( n , meta)
        {}
        // copy constructor
        ArrayWrapper (const ArrayWrapper& other)
                : _p_vals( new int[ other._metadata.getSize()  ] )
                , _metadata( other._metadata )
        {
            for ( int i = 0; i < _metadata.getSize(); ++i )
            {
                _p_vals[ i ] = other._p_vals[ i ];
            }
        }

        // move constructor
        ArrayWrapper (ArrayWrapper&& other)
                : _p_vals( other._p_vals  )
                , _metadata( std::move(other._metadata) )
        {
            other._p_vals = nullptr;
        }

        ArrayWrapper& operator=(ArrayWrapper& other) {
            std::swap(_p_vals, other._p_vals);
            std::swap( _metadata, other._metadata);
        }

        friend std::ostream &operator<<(std::ostream &os, const ArrayWrapper &arrayWrapper) {
            os << "_{p_vals: " << arrayWrapper._p_vals << ", _metadata: " << arrayWrapper._metadata << "}";
            return os;
        }

        ~ArrayWrapper ()
        {
            delete [] _p_vals;
        }
    private:
        int *_p_vals;
        MetaData _metadata;
    };



}


#endif //C_EXPERIMENTS_ARRAYWRAPPER_H
