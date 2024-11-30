#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#include "objPos.h"

#define ARRAY_MAX_CAP 200



class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;
        int arrayCapacity;


    public:
        objPosArrayList(); //constructor
        ~objPosArrayList(); //destructor
        objPosArrayList(const objPosArrayList &sList); //copy constructor
        objPosArrayList& operator=(const objPosArrayList &sList); //copy assignment constructor


        int getSize() const;

        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        objPos getHeadElement() const;
        objPos getTailElement() const;
        objPos getElement(int index) const;
    
};

#endif