// Provided by:   _________Xing Yang_____________
// Email Address: ___xyang004@citymail.cuny.edu_________________
#include <cassert>
#include "sequence1.h"
#include <cstdlib>
#include <iostream>
using namespace std;

namespace main_savitch_3
{
    sequence::sequence()
    {
        used = 0;
        sequence_current = 0;
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
    void sequence::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        if(!is_item()) //insert at the front
        {
            sequence_current = 0;
            if(used == 0) //when there is not current 
            {
                data[sequence_current] = entry;
            }
            else  //there is current
            {
                for(int i = used; i > sequence_current; i--)
                    data[i] = data[i-1];
                data[sequence_current] = entry;
            }
        }
        else
        {
            for(int i = used; i > sequence_current; i--)
            {
                data[i] = data[i-1];
            }
            data[sequence_current] = entry;
        }
        used++;
    }
    void sequence::attach(const value_type& entry)
    {
        assert (size() < CAPACITY);
        if (!is_item())
        {
            data[sequence_current] = entry;
        }
        else
        {
            sequence_current++;
            for (size_type i = used; i > sequence_current; i--)
            {
                data[i] = data[i-1];
            }
            data[sequence_current] = entry;
        }
        used++;
    }
    void sequence::remove_current()
    {
        assert(is_item());
        for(size_type i = sequence_current; i < used; i++)
            data[i] = data[i+1];
        used--;
    }
    sequence::value_type sequence::current( ) const
    {
        assert(is_item());
        return data[sequence_current];
    }
}

