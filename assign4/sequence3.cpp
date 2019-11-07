// Provided by:   _________Xing Yang_____________
// Email Address: ___xyang004@citymail.cuny.edu_________________
#include <cassert>
#include "sequence3.h"
using namespace std;

namespace main_savitch_5
{
    sequence::sequence()
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        length = 0;
    }
    sequence::sequence(const sequence& source)
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr); // copy from the source and paste to the head pointer
        length = source.size(); 
        if (source.cursor == NULL) //check if there is null in both cursor and precursors
        {
            cursor = NULL; 
            if(source.precursor == NULL)
            {
                precursor = NULL;
            } 
            else
            {
                precursor = tail_ptr;
            }
        }
        else
        {
            cursor = head_ptr; //set cursor to head pointer
            precursor = NULL; //because cursor is head pointer, nothing can be in front of the head pointer
            node* loop = source.head_ptr;
            while(loop != NULL && loop != source.cursor) //until detects the current item of source, the cursor will keep looping
            {
                loop = loop ->link();
                precursor = cursor; //precursor and cursor also need to move as the loop continues
                cursor = cursor ->link();
            }
        }
    }
    sequence::~sequence()
    {
        list_clear(head_ptr);
    }
    void sequence::start()
    {
        cursor = head_ptr;
        precursor = NULL;
    }
    void sequence::advance()
    {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }
    void sequence::insert(const value_type& entry)
    {
        if(!is_item()) //if there isn't a cursor
        {
                head_ptr = new node(entry, head_ptr); //insert head pointer
                precursor = NULL;
                cursor = head_ptr;
        }
        else
        {
            if(cursor == head_ptr) //if cursor is located on the head
            {
                head_ptr = new node(entry, head_ptr);
                cursor = head_ptr;
                precursor = NULL;
            }
            else //if cursor locates somewhere on the linked list
            {
                list_insert(precursor, entry);
                cursor = precursor->link();
            }
        }
        length++;
    }
    void sequence::attach(const value_type& entry)
    {
        if(is_item()) //when there is a cursor
        {
            list_insert(cursor,entry);
            advance();
        }
        else //when there isn't a cursor
        {
            if(precursor == NULL) //when precursor is NULL
            {
                list_head_insert(head_ptr,entry);
                cursor = head_ptr;
                precursor = NULL;
                if(tail_ptr == NULL) //check if the original linked list is empty
                {
                    tail_ptr = head_ptr;
                } 
            }
            else
            {
                cursor = list_locate(head_ptr, list_length(head_ptr)); //go to the last node of the linked list
                list_insert(cursor, entry);
                cursor = precursor->link();
            }
        }
        length++;
    }
    void sequence::remove_current()
    {
        assert(is_item());
        if(cursor == head_ptr) //remove the head pointer
        {
            list_head_remove(head_ptr);
            cursor = head_ptr;
            precursor = NULL;
            if(cursor == NULL) //check if there is only one node on the linked list
            { 
                tail_ptr = NULL;
            }
        }
        else //general case for remove a cursor 
        {
            cursor = cursor -> link();
            list_remove(precursor);
            if (cursor == NULL)
            {
                tail_ptr = NULL;
            }
        }
        length--;
    }
    void sequence::operator=(const sequence& source)
    {
        if(this == &source) //self check
            return;
        list_clear(head_ptr); //clear the linked list
        list_copy(source.head_ptr, head_ptr, tail_ptr); // copy everything from source and pasted to the head pointer
        length = source.size(); 
        if (source.cursor == NULL) //check if there is null in both cursor and precursors
        {
            cursor = NULL; 
            if(source.precursor == NULL)
            {
                precursor = NULL;
            } 
            else
            {
                precursor = tail_ptr;
            }
        }
        else
        {
            cursor = head_ptr; //set cursor to head pointer
            precursor = NULL; //because cursor is head pointer, nothing can be in front of the head pointer
            node* loop = source.head_ptr;
            while(loop != NULL && loop != source.cursor) //until detects the current item of source, the cursor will keep looping
            {
                loop = loop ->link();
                precursor = cursor; //precursor and cursor also need to move as the loop continues
                cursor = cursor ->link();
            }
        }
    }

    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return cursor -> data(); //return the data inside the node cursor
    }
}