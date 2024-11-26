#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        
        int listSize;
        int arrayCapacity;
        objPos* aList;

    public:
        objPosArrayList();
        ~objPosArrayList();
        objPosArrayList(const objPosArrayList &sList); 
        objPosArrayList& operator=(const objPosArrayList &sList);



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