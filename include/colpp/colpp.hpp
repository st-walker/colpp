#pragma once
#ifndef COLPP_COLPP_HPP
#define COLPP_COLPP_HPP

#include <cstdint>
#include <iostream>

namespace col {
    
    class MyClass
    {
    public:
        MyClass(const uint64_t size)
        : m_size(size)
        {

        }
        
        void hello_world()
        {
            std::cout<<"Hello World!\n";
        }
    private:
        uint64_t m_size;
    };

} // end namespace col


#endif // COLPP_COLPP_HPP