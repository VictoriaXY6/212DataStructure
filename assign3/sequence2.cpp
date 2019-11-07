// Provided by:   _________Xing Yang_____________
// Email Address: ___xyang004@citymail.cuny.edu_________________
#include <algorithm>
#include "sequence2.h"
#include <cassert>

using namespace std;
namespace main_savitch_4
{
    sequence::sequence(sequence::size_type initial_capacity) 
    {
        p = new value_type[initial_capacity];
        capacity = initial_capacity;
        sequence_current = 0;
        used = 0;
    }
    sequence::sequence(const sequence &source) 
    {
        p = new value_type[source.capacity];
        capacity = source.capacity;
        sequence_current = source.sequence_current;
        used = source.used;
        copy(source.p, source.p + source.used, p);
    }
    sequence::~sequence() 
    {
        delete[] p;
    }
    void sequence::start()
    {
        sequence_current = 0;
    }
    void sequence::advance()
    {
        assert(is_item());
        sequence_current++;
    }
    void sequence::insert(const value_type &entry)
    {
        if (capacity <= used) 
            resize(size() * 1.1);

        if(!is_item()) 
        {
            sequence_current = 0;
            if(used == 0) 
            {
                p[sequence_current] = entry;
            }
            else  
            {
                for(int i = used; i > sequence_current; i--)
                    p[i] = p[i-1];
                p[sequence_current] = entry;
            }
        }
        else
        {
            for(int i = used; i > sequence_current; i--)
            {
                p[i] = p[i-1];
            }
            p[sequence_current] = entry;
        }
        used++;
    }
    void sequence::attach(const value_type &entry)
    {
        if (capacity <= size())
            resize(size()+1);

        if (!is_item())
        {
            p[sequence_current] = entry;
        }
        else
        {
            sequence_current++;
            for (size_type i = used; i > sequence_current; i--)
            {
                p[i] = p[i-1];
            }
            p[sequence_current] = entry;
        }
        used++;
    }
    void sequence::remove_current()
    {
        assert(is_item());
        for(size_type i = sequence_current; i < size(); i++)
            p[i] = p[i+1];
        used--;
    }
    void sequence::resize(size_type new_capacity)
    {
        if(new_capacity > used)
        {
            value_type* temp;
            capacity = new_capacity;
            temp = new value_type[capacity];
            copy(p,p+used,temp);
            delete[] p;
            p = temp;
        }
    }
    void sequence::operator=(const sequence &source)
    {
        if(this == &source) //self check
            return;
        delete[] p;
        capacity = source.capacity;
        p = new value_type[source.capacity];
        sequence_current = source.sequence_current;
        used = source.used;
        copy(source.p, source.p + used, p);
    }
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return p[sequence_current];
    }
    sequence::value_type sequence::operator[](size_type idx) const
    {
        assert(idx < used);
        return p[idx];
    }
    void sequence::operator+=(const sequence& s)
    {
        if(capacity < s.used + used)
            resize(capacity + s.used);
        for(size_t i = used; i < used + s.used; i++)
            p[i] == s.p[i];
        used = used + s.used;
    }
    sequence operator+(const sequence &s1, const sequence &s2)
    {
        sequence result = s1;
        result += s2;
        return result;
    }
}
